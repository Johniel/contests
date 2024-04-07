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

int main(int argc, char *argv[])
{
  int h, w;
  while (cin >> h >> w) {
    const int H = 200 + 3;
    const int W = 200 + 3;
    const int N = 300 + 3;
    static char g[H][W];

    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> g[i][j];
      }
    }
    static int e[H][W];
    fill(&e[0][0], &e[H - 1][W - 1] + 1, 0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      cin >> e[a][b];
    }

    pair<int, int> src, dst;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if (g[i][j] == 'S') src = make_pair(i, j);
        if (g[i][j] == 'T') dst = make_pair(i, j);
      }
    }

    const int inf = 1 << 29;
    static int r[H][W];
    fill(&r[0][0], &r[H - 1][W - 1] + 1, -inf);
    r[src.first][src.second] = 0;
    priority_queue<pair<int, pair<int, int>>> q;
    q.push(make_pair(0, src));
    while (q.size()) {
      auto [rem, p] = q.top();
      auto [i, j] = p;
      q.pop();
      if (rem < 0) continue;
      if (rem != r[i][j]) continue;
      int di[] = {0, 0, -1, +1};
      int dj[] = {-1, +1, 0, 0};
      for (int d = 0; d < 4; ++d) {
        int ni = i + di[d];
        int nj = j + dj[d];
        unless (0 <= ni && ni < h) continue;
        unless (0 <= nj && nj < w) continue;
        if (g[ni][nj] == '#') continue;
        if (r[ni][nj] < r[i][j] - 1) {
          r[ni][nj] = r[i][j] - 1;
          q.push(make_pair(r[ni][nj], make_pair(ni, nj)));
        }
        if (r[ni][nj] < e[i][j] - 1) {
          r[ni][nj] = e[i][j] - 1;
          q.push(make_pair(r[ni][nj], make_pair(ni, nj)));
        }
      }
    }
    cout << (0 <= r[dst.first][dst.second] ? "Yes" : "No") << endl;
  }
return 0;
}
