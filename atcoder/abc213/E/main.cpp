// atcoder/abc213/E/main.cpp
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

constexpr lli mod = 1e9 + 7;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int h, w;
  while (cin >> h >> w) {
    const int H = 500 + 3;
    const int W = 500 + 3;
    const int B = 2;
    static int cost[H][W];
    const int inf = 1 << 27;
    fill(&cost[0][0], &cost[H - 1][W - 1], inf);

    static char g[H][W];
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> g[i][j];
      }
    }

    const int di[] = {-1, 0, +1, 0};
    const int dj[] = {0, +1, 0, -1};

    priority_queue<pair<int, pair<int, int>>> q;
    q.push(make_pair(0, make_pair(0, 0)));
    cost[0][0] = 0;
    while (!q.empty()) {
      auto p = q.top();
      const int i = p.second.first;
      const int j = p.second.second;
      const int C = abs(p.first);
      q.pop();
      if (cost[i][j] != C) continue;
      if (i == h - 1 && j == w - 1) break;
      for (int d = 0; d < 4; ++d) {
        int ni = i + di[d];
        int nj = j + dj[d];
        unless (0 <= ni && ni < h) continue;
        unless (0 <= nj && nj < w) continue;
        unless (g[i][j] == '.') continue;
        if (C < cost[ni][nj]) {
          cost[ni][nj] = C;
          q.push(make_pair(-cost[ni][nj], make_pair(ni, nj)));
        }
      }
      for (int d = 0; d < 4; ++d) {
        const int nr = (d + 1) % 4;
        const int nl = (d + 3) % 4;
        vec<int> a;
        vec<int> b;

        a.push_back(i + di[d]);
        b.push_back(j + dj[d]);

        a.push_back(i + di[d] + di[nr]);
        b.push_back(j + dj[d] + dj[nr]);

        a.push_back(i + di[d] + di[nl]);
        b.push_back(j + dj[d] + dj[nl]);


        a.push_back(i + di[d]+ di[d]);
        b.push_back(j + dj[d]+ dj[d]);

        a.push_back(i + di[d]+ di[d] + di[nr]);
        b.push_back(j + dj[d]+ dj[d] + dj[nr]);

        a.push_back(i + di[d]+ di[d] + di[nl]);
        b.push_back(j + dj[d]+ dj[d] + dj[nl]);

        for (int k = 0; k < a.size(); ++k) {
          int ni = a[k];
          int nj = b[k];
          unless (0 <= ni && ni < h) continue;
          unless (0 <= nj && nj < w) continue;
          const int nc = C + 1;
          if (nc < cost[ni][nj]) {
            cost[ni][nj] = nc;
            q.push(make_pair(-cost[ni][nj], make_pair(ni, nj)));
          }
        }
      }
    }

    cout << cost[h - 1][w - 1] << endl;
  }

  return 0;
}
