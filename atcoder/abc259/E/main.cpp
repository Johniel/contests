// atcoder/abc259/E/main.cpp
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
using point = complex<double>;
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;
// constexpr lli mod = 998244353;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n;
  while (cin >> n) {
    const int N = 2 * 1e5 + 2;
    map<int, vec<int>> x;
    vec<vec<pair<int, int>>> u;
    for (int i = 0; i < n; ++i) {
      int m;
      cin >> m;
      u.push_back({});
      for (int j = 0; j < m; ++j) {
        lli p, e;
        cin >> p >> e;
        u.back().push_back({p, e});
        x[p].push_back(e);
      }
    }
    sort(u.begin(), u.end());
    u.erase(unique(u.begin(), u.end()), u.end());

    map<int, int> idx;
    vec<int> v;
    each (i, x) {
      sort(i.second.begin(), i.second.end());
      idx[i.first] = v.size();
      v.push_back(i.second.back());
    }
    set<vec<int>> vis;
    for (int i = 0; i < u.size(); ++i) {
      vec<int> w;
      each (j, u[i]) {
        const int y = x[j.first].size();
        if (y && x[j.first].back() == j.second) {
          if (2 <= y && x[j.first][y - 1] != x[j.first][y - 2]) {
            w.push_back(j.first);
          } else if (y == 1) {
            w.push_back(j.first);
          }
        }
      }
      vis.insert(w);
    }
    // cout << vis << endl;
    cout << vis.size() << endl;
  }

  return 0;
}
