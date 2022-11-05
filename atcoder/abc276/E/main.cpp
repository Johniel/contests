// github.com/Johniel/contests
// atcoder/abc276/E/main.cpp

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
  int h, w;
  while (cin >> h >> w) {
    char g[h][w];
    pair<int, int> src;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> g[i][j];
        if (g[i][j] == 'S') src = make_pair(i, j);
      }
    }
    bool vis[h][w];
    bool f = false;
    for (int k = 0; k < 4; ++k) {
      auto inside = [&] (int i, int j) {
        unless (0 <= i && i < h) return false;
        unless (0 <= j && j < w) return false;
        return true;
      };
      for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
          vis[i][j] = false;
        }
      }
      queue<pair<int, int>> q;
      vis[src.first][src.second] = true;
      for (q.push(src); q.size(); q.pop()) {
        pair<int, int> curr = q.front();
        for (int d = 0; d < 4; ++d) {
          if (curr == src && d != k) continue;
          int ni = curr.first + di[d];
          int nj = curr.second + dj[d];
          unless (inside(ni, nj)) continue;
          if (g[ni][nj] == '#') continue;
          if (vis[ni][nj]) continue;
          q.push(make_pair(ni, nj));
          vis[ni][nj] = true;
        }
      }
      for (int d = 0; d < 4; ++d) {
        if (d == k) continue;
        int ni = src.first + di[d];
        int nj = src.second + dj[d];
        unless (inside(ni, nj)) continue;
        if (vis[ni][nj]) f = true;
      }
    }

    cout << (f ? "Yes" : "No") << endl;
  }
  return 0;
}
