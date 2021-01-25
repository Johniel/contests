// atcoder/arc111/D/main.cpp
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

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n, m;
  while (cin >> n >> m) {
    vec<int> g[n];
    map<pair<int, int>, pair<int, str>> dm;
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[a].push_back(b);
      g[b].push_back(a);
      dm[make_pair(a, b)] = make_pair(i, "->");
      dm[make_pair(b, a)] = make_pair(i, "<-");
    }
    vec<int> c(n);
    cin >> c;
    set<int> vis;
    int ord[n];
    set<pair<int, int>> used;
    function<void(int)> rec = [&] (int curr) {
      ord[curr] = vis.size();
      vis.insert(curr);
      each (next, g[curr]) {
        if (vis.count(next)) continue;
        if (c[curr] > c[next]) {
          used.insert({curr, next});
        }
        if (c[curr] == c[next]) {
          used.insert({curr, next});
          rec(next);
        }
      }
      return ;
    };

    vec<pair<int, int>> src;
    for (int i = 0; i < n; ++i) {
      src.push_back(make_pair(c[i], i));
    }
    sort(src.begin(), src.end());
    reverse(src.begin(), src.end());
    // cout << src << endl;
    each (i, src) {
      unless (vis.count(i.second)) rec(i.second);
    }

    // cout << dm << endl;
    // cout << used << endl;
    str dir[m];
    fill(dir, dir + m, str(""));
    each (e, used) {
      dir[dm[e].first] = dm[e].second;
    }
    each (i, dm) {
      if (dir[i.second.first] == "") {
        int a = i.first.first;
        int b = i.first.second;
        if (ord[a] >= ord[b]) dir[i.second.first] = i.second.second;
      }
    }
    for (int i = 0; i < m; ++i) {
      cout << dir[i] << endl;
    }
  }

  return 0;
}
