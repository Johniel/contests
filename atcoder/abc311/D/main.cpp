// github.com/Johniel/contests
// atcoder/abc311/D/main.cpp

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
  int h, w;
  while (cin >> h >> w) {
    const int H = 200 + 3;
    const int W = 200 + 3;
    static char g[H][W];
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> g[i][j];
      }
    }

    static bool vis[H][W];
    static bool reach[H][W];
    fill(&vis[0][0], &vis[H - 1][W - 1] + 1, false);
    fill(&reach[0][0], &reach[H - 1][W - 1] + 1, false);

    vis[1][1] = reach[1][1] = true;
    queue<pair<int, int>> q;
    for (q.push(make_pair(1, 1)); q.size(); q.pop()) {
      pair<int, int> curr = q.front();
      for (int d = 0; d < 4; ++d) {
        for (int l = 1; ; ++l) {
          int ni = curr.first  + di[d] * l;
          int nj = curr.second + dj[d] * l;
          if (g[ni][nj] == '#') {
            ni -= di[d];
            nj -= dj[d];
            if (!vis[ni][nj]) {
              vis[ni][nj] = true;
              q.push(make_pair(ni, nj));
            }
            break;
          }
          reach[ni][nj] = true;
        }
      }
    }
    // for (int i = 0; i < h; ++i) {
    //   for (int j = 0; j < w; ++j) {
    //     if (g[i][j] == '#') cout << "#";
    //     else cout << (reach[i][j] ? "_" : ".");
    //   }
    //   cout << endl;
    // }
    cout << count(&reach[0][0], &reach[H - 1][W - 1] + 1, true) << endl;
  }
  return 0;
}
