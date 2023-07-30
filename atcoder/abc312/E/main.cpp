// github.com/Johniel/contests
// atcoder/abc312/E/main.cpp

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

int main(int argc, char *argv[])
{
  int n;
  while (cin >> n) {
    int x1[n], y1[n], z1[n];
    int x2[n], y2[n], z2[n];
    for (int i = 0; i < n; ++i) {
      cin >> x1[i] >> y1[i] >> z1[i] >> x2[i] >> y2[i] >> z2[i];
    }

    map<tuple<int, int, int>, int> m;
    vec<tuple<int, int, int>> v[n];
    for (int i = 0; i < n; ++i) {
      for (int x = x1[i]; x < x2[i]; ++x) {
        for (int y = y1[i]; y < y2[i]; ++y) {
          v[i].push_back(make_tuple(x, y, z1[i]));
          v[i].push_back(make_tuple(x, y, z2[i] - 1));
        }
      }
      for (int y = y1[i]; y < y2[i]; ++y) {
        for (int z = z1[i]; z < z2[i]; ++z) {
          v[i].push_back(make_tuple(x1[i], y, z));
          v[i].push_back(make_tuple(x2[i] - 1, y, z));
        }
      }
      for (int x = x1[i]; x < x2[i]; ++x) {
        for (int z = z1[i]; z < z2[i]; ++z) {
          v[i].push_back(make_tuple(x, y1[i], z));
          v[i].push_back(make_tuple(x, y2[i] - 1, z));
        }
      }
      each (k, v[i]) m[k] = i;
    }

    for (int i = 0; i < n; ++i) {
      set<int> vis;
      each (k, v[i]) {
        auto [x, y, z] = k;
        for (int d = 0; d < 6; ++d) {
          int dx[] = {+1, -1, 0, 0, 0, 0};
          int dy[] = {0, 0, +1, -1, 0, 0};
          int dz[] = {0, 0, 0, 0, +1, -1};
          tuple<int, int, int> p = make_tuple(x + dx[d], y + dy[d], z + dz[d]);
          if (m.count(p)) vis.insert(m[p]);
        }
      }
      vis.erase(i);
      cout << vis.size() << endl;
    }
  }
  return 0;
}
