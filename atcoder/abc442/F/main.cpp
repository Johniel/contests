// github.com/Johniel/contests
// atcoder/abc442/F/main.cpp

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
  PrefixSum(vector<T> v = {}) {
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
  int n;
  while (cin >> n) {
    const int N = 5000 + 3;
    static char g[N][N];
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> g[i][j];
      }
    }
    PrefixSum<int> white[n];
    for (int j = 0; j < n; ++j) {
      vec<int> v;
      for (int i = 0; i < n; ++i) {
        v.push_back(g[i][j] == '.');
      }
      white[j] = PrefixSum<int>(v);
    }
    static int dp[N][N]; // [j列目が][上からiまで白い]:=コスト
    const int inf = (1 << 29);
    fill(&dp[0][0], &dp[N - 1][N - 1] + 1, inf);
    {
      const int j = 0;
      for (int i = 0; i <= n; ++i) {
        int black_ng = i - white[j](0, i);
        int white_ng = white[j](i, n);
        dp[j][i] = black_ng + white_ng;
      }
    }
    for (int j = 1; j < n; ++j) {
      int prev_mn = dp[j - 1][n];
      for (int i = n; 0 <= i; --i) {
        setmin(prev_mn, dp[j - 1][i]);
        int black_ng = i - white[j](0, i);
        int white_ng = white[j](i, n);
        dp[j][i] = black_ng + white_ng + prev_mn;
      }
    }

    // for (int i = 0; i <= n; ++i) {
    //   for (int j = 0; j <= n; ++j) {
    //     cout << dp[i][j] << ' ';
    //   }
    //   cout << endl;
    // }

    int mn = inf;
    for (int i = 0; i <= n; ++i) {
      setmin(mn, dp[n - 1][i]);
    }
    cout << mn << endl;
  }
  return 0;
}
