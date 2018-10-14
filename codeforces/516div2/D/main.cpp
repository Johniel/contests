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

const int H = 2000 + 5;
const int W = 2000 + 5;
char g[H][W];
pair<int, int> cost[H][W];

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int h, w;
  int si, sj;
  int r, l;
  while (cin >> h >> w >> si >> sj >> l >> r) {
    --si;
    --sj;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> g[i][j];
      }
    }

    int di[] = {0, 0, -1, +1};
    int dj[] = {-1, +1, 0, 0};

    fill(&cost[0][0], &cost[H - 1][W - 1] + 1, make_pair(1 << 30, 1 << 30));

    using state = pair<pair<int, int>, pair<int, int>>;
    priority_queue<state, vector<state>, greater<state>> q;
    q.push({{0, 0}, {si, sj}});
    cost[si][sj] = make_pair(0, 0);

    while (!q.empty()) {
      state curr = q.top();
      int i = curr.second.first;
      int j = curr.second.second;
      q.pop();
      for (int d = 0; d < 4; ++d) {
        int ni = i + di[d];
        int nj = j + dj[d];
        unless (0 <= ni && ni < h) continue;
        unless (0 <= nj && nj < w) continue;
        if (g[ni][nj] == '*') continue;
        pair<int, int> c = cost[i][j];
        c.first += (dj[d] == -1);
        c.second += (dj[d] == +1);
        if (cost[ni][nj] > c) {
          cost[ni][nj] = c;
          q.push({c, {ni, nj}});
        }
      }
    }

    int cnt = 0;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cnt += (cost[i][j].first <= l && cost[i][j].second <= r);
      }
    }
    cout << cnt << endl;
  }

  return 0;
}
