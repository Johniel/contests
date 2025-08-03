// github.com/Johniel/contests
// atcoder/abc417/D/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
#define __builtin_popcount(x) __builtin_popcountll(x)

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p);
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p);
template<typename... Ts> ostream& operator << (ostream& os, const tuple<Ts...>& t) { os << "("; if constexpr (sizeof...(Ts) > 0) { apply([&](const Ts&... args) { ((os << args << ','), ...); }, t); } os << ")"; return os; }
template<typename... Ts> istream& operator >> (istream& is, tuple<Ts...>& t) { apply([&](Ts&... args) { ((is >> args), ...); }, t); return is; }
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

constexpr lli mod = 998244353; // 1e9 + 7;

template<typename T>
struct PrefixSum {
  vector<T> sum;
  PrefixSum(vector<T> v) {
    sum.push_back(T(0));
    for (int i = 0; i < v.size(); ++i) {
      sum.push_back(sum.back() + v[i]);
    }
  }
  T operator () (size_t begin, size_t end) const {
    assert(begin <= end);
    return sum.at(end) - sum.at(begin);
  }
  T operator () (size_t end) const { return (*this)(0, end); }
  size_t size(void) const { return (int)sum.size() - 1; }
};

int main(int argc, char *argv[])
{
  const int N = 10000 + 3;
  const int A = 500;
  const int B = 500;
  int n;
  while (cin >> n) {
    vec<int> p(n), a(n), b(n);
    for (int i = 0; i < n; ++i) {
      cin >>p[i] >> a[i] >> b[i];
    }

    PrefixSum<int> S(b);



    // dp[n][t]:=n日目にテンションがtだった場合の最終日のテンション。逆から作る。
    vec<vec<lli>> dp(N + 1, vec<lli>(501, -(1LL << 60)));
    for (int i = 0; i <= 500; ++i) {
      dp[n][i] = i;
    }
    for (int i = n - 1; 0 <= i; --i) {
      for (int t = 0; t <= A; ++t) {
        const int nt = (t <= p[i] ? (t + a[i]) : max(0, t - b[i]));
        if (nt <= A) {
          dp[i][t] = dp[i + 1][nt];
        } else {
          int d = nt - A;
          int j = lower_bound(S.sum.begin() + i + 1, S.sum.end(), d + S.sum[i + 1]) - S.sum.begin();

          if (j == S.sum.size()) {
            dp[i][t] = nt - (S.sum.back() - S.sum[i + 1]);
            continue;
          }
          int y = nt - (S.sum[j] - S.sum[i + 1]);
          if (n <=j) { //
            dp[i][t] = y;
          } else {
            dp[i][t] = dp[j][y];
          }
        }
      }
    }
    // cout << dp << endl;
    int q;
    cin >> q;
    while (q--) {
      int x;
      cin >> x;

      if (x <= A) {
        cout << dp[0][x] << endl;
        continue;
      }

      int j = lower_bound(S.sum.begin(), S.sum.end(), (x - A)) - S.sum.begin();

      if (n <= j) {
        cout << x - S.sum[n] << endl;
        continue;
      }

      int y = x - S.sum[j];
      if (n <= j) {
        cout << y << endl;
      } else {
        cout << dp[j][y] << endl;
      }
    }
  }
  return 0;
}
