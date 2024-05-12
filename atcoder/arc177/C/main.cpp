// github.com/Johniel/contests
// atcoder/arc177/C/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

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

int main(int argc, char *argv[])
{
  int n;
  while (cin >> n) {
    static char g[500][500];
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> g[i][j];
      }
    }
    const int inf = 1 << 28;
    int di[] = {0, 0, -1, +1};
    int dj[] = {-1, +1, 0, 0};
    static int cost[4][500][500];
    auto bfs = [&] (pair<int, int> src, const char c, const int k) {
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          cost[k][i][j] = inf;
        }
      }
      cost[k][src.first][src.second] = 0;
      deque<pair<int, int>> q;
      q.push_back(src);
      while (q.size()) {
        auto [i, j] = q.front();
        q.pop_front();
        for (int d = 0; d < 4; ++d) {
          int ni = i + di[d];
          int nj = j + dj[d];
          unless (0 <= ni && ni < n) continue;
          unless (0 <= nj && nj < n) continue;
          if (cost[k][ni][nj] != inf) continue;
          if (c == g[ni][nj]) {
            q.push_front(make_pair(ni, nj));
            cost[k][ni][nj] = cost[k][i][j];
          } else {
            q.push_back(make_pair(ni, nj));
            cost[k][ni][nj] = cost[k][i][j] + 1;
          }
        }
      }
      return ;
    };
    const pair<int, int> a = make_pair(0, 0);
    const pair<int, int> b = make_pair(n - 1, n - 1);
    const pair<int, int> s = make_pair(0, n - 1);
    const pair<int, int> t = make_pair(n - 1, 0);
    bfs(a, 'R', 0);
    bfs(b, 'R', 1);
    bfs(s, 'B', 2);
    bfs(t, 'B', 3);

    int z = inf;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        int w = 0;
        w += cost[0][i][j];
        w += cost[1][i][j];
        w += cost[2][i][j];
        w += cost[3][i][j];
        w -= 1;
        setmin(z, w);
        for (int d = 0; d < 4; ++d) {
          int ni = i + di[d];
          int nj = j + dj[d];
          unless (0 <= ni && ni < n) continue;
          unless (0 <= nj && nj < n) continue;
          {
            int w = 0;
            w += cost[0][i][j];
            w += cost[1][ni][nj];
            w += cost[2][i][j];
            w += cost[3][ni][nj];
            setmin(z, w);
          }
        }
      }
    }
    cout << z << endl;
  }
  return 0;
}
