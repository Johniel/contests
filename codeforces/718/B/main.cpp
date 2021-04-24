// codeforces/718/B/main.cpp
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

  int _;
  cin >> _;

  int n, m;
  while (cin >> n >> m) {
    const int N = 100 + 3;
    const int M = 100 + 3;
    static int g[N][M];
    static int b[N][M];
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        b[i][j] = -1;
        cin >> g[i][j];
      }
    }
    vec<pair<int, int>> v;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        v.push_back(pair<int, int>(g[i][j], i));
      }
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    for (int i = 0; i < m; ++i) {
      pair<int, int> p = v.back();
      v.pop_back();
      b[p.second][i] = p.first;
    }

    static int idx[N];
    fill(idx, idx + N, 0);
    while (v.size()) {
      pair<int, int> p = v.back();
      v.pop_back();
      while (b[p.second][idx[p.second]] != -1) ++idx[p.second];
      b[p.second][idx[p.second]] = p.first;
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cout << b[i][j] << ' ';
      }
      cout << endl;
    }
  }

  return 0;
}
