// yukicoder/1949/main.cpp
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

  const int H = 500 + 3;
  const int W = 500 + 3;
  int h, w, y, x;
  while (cin >> h >> w >> y >> x) {
    --y;
    --x;
    static lli a[H][W];
    static bool vis[H][W];
    fill(&vis[0][0], &vis[H - 1][W - 1] + 1, false);
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> a[i][j];
      }
    }

    priority_queue<pair<lli, pair<int, int>>> q;
    q.push(make_pair(0, make_pair(y, x)));
    lli z = a[y][x];
    a[y][x] = 0;
    while (q.size()) {
      auto curr = q.top();
      q.pop();
      const int i = curr.second.first;
      const int j = curr.second.second;
      if (vis[i][j]) continue;
      unless (a[i][j] < z) continue;
      vis[i][j] = true;
      z += a[i][j];
      for (int d = 0; d < 4; ++d) {
        const int ni = i + di[d];
        const int nj = j + dj[d];
        unless (0 <= ni && ni < h) continue;
        unless (0 <= nj && nj < w) continue;
        if (vis[ni][nj]) continue;
        q.push(make_pair(-a[ni][nj], make_pair(ni, nj)));
      }
    }
    int p = 0;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        p += vis[i][j];
      }
    }
    cout << (p == h * w ? "Yes" : "No") << endl;
  }

  return 0;
}
