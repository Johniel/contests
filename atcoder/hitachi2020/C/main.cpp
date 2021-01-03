// atcoder/hitachi2020/C/main.cpp
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

const int N = 2 * 1e5 + 5;
vec<int> g[N];
vec<int> v[2];
void rec(int curr, int prev, int depth)
{
  v[depth % 2].push_back(curr);
  each (next, g[curr]) {
    if (next == prev) continue;
    rec(next, curr, depth + 1);
  }
  return ;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n;
  while (cin >> n) {
    fill(g, g + n, vec<int>());
    v[0].clear();
    v[1].clear();
    for (int i = 0; i < n - 1; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    rec(0, -1, 0);
    vec<int> u(n, -1);

    if (0) {
    } else if (v[0].size() <= n / 3) {
      for (int i = 3; i <= n; i += 3) {
        if (v[0].size()) {
          u[v[0].back()] = i;
          v[0].pop_back();
        } else {
          u[v[1].back()] = i;
          v[1].pop_back();
        }
      }
      for (int i = 1; i <= n && v[1].size(); i += 3) {
        u[v[1].back()] = i;
        v[1].pop_back();
      }
      for (int i = 2; i <= n && v[1].size(); i += 3) {
        u[v[1].back()] = i;
        v[1].pop_back();
      }
    } else if (v[1].size() <= n / 3) {
      for (int i = 3; i <= n; i += 3) {
        if (v[1].size()) {
          u[v[1].back()] = i;
          v[1].pop_back();
        } else {
          u[v[0].back()] = i;
          v[0].pop_back();
        }
      }
      for (int i = 1; i <= n && v[0].size(); i += 3) {
        u[v[0].back()] = i;
        v[0].pop_back();
      }
      for (int i = 2; i <= n && v[0].size(); i += 3) {
        u[v[0].back()] = i;
        v[0].pop_back();
      }
    } else {
      for (int i = 1; i <= n && v[0].size(); i += 3) {
        u[v[0].back()] = i;
        v[0].pop_back();
      }
      for (int i = 2; i <= n && v[1].size(); i += 3) {
        u[v[1].back()] = i;
        v[1].pop_back();
      }
      for (int i = 3; i <= n; i += 3) {
        if (0) {
        } else if (v[0].size()) {
          u[v[0].back()] = i;
          v[0].pop_back();
        } else if (v[1].size()) {
          u[v[1].back()] = i;
          v[1].pop_back();
        }
      }
    }
    each (i, u) cout << i << ' '; cout << endl;
  }

  return 0;
}
