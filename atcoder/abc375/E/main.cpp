// github.com/Johniel/contests
// atcoder/abc375/E/main.cpp

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
    vec<pair<int, int>> v(n);
    cin >> v;
    each (i, v) --i.first;

    const int N = 100 + 2;
    const int M = 1500 + 2;
    static int dp[N][M][M];
    const int inf = 1 << 29;
    fill(&dp[0][0][0], &dp[N - 1][M - 1][M - 1], inf);
    dp[0][0][0] = 0;
    int sum = 0;
    for (int i = 0; i < v.size(); ++i) {
      sum += v[i].second;
      for (int a = 0; a <= sum; ++a) {
        for (int b = 0; a + b <= sum; ++b) {
          if (inf <= dp[i][a][b]) continue;

          if (v[i].first == 0) {
            setmin(dp[i + 1][a + v[i].second][b], dp[i][a][b]);
            setmin(dp[i + 1][a][b + v[i].second], dp[i][a][b] + 1);
            setmin(dp[i + 1][a][b], dp[i][a][b] + 1);
          }

          if (v[i].first == 1) {
            setmin(dp[i + 1][a + v[i].second][b], dp[i][a][b] + 1);
            setmin(dp[i + 1][a][b + v[i].second], dp[i][a][b]);
            setmin(dp[i + 1][a][b], dp[i][a][b] + 1);
          }

          if (v[i].first == 2) {
            setmin(dp[i + 1][a + v[i].second][b], dp[i][a][b] + 1);
            setmin(dp[i + 1][a][b + v[i].second], dp[i][a][b] + 1);
            setmin(dp[i + 1][a][b], dp[i][a][b]);
          }

        }
      }
    }
    sum = 0;
    each (k, v) sum += k.second;
    int z = inf;
    if (sum % 3 == 0) {
      setmin(z, dp[n][sum / 3][sum / 3]);
    }
    if (z == inf) z = -1;
    cout << z << endl;
  }
  return 0;
}
