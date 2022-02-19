// codeforces/771div2/D/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
#define endl "\n"

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

  const int H = 1000 + 3;
  const int W = 1000 + 3;
  int h, w;
  while (cin >> h >> w) {
    static int g[H][W];
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> g[i][j];
      }
    }

    static bool vis[H][W];
    queue<pair<int, int>> q;
    for (int i = 0; i + 1 < h; ++i) {
      for (int j = 0; j + 1 < w; ++j) {
        vis[i][j] = false;
        if (g[i][j] == g[i][j + 1] && g[i][j] == g[i + 1][j] && g[i][j] == g[i + 1][j + 1]) {
          q.push({i, j});
          vis[i][j] = true;
        }
      }
    }

    vec<int> color;
    vec<pair<int, int>> v;
    while (q.size()) {
      pair<int, int> p = q.front();
      q.pop();

      // cout <<p << endl;
      // for (int i = 0; i < h; ++i) {
      //   for (int j = 0; j < w; ++j) cout << g[i][j] << ' ';
      //   cout << endl;
      // }

      const int i = p.first;
      const int j = p.second;
      const int mx = max({g[i][j], g[i + 1][j], g[i][j + 1], g[i + 1][j + 1]});
      if (mx == 0) continue;
      g[i][j] = g[i + 1][j] = g[i][j + 1] = g[i + 1][j + 1] = 0;
      v.push_back(p);
      color.push_back(mx);
      for (int d = 0; d < 8; ++d) {
        const int ni = i + di[d];
        const int nj = j + dj[d];
        unless (0 <= ni && ni + 1 < h) continue;
        unless (0 <= nj && nj + 1 < w) continue;
        if (vis[ni][nj]) continue;

        const int mx = max({g[ni][nj], g[ni + 1][nj], g[ni][nj + 1], g[ni + 1][nj + 1]});
        bool f = (mx != 0);
        f = f && (g[ni][nj] == mx || g[ni][nj] == 0);
        f = f && (g[ni + 1][nj] == mx || g[ni + 1][nj] == 0);
        f = f && (g[ni][nj + 1] == mx || g[ni][nj + 1] == 0);
        f = f && (g[ni + 1][nj + 1] == mx || g[ni + 1][nj + 1] == 0);
        if (f) {
          q.push({ni, nj});
          vis[ni][nj] = true;
        }
      }
    }

    int z = 0;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        z += (g[i][j] == 0);
      }
    }
    if (z != h * w) {
      cout << -1 << endl;
      continue;
    }
    reverse(v.begin(), v.end());
    reverse(color.begin(), color.end());
    cout << v.size() << endl;
    for (int i = 0; i < v.size(); ++i) {
      cout << v[i].first + 1 << ' ' << v[i].second + 1 << ' ' << color[i] << endl;
    }
  }

  return 0;
}
