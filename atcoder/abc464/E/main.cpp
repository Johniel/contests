// github.com/Johniel/contests
// atcoder/abc464/E/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
#define __builtin_popcount(x) __builtin_popcountll(x)

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p);
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p);
template<typename... Ts> ostream& operator << (ostream& os, const tuple<Ts...>& t) { os << "("; if constexpr (sizeof...(Ts) > 0) { apply([&](const Ts&... args) { ((os << args << ','), ...); }, t); } os << ")"; return os; }
template<typename... Ts> istream& operator >> (istream& is, tuple<Ts...>& t) { apply([&](Ts&... args) { ((is >> args), ...); }, t); return is; }
template<typename T> ostream& operator << (ostream& os, const vector<T>& v) { os << "("; for (const auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, const set<T>& s) { os << "set{"; for (const auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, const map<K, V>& m) { os << "map{"; for (const auto& i: m) os << i << ","; os << "}"; return os; }
template<typename E, size_t N> istream& operator >> (istream& is, array<E, N>& a) { for (auto& i: a) is >> i; return is; }
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[" << N << "]{"; for (const auto& i: a) os << i << ","; os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, stack<T> s) { os << "stack{"; while (s.size()) { os << s.top() << ","; s.pop(); } os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, queue<T> q) { os << "queue{"; while (q.size()) { os << q.front() << ","; q.pop(); } os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, const deque<T>& q) { os << "deque{"; for (int i = 0; i < q.size(); ++i) os << q[i] << ","; os << "}"; return os; }
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

constexpr lli mod = 998244353; // 1e9 + 7;

int main(int argc, char *argv[])
{
  int h, w, q;
  while (cin >> h >> w >> q) {
    int I[q + 1], J[q + 1];
    char c[q + 1];
    I[0] = h - 1;
    J[0] = w - 1;
    c[0] = 'A';
    for (int k = 1; k <= q; ++k) {
      cin >> I[k] >> J[k] >> c[k];
      // cin >> J[k] >> I[k] >> c[k];
      --I[k];
      --J[k];
    }

    // vec<int> idx(q+1);
    // iota(idx.begin(), idx.end(), 0);
    // sort(idx.begin(), idx.end(), [&] (int x, int y) {
    //   int mx_x = max(i[x], j[x]);
    //   int mx_y = max(i[y], j[y]);
    //   if (mx_x != mx_y) return mx_x < mx_y;
    //   return x < y;
    // });
    // cout << idx << endl;
    // each (k, idx) cout << i[k] << ' ' << j[k] << ' ' << c[k] << endl;


    int dp[h][w];
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        dp[i][j] = -1;
      }
    }
    for (int k = 0; k <= q; ++k) {
      setmax(dp[I[k]][J[k]], k);
    }
    for (int i = h - 1; 0 <= i; --i) {
      for (int j = w - 1; 0 <= j; --j) {
        // if (i + 1 < h && j + 1 < w) setmax(dp[i][j], dp[i + 1][j + 1]);

        if (i + 1 < h) setmax(dp[i][j], dp[i + 1][j]);
        if (j + 1 < w) setmax(dp[i][j], dp[i][j + 1]);
      }
    }
    // for (int i = 0; i < h; ++i) {
    //   for (int j = 0; j < w; ++j) {
    //     cout << dp[i][j] << ' ';
    //   }
    //   cout << endl;
    // }

    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cout << c[dp[i][j]];
      }
      cout << endl;
    }

    // break;
  }
  return 0;
}
