// github.com/Johniel/contests
// atcoder/abc393/E/main.cpp

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
  lli n, k;
  while (cin >> n >> k) {
    vec<lli> a(n);
    cin >> a;

    const int N = 1e6 + 3;
    vec<lli> freq(N, 0);
    each (i, a) ++freq[i];
    vec<lli> sum(N, 0);
    for (int i = 1; i < N; ++i) {
      for (int j = i; j < N; j += i) {
        sum[i] += freq[j];
      }
    }

    vec<lli> dp(N, 1);
    for (int i = 0; i < N; ++i) {
      if (k <= sum[i]) dp[i] = i;
    }
    for (int i = 1; i < N; ++i) {
      for (int j = 2; i * j < N; ++j) {
        if (k <= sum[i]) setmax(dp[i * j], dp[i]);
        if (k <= sum[j]) setmax(dp[i * j], dp[j]);
      }
    }
    each (i, a) cout << dp[i] << endl;

    // vec<lli> v;
    // vec<lli> memo(N, -1);
    // for (int i = 0; i < a.size(); ++i) {
    //   if (memo[a[i]] != -1) {
    //     v.push_back(memo[a[i]]);
    //     continue;
    //   }
    //   lli best = 1;
    //   for (lli j = 1; j * j <= a[i]; ++j) {
    //     if (a[i] % j == 0) {
    //       if (k <= sum[a[i] / j]) setmax(best, a[i] / j);
    //       if (k <= sum[j]) setmax(best, j);
    //     }
    //   }
    //   memo[a[i]] = best;
    //   v.push_back(best);
    // }
    // each (i, v) cout << i << endl;
  }
  return 0;
}
