// github.com/Johniel/contests
// atcoder/abc376/F/main.cpp

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

const int N = 3000 + 3;

// 0〜n-1までの番号の振られて円状に並んだマスを-1,+1の方向それぞれに移動できる。
// aからbまで移動するために-1方向+1方向に何度移動すれば到達するかを返す。
// {-1方向の移動回数,+1方向の移動回数}
// https://atcoder.jp/contests/abc376/tasks/abc376_f
template<std::integral T>
pair<T, T> ring(T a, T b, T n) {
  if (a == b) return make_pair(T(0), T(0));

  if (a < b) {
    T x = b - a;
    T y = n - x;
    return make_pair(y, x);
  } else {
    T y = a - b;
    T x = n - y;
    return make_pair(y, x);
  }
}

int main(int argc, char *argv[])
{
  const int inf = 1 << 28;

  int n, q;
  while (cin >> n >> q) {
    vec<pair<char, int>> v(q);
    cin >> v;
    each (i, v) --i.second;

    static int dp[N][N]; // dp[いまどのクエリ][もう一方の手の位置]:=動かした回数
    fill(&dp[0][0], &dp[N - 1][N - 1] + 1, inf);

    v.insert(v.begin(), make_pair('L', 0));
    dp[1][1] = 0;

    for (int i = 1; i < v.size(); ++i) {
      assert(i);
      for (int j = 0; j < n; ++j) {
        auto F = [&] () {
          int R, L;
          if (v[i - 1].first == 'R') L = j, R = v[i - 1].second;
          if (v[i - 1].first == 'L') R = j, L = v[i - 1].second;
          return make_pair(L, R);
        };
        if (inf <= dp[i][j]) continue;
        const int T = v[i].second;

        if (v[i].first == 'R') {
          if (const int D = +1; true) { // +1
            auto [L, R] = F();
            auto [_l, wL] = ring(L, T, n);
            auto [_r, wR] = ring(R, T, n);
            int cost = dp[i][j] + wR;
            if (wL < wR) {
              const int nL = (T + D + n) % n;
              cost += wL + 1;
              L = nL;
            }
            setmin(dp[i + 1][L], cost);
          }
          if (const int D = -1; true) { // -1
            auto [L, R] = F();
            auto [wL, _l] = ring(L, T, n);
            auto [wR, _r] = ring(R, T, n);
            int cost = dp[i][j] + wR;
            if (wL < wR) {
              const int nL = (T + D + n) % n;
              cost += wL + 1;
              L = nL;
            }
            setmin(dp[i + 1][L], cost);
          }
        }

        if (v[i].first == 'L') {
          if (const int D = +1; true) { // +1
            auto [L, R] = F();
            auto [_l, wL] = ring(L, T, n);
            auto [_r, wR] = ring(R, T, n);
            int cost = dp[i][j] + wL;
            if (wR < wL) {
              const int nR = (T + D + n) % n;
              cost += wR + 1;
              R = nR;
            }
            setmin(dp[i + 1][R], cost);
          }
          if (const int D = -1; true) { // -1
            auto [L, R] = F();
            auto [wL, _l] = ring(L, T, n);
            auto [wR, _r] = ring(R, T, n);
            int cost = dp[i][j] + wL;
            if (wR < wL) {
              const int nR = (T + D + n) % n;
              cost += wR + 1;
              R = nR;
            }
            setmin(dp[i + 1][R], cost);
          }
        }
      }
    }
    int z = inf;
    for (int i = 0; i < N; ++i) {
      setmin(z, dp[v.size()][i]);
    }
    cout << z << endl;
  }
  return 0;
}
