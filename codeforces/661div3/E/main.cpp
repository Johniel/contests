// codeforces/661div3/E/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; for (auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, set<T> s) { os << "#{"; for (auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "{"; for (auto& i: m) os << i << ","; os << "}"; return os; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

using lli = long long int;
using ull = unsigned long long;
using point = complex<double>;
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;

const int N = 2 * 1e5 + 3;
vec<vec<int>> g[N];
map<pair<int, int>, int> m;
int rec(int curr, int prev)
{
  int cnt = (g[curr].size() == 1);
  each (e, g[curr]) {
    int next = e[0];
    if (next == prev) continue;
    auto tmp = rec(next, curr);
    m[{curr, next}] = tmp;
    cnt += tmp;
  }
  return cnt;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int _;
  cin >> _;

  lli n, s;
  while (cin >> n >> s) {
    m.clear();
    fill(g, g + n, vec<vec<int>>());
    for (int i = 0; i < n - 1; ++i) {
      int a, b, c, d;
      cin >> a >> b >> c >> d;
      --a;
      --b;
      --d;
      g[a].push_back({b, c, d});
      g[b].push_back({a, c, d});
    }
    rec(0, -1);

    vec<lli>  z[2];
    for (int k = 0; k < 2; ++k) {
      priority_queue<vec<lli>> q;

      lli x = 0;
      for (int i = 0; i < n; ++i) {
        each (j, g[i]) {
          unless (j[2] == k) continue;
          const pair<int, int> e = {i, j[0]};
          if (m[e]) {
            lli w = j[1];
            int cnt = m[e];
            vec<lli> v;
            v.push_back(w * cnt - (w / 2) * cnt);
            v.push_back(w / 2);
            v.push_back(cnt);
            q.push(v);
            x += cnt * w;
          }
        }
      }
      z[k].push_back(x);
      while (0 < x) {
        vec<lli> v = q.top();
        q.pop();
        int cnt = v.back();
        v.pop_back();
        lli w = v.back();
        v.pop_back();
        x -= v.back();
        z[k].push_back(x);
        vec<lli> u;
        u.push_back(w * cnt - (w / 2) * cnt);
        u.push_back(w / 2);
        u.push_back(cnt);
        q.push(u);
      }
    }

    // cout << z[0] << endl;
    // cout << z[1] << endl;

    int mn = 1 << 29;
    for (int i = 0, j = z[1].size() - 1; i < z[0].size(); ++i) {
      while (0 < j && z[0][i] + z[1][j - 1] <= s) --j;
      if (z[0][i] + z[1][j] <= s) {
        setmin(mn, i + j * 2);
      }
    }
    cout << mn << endl;
    // cout << endl;
  }

  return 0;
}
