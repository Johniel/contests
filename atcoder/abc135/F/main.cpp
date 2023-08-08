// github.com/Johniel/contests
// atcoder/abc135/F/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
// #define endl "\n"

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; for (auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, set<T> s) { os << "#{"; for (auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "{"; for (auto& i: m) os << i << ","; os << "}"; return os; }
template<typename E, size_t N> istream& operator >> (istream& is, array<E, N>& a) { for (auto& i: a) is >> i; return is; }
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[" << N << "]{"; for (auto& i: a) os << i << ","; os << "}"; return os; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

__attribute__((constructor)) static void ___initio(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;
// constexpr lli mod = 998244353;

// s自身とすべてのsuffixとの共通接頭辞の文字数を返す。
// つまり、{|LCP(s[0], s.substring(0))|, |LCP(s[0], s.substring(1))|, |LCP(s[0], s.substring(2))|, ... }
// verified at ABC257G
vector<int> z_algorithm(const string& s)
{
  vector<int> v(s.size());
  v[0] = s.size();
  int i = 1, j = 0;
  while(i < s.size()){
    while(i + j < s.size() && s[j] == s[i + j]) j++;
    v[i] = j;

    if(j == 0){
      i++;
      continue;
    }
    int k = 1;
    while(k < j && k + v[k] < j){
      v[i + k] = v[k];
      k++;
    }
    i += k;
    j -= k;
  }
  return v;
}

const int N = 5 * 1e5 + 3;
// const int N = 1000;
vec<int> g[N];

int main(int argc, char *argv[])
{
  str s, t;
  while (cin >> s >> t) {
    const int n = s.size();
    while (s.size() < t.size()) {
      s += s;
    }
    str u = t + "|" + s + s;
    vec<int> v = z_algorithm(u);
    fill(g, g + N, vec<int>());
    v.erase(v.begin(), v.begin() + t.size() + 1);
    // assert(v.size() == s.size());

    // cout << u << endl; cout << v << endl;

    for (int i = 0; i < n; ++i) {
      if (t.size() <= v[i]) {
        int j = (i + t.size()) % n;
        g[i].push_back(j);
      }
    }

    // for (int i = 0; i < v.size(); ++i) cout << i << ": " << g[i] << endl;

    {
      map<int, int> vis;
      function<bool(int, int)> find_circle = [&] (int curr, int color) {
        if (vis.count(curr)) {
          if (vis[curr] == color) return true;
          return false;
        }
        vis[curr] = color;
        each (next, g[curr]) if (find_circle(next, color)) return true;
        return false;
      };

      bool f = false;
      for (int i = 0; i < n; ++i) {
        if (!vis.count(i) && g[i].size()) f = f || find_circle(i, i);
      }
      if (f) {
        cout << -1 << endl;
        continue;
      }
    }

    {
      map<int, int> deg;
      int mx = 0;
      for (int i = 0; i < N; ++i) {
        each (j, g[i]) setmax(mx, ++deg[i]);
      }
      if (2 <= mx) {
        cout << -1 << endl;
        continue;
      }
    }

    map<int, int> memo;
    function<int(int)> rec = [&] (int curr) {
      if (memo.count(curr)) return memo[curr];
      int mx = 0;
      each (next, g[curr]) setmax(mx, rec(next) + 1);
      return memo[curr] = mx;
    };
    int mx = 0;
    for (int i = 0; i < n; ++i) {
      if (g[i].size()) setmax(mx, rec(i));
    }
    cout << mx << endl;
  }
  return 0;
}
