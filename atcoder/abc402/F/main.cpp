// github.com/Johniel/contests
// atcoder/abc402/F/main.cpp

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
// constexpr lli mod = 998244353;

int main(int argc, char *argv[])
{
  int n;
  lli mod;
  while (cin >> n >> mod) {
    lli g[n][n];
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> g[i][j];
      }
    }
    // 2^20=1048576
    const int N = 20 + 1;
    set<lli> dp1[N][N];
    dp1[0][0].insert(0);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (j == n - i - 1) break;
        each (k, dp1[i][j]) {
          if (i + 1 < n) dp1[i + 1][j].insert((k * 10 + g[i][j]) % mod);
          if (j + 1 < n) dp1[i][j + 1].insert((k * 10 + g[i][j]) % mod);
        }
      }
    }

    vec<lli> p10({1});
    for (int i = 0; i < 100; ++i) {
      p10.push_back((p10.back() * 10) % mod);
    }

    set<lli> dp2[N][N];
    dp2[n - 1][n -1].insert(g[n - 1][n - 1]);
    for (int i = n - 1; 0 <= i; --i) {
      for (int j = n - 1; 0 <= j; --j) {
        unless (n <= i + j) continue;
        const int w = p10[(2 * n - 1) - (i + j)];
        each (k, dp2[i][j]) {
          if (0 <= i - 1) dp2[i - 1][j].insert((k + (g[i - 1][j] * w) % mod) % mod);
          if (0 <= j - 1) dp2[i][j - 1].insert((k + (g[i][j - 1] * w) % mod) % mod);
        }
      }
    }

    lli z = 0;
    for (int i = 0; i < n; ++i) {
      const int j = n - i - 1;
      each (a, dp1[i][j]) {
        const lli x = (a * p10[n]) % mod;
        auto itr = dp2[i][j].lower_bound(mod - x);
        if (itr != dp2[i][j].begin()) {
          --itr;
          setmax(z, x + (*itr));
        }
        setmax(z, (x + (*dp2[i][j].begin())) % mod);
        setmax(z, (x + (*dp2[i][j].rbegin())) % mod);
      }
    }
    cout << z << endl;
  }
  return 0;
}
