// github.com/Johniel/contests
// atcoder/abc348/D/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
#define makepair(a, b) make_pair(a, b)
// #define endl "\n"

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p);
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p);
template<typename P, typename Q, typename R> ostream& operator << (ostream& os, tuple<P, Q, R> t) { os << "(" << get<0>(t) << "," << get<1>(t) << "," << get<2>(t) << ")"; return os; }
template<typename P, typename Q, typename R> istream& operator >> (istream& is, tuple<P, Q, R>& t) { is >> get<0>(t) >> get<1>(t) >> get<2>(t); return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; for (auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, set<T> s) { os << "set{"; for (auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "map{"; for (auto& i: m) os << i << ","; os << "}"; return os; }
template<typename E, size_t N> istream& operator >> (istream& is, array<E, N>& a) { for (auto& i: a) is >> i; return is; }
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[" << N << "]{"; for (auto& i: a) os << i << ","; os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, stack<T> s) { os << "stack{"; while (s.size()) { os << s.top() << ","; s.pop(); } os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, queue<T> q) { os << "queue{"; while (q.size()) { os << q.front() << ","; q.pop(); } os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, deque<T> q) { os << "deque{"; for (int i = 0; i < q.size(); ++i) os << q[i] << ","; os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, priority_queue<T> q) { os << "heap{"; while (q.size()) { os << q.top() << ","; q.pop(); } os << "}"; return os; }
template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

__attribute__((constructor)) static void _____(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

// constexpr lli mod = 1e9 + 7;
constexpr lli mod = 998244353;

const int H = 200 + 3;
const int W = 200 + 3;
const int N = 300 + 3;
char g[H][W];
int cost[H][W];
const int inf = 1 << 29;
int h, w;
void bfs(int si, int sj)
{
  queue<pair<int, int>> q;
  fill(&cost[0][0], &cost[H - 1][W - 1], inf);
  cost[si][sj] = 0;
  for (q.push(make_pair(si, sj)); q.size(); q.pop()) {
    auto [i, j] = q.front();
    int di[] = {0, 0, -1, +1};
    int dj[] = {-1, +1, 0, 0};
    for (int d = 0; d < 4; ++d) {
      int ni = i + di[d];
      int nj = j + dj[d];
      unless (0 <= ni && ni < h) continue;
      unless (0 <= nj && nj < w) continue;
      if (g[ni][nj] == '#') continue;
      if (cost[ni][nj] > cost[i][j] + 1) {
        cost[ni][nj] = cost[i][j] + 1;
        q.push(make_pair(ni, nj));
      }
    }
  }
  return ;
}

int main(int argc, char *argv[])
{
  while (cin >> h >> w) {
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> g[i][j];
      }
    }
    int n;
    cin >> n;
    vec<pair<int, int>> v(n);
    vec<int> e(n);
    for (int i = 0; i < v.size(); ++i) {
      cin >> v[i] >> e[i];
      --v[i].first;
      --v[i].second;
    }

    pair<int, int> src, dst;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if (g[i][j] == 'S') src = make_pair(i, j);
        if (g[i][j] == 'T') dst = make_pair(i, j);
      }
    }
    v.push_back(src);
    v.push_back(dst);
    static lli x[N][N];
    for (int i = 0; i < v.size(); ++i) {
      bfs(v[i].first, v[i].second);
      for (int j = 0; j < v.size(); ++j) {
        x[i][j] = cost[v[j].first][v[j].second];
      }
    }

    // cout << src << ' ' << dst << endl;
    // for (int i = 0; i < v.size(); ++i) {
    //   for (int j = 0; j < v.size(); ++j) {
    //     cout << x[i][j] << ' ';
    //   }
    //   cout << endl;
    // }

    static lli y[H][W];
    fill(&y[0][0], &y[H - 1][W - 1], 0);
    for (int i = 0; i < n; ++i) {
      y[v[i].first][v[i].second] = e[i];
    }

    static lli mx[N];
    fill(mx, mx + N, -inf);
    const int s = v.size() - 2;
    const int d = v.size() - 1;
    mx[s] = 0;
    priority_queue<pair<lli, int>> q;
    q.push(make_pair(mx[s], s));
    bool vis[N];
    fill(vis, vis + N, false);
    while (q.size()) {
      auto [remained, curr] = q.top();
      q.pop();
      if (vis[curr]) continue;
      if (mx[curr] != remained) continue;
      vis[curr] = true;
      for (int next = 0; next < v.size(); ++next) {
        if (next == curr) continue;
        auto [i, j] = v[curr];
        if (vis[next]) continue;
        {
          lli r = y[i][j] - x[curr][next];
          if (mx[next] < r && 0 <= r) {
            mx[next] = r;
            q.push(make_pair(mx[next], next));
          }
        }
        {
          lli r = mx[curr] - x[curr][next];
          if (mx[next] < r && 0 <= r) {
            mx[next] = r;
            q.push(make_pair(mx[next], next));
          }
        }
      }
    }
    // for (int i = 0; i < v.size(); ++i) cout << mx[i] << ' '; cout << endl;
    cout << (vis[d] ? "Yes" : "No") << endl;
  }
  return 0;
}
