// atcoder/abc260/F/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

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
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[]{"; for (auto& i: a) os << i << ","; os << "}"; return os; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;
// constexpr lli mod = 998244353;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int s, t, m;
  while (cin >> s >> t >> m) {
    const int T = 3000 + 2;
    const int N = 3 * 1e5 + T;
    static vec<int> g[N];
    fill(g, g + N, vec<int>());
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    for (int i = 0; i < s+t; ++i) {
      sort(g[i].begin(), g[i].end());
    }

    vec<int> v;
    static int z[T][T];
    fill(&z[0][0], &z[T - 1][T - 1] + 1, -1);
    for (int i = 0; i < s; ++i) {
      const int size = g[i].size();
      for (int j = 0; j < size; ++j) {
        for (int k = j+1; k < size; ++k) {
          int a = g[i][j] - s;
          int b = g[i][k] - s;
          if (z[a][b] != -1) {
            v.push_back(a+s);
            v.push_back(z[a][b]);
            v.push_back(b+s);
            v.push_back(i);
            i = j = k = (1 << 28);
          } else {
            z[a][b] = i;
          }
        }
      }
    }
    if (v.empty()) {
      cout << -1 << endl;
    } else {
      each (i, v) cout << i + 1 << ' '; cout << endl;
    }
  }

  return 0;
}
