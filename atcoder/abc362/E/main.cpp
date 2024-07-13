// github.com/Johniel/contests
// atcoder/abc362/E/main.cpp

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
    vec<lli> a(n);
    cin >> a;
    vec<lli> diff;
    for (int i = 0; i < a.size(); ++i) {
      for (int j = 0; j < a.size(); ++j) {
        lli x = a[i] - a[j];
        diff.push_back(x);
      }
    }
    sort(diff.begin(), diff.end());
    diff.erase(unique(diff.begin(), diff.end()), diff.end());
    // cout << endl; cout << diff << endl; diff = vec<lli>({2});
    vec<lli> z(n+1, 0);
    each (d, diff) {
      const int N = 80 + 3;
      static lli dp[N][N];
      fill(&dp[0][0], &dp[N - 1][N - 1] + 1, 0);
      for (int i = 0; i < n; ++i) {
        dp[i][1] = 1;
      }
      for (int i = 0; i < a.size(); ++i) {
        for (int len = 0; len + 1 < N; ++len) {
          unless (dp[i][len]) continue;
          for (int j = i + 1; j < a.size(); ++j) {
            if (a[j] == a[i] + d) {
              (dp[j][len + 1] += dp[i][len]) %= mod;
            }
          }
        }
      }
      for (int i = 0; i < N; ++i) {
        for (int j = 0; j < z.size(); ++j) {
          (z[j] += dp[i][j]) %= mod;
        }
      }
    }
    // cout << z << endl;
    z.at(1) = n;
    z.erase(z.begin());
    each (i, z) cout << i << ' '; cout << endl;
  }
  return 0;
}
