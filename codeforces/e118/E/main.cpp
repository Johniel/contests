// codeforces/e118/E/main.cpp
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
  // cin >> _;
  scanf("%d\n", &_);

  int h, w;
  // while (cin >> h >> w) {
  while (scanf("%d%d\n", &h, &w) == 2) {
    char g[h][w];
    int deg[h][w];
    bool vis[h][w];
    fill(&deg[0][0], &deg[h - 1][w - 1] +1, 0);
    fill(&vis[0][0], &vis[h - 1][w - 1] +1, false);
    int si, sj;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        // deg[i][j] = 0;
        //vis[i][j] = false;
        // cin >> g[i][j];
        scanf("%c", &g[i][j]);
        if (g[i][j] == 'L') {
          si = i;
          sj = j;
        }
      }
      scanf("\n");
    }

    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        for (int d = 0; d < 4; ++d) {
          int ni = i + di[d];
          int nj = j + dj[d];
          unless (0 <= ni && ni < h) continue;
          unless (0 <= nj && nj < w) continue;
          deg[i][j] += (g[ni][nj] != '#');
        }
      }
    }

    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    while (q.size()) {
      pair<int, int> curr = q.front();
      q.pop();
      int i = curr.first;
      int j = curr.second;
      for (int d = 0; d < 4; ++d) {
        int ni = i + di[d];
        int nj = j + dj[d];
        unless (0 <= ni && ni < h) continue;
        unless (0 <= nj && nj < w) continue;
        if (vis[ni][nj]) continue;
        if (g[ni][nj] == '#') continue;
        if (deg[ni][nj] <= 2) {
          q.push({ni, nj});
          vis[ni][nj] = true;
        } else {
          --deg[ni][nj];
        }
      }
    }

    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if (g[i][j] != 'L' && vis[i][j]) g[i][j] = '+';
        // cout << g[i][j];
        printf("%c", g[i][j]);
      }
      puts("");
      // cout << endl;
    }
  }

  return 0;
}
