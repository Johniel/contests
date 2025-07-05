// github.com/Johniel/contests
// atcoder/abc413/F/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
#define __builtin_popcount(x) __builtin_popcountll(x)

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<std::ranges::input_range R> requires (!std::same_as<R, std::string>) std::ostream& operator<<(std::ostream& os, const R& r) { os << '{'; for (const auto& e : r) os << e << ','; return os << '}'; }
template<std::ranges::input_range R> requires (!std::same_as<R, std::string>) && std::ranges::sized_range<R> && requires(R& r) { r.begin(); r.end(); } std::istream& operator>>(std::istream& is, R& r) { for (auto& x : r) is >> x; return is; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

__attribute__((constructor)) static void _____(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

constexpr lli mod = 998244353; // 1e9 + 7;

int main(int argc, char *argv[])
{
  int h, w, k;
  while (cin >> h >> w >> k) {
    vec<pair<int, int>> v(k);
    cin >> v;
    each (i, v) --i.first, --i.second;
    const int inf = (1 << 28);
    int dist[h][w];
    fill(&dist[0][0], &dist[h - 1][w - 1] + 1, inf);
    int cnt[h][w];
    fill(&cnt[0][0], &cnt[h - 1][w - 1] + 1, 0);
    queue<pair<int, int>> q;
    each (i, v) {
      cnt[i.first][i.second] = 1;
      dist[i.first][i.second] = 0;
      q.push(i);
    }
    for (; q.size(); q.pop()) {
      auto [i, j] = q.front();
      constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
      constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
      for (int d = 0; d < 4; ++d) {
        const int ni = i + di[d];
        const int nj = j + dj[d];
        unless (0 <= ni && ni < h) continue;
        unless (0 <= nj && nj < w) continue;
        if (cnt[ni][nj] < 2 && dist[ni][nj] == inf) {
          ++cnt[ni][nj];
          if (cnt[ni][nj] == 2) {
            dist[ni][nj] = dist[i][j] + 1;
            q.push(make_pair(ni, nj));
          }
        }
      }
    }
    lli z = 0;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if (dist[i][j] != inf) z += dist[i][j];
      }
    }
    cout << z << endl;
  }
  return 0;
}
