// github.com/Johniel/contests
// atcoder/abc375/C/main.cpp

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

// constexpr lli mod = 1e9 + 7;
constexpr lli mod = 998244353;

int main(int argc, char *argv[])
{
  int n;
  while (cin >> n) {
    char g[n][n][4];
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> g[i][j][0];
      }
    }
    for (int k = 0; k + 1 < 4; ++k) {
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          g[j][n - 1 - i][k + 1] = g[i][j][k];
        }
      }
    }

    // for (int k = 0; k < 4; ++k) {
    //   cout << k << endl;
    //   for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < n; ++j) {
    //       cout << g[i][j][k];
    //     }
    //     cout << endl;
    //   }
    // }
    // cout << endl;

    queue<pair<int,int>> q;
    bool vis[n][n];
    int cost[n][n];
    const int inf = 1 << 29;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        vis[i][j] = false;
        cost[i][j] = inf;
      }
    }
    for (int i = 0; i < n; ++i) {
      q.push(make_pair(0, i));
      q.push(make_pair(i, 0));
      q.push(make_pair(n - 1, i));
      q.push(make_pair(i, n - 1));
      vis[i][0] = vis[0][i] = true;
      vis[i][n - 1] = vis[n - 1][i] = true;
      cost[i][0] = cost[0][i] = 0;
      cost[i][n - 1] = cost[n - 1][i] = 0;
    }
    while (q.size()) {
      auto [i, j] = q.front();
      q.pop();
      for (int d = 0; d < 4; ++d) {
        constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
        constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
        int ni = i + di[d];
        int nj = j + dj[d];
        unless (0 <= ni && ni < n) continue;
        unless (0 <= nj && nj < n) continue;
        if (vis[ni][nj]) continue;
        vis[ni][nj] = true;
        cost[ni][nj] = cost[i][j] + 1;
        q.push(make_pair(ni, nj));
      }
    }

    // for (int i = 0; i < n; ++i) {
    //   for (int j = 0; j < n; ++j) {
    //     cout <<  cost[i][j] << ' ';
    //   }
    //   cout << endl;
    // }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        int k = (cost[i][j] + 1) % 4;
        // int k = min<int>({i - 1, j - 1, n - i, n - j});
        // if (cost[i][j] % 2 == 0) cout << g[i][j];
        // else cout << h[i][j];
        cout << g[i][j][k];
      }
      cout << endl;
    }
    // break;
  }
  return 0;
}
