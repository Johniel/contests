#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; each (i, v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { each (i, v) is >> i; return is; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

const int H = 1000 + 5;
const int W = 1000 + 5;
char g[H][W];

int h, w, n;

queue<pair<int, int>> bfs(queue<pair<int, int>> q, int s)
{
  static int dist[H][W];
  const char color = g[q.front().first][q.front().second];

  queue<pair<int, int>> x;
  while (!q.empty()) {
    dist[q.front().first][q.front().second] = 0;
    x.push(q.front());
    q.pop();
  }
  q = x;
  while (!x.empty()) x.pop();

  const int D = 4;
  const int di[D] = {0, 0, -1, +1};
  const int dj[D] = {-1, +1, 0, 0};

  for (; q.size(); q.pop()) {
    int i = q.front().first;
    int j = q.front().second;
    if (dist[i][j] == s) {
      x.push(make_pair(i, j));
      continue;
    }
    for (int d = 0; d < D; ++d) {
      int ni = i + di[d];
      int nj = j + dj[d];
      unless (0 <= ni && ni <= h) continue;
      unless (0 <= nj && nj <= w) continue;
      unless (g[ni][nj] == '.') continue;
      g[ni][nj] = color;
      dist[ni][nj] = dist[i][j] + 1;
      q.push(make_pair(ni, nj));
    }
  }

  return x;
}

void show(void)
{
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      cout << g[i][j];
    }
    cout << endl;
  }
  cout << endl;
  return ;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> h >> w >> n) {
    fill(&g[0][0], &g[H - 1][W - 1] + 1, '#');

    vector<int> s(n);
    cin >> s;

    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> g[i][j];
      }
    }

    queue<pair<int, int>> q[n];
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if ('1' <= g[i][j] && g[i][j] <= '9') {
          q[g[i][j] - '0' - 1].push(make_pair(i, j));
        }
      }
    }

    // show();
    while (true) {
      bool f = true;
      for (int i = 0; i < n; ++i) {
        f = f && q[i].empty();
      }
      if (f) break;
      for (int i = 0; i < n; ++i) {
        if (!q[i].empty()) q[i] = bfs(q[i], s[i]);
      }
      // show();
    }

    map<char, int> cnt;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if ('1' <= g[i][j] && g[i][j] <= '9') {
          ++cnt[g[i][j]];
        }
      }
    }

    for (char c = '1'; c < '1' + n; ++c) {
      cout << cnt[c] << ' ';
    }
    cout << endl;
  }

  return 0;
}
