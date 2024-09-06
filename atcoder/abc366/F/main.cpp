// github.com/Johniel/contests
// atcoder/abc366/F/main.cpp

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
  int n, k;
  while (cin >> n >> k) {
    vec<pair<lli, lli>> v(n);
    cin >> v;
    sort(v.begin(), v.end(), [] (auto x, auto y) {
      return (x.first - 1) * y.second < (y.first - 1) * x.second;
    });

    const int N = 2 * 1e5 + 2;
    const int K = 10 + 2;

    const lli inf = (1LL << 50);
    auto get_better = [] (pair<lli, lli> a, pair<lli, lli> b) {
      return (a.first + a.second < b.first + b.second) ? b : a;
    };

    static pair<lli, lli> dp[K][N]; // dp[i][j]:=i個追加した。次はjを追加できる。最大値。
    fill(&dp[0][0], &dp[K - 1][N - 1] + 1, make_pair(-inf, -inf));
    dp[0][0] = make_pair(1, 0);
    for (int i = 0; i < k; ++i) {
      for (int j = 0; j < n; ++j) {
        dp[i][j + 1] = get_better(dp[i][j + 1], dp[i][j]);
      }
      for (int j = 0; j < n; ++j) {
        auto x = dp[i][j];
        pair<lli, lli> p;
        p.first = x.first * v[j].first;
        p.second = x.second * v[j].first + v[j].second;
        dp[i + 1][j + 1] = get_better(dp[i + 1][j + 1], p);
      }
    }

    lli z = -inf;
    for (int i = 0; i < K; ++i) {
      for (int j = 0; j < N; ++j) {
        setmax(z, dp[i][j].first + dp[i][j].second);
      }
    }
    cout << z << endl;
  }
  return 0;
}
