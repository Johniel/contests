// github.com/Johniel/contests
// codeforces/938div3/H/main.cpp

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

const int H = 50 + 2;
const int W = 50 + 2;

int main(int argc, char *argv[])
{

  vec<lli> p3(100);
  p3[0] = 1;
  for (int i = 1; i < p3.size(); ++i) {
    p3[i] = p3[i - 1] * 3;
  }

  { int _; cin >> _; }
  int h, w, t;
  while (cin >> h >> w >> t) {
    char g[h][w];
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> g[i][j];
      }
    }
    int x[t], y[t], p[t];
    for (int i = 0; i < t; ++i) {
      cin >> x[i] >> y[i] >> p[i];
      --x[i];
      --y[i];
    }

    const int R = 13;
    int reach[t][R];
    for (int i = 0; i < t; ++i) {
      for (int j = 0; j < R; ++j) {
        reach[i][j] = 0;
      }
    }
    for (int k = 0; k < t; ++k) {
      const int ti = x[k];
      const int tj = y[k];
      for (int r = 0; r < R; ++r) {
        for (int ei = 0; ei < h; ++ei) {
          for (int ej = 0; ej < w; ++ej) {
            if (g[ei][ej] == '#') {
              int di = ti - ei;
              int dj = tj - ej;
              if (di * di + dj * dj <= r * r) {
                ++reach[k][r];
              }
            }
          }
        }
      }
    }
    const int T = 2500 + 3;
    const int B = (1 << R);
    static lli dp[T][B];
    const lli inf = (1LL << 60);
    for (int i = 0; i <= t; ++i) {
      for (int bit = 0; bit < B; ++bit) {
        dp[i][bit] = -inf;
      }
    }
    dp[0][0] = 0;
    for (int i = 0; i < t; ++i) {
      for (int bit = 0; bit < B; ++bit) {
        for (int r = 1; r < R; ++r) {
          if (bit & (1 << r)) continue;
          setmax(dp[i + 1][bit | (1 << r)], dp[i][bit] + reach[i][r] * p[i]);
          setmax(dp[i + 1][bit], dp[i][bit]);
        }
      }
    }
    lli mx = 0;
    for (int bit = 0; bit < B; ++bit) {
      lli damage = dp[t][bit];
      if (damage < 0) continue;
      lli hp = 0;
      for (int r = 1; r < R; ++r) {
        if (bit & (1 << r)) hp += p3[r];
      }
      setmax(mx, damage - hp);
    }
    cout << mx << endl;
  }

  return 0;
}
