// github.com/Johniel/contests
// codeforces/1013div3/F/main.cpp

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

const int WW = 2000 + 3;

template<typename T>
struct PrefixSum {
  vector<T> sum;
  PrefixSum() { sum.resize(WW); }
  PrefixSum(vector<T> v) {
    sum.push_back(0);
    for (int i = 0; i < v.size(); ++i) {
      sum.push_back((sum.back() + v[i]) % mod);
    }
    while (sum.size() < WW) sum.push_back(0);
  }
  inline void rebuild(const vec<T>& v) {
    for (int i = 0; i < v.size(); ++i) {
      sum[i + 1] = (sum[i] + v[i]) % mod;
    }
  }
  inline T operator () (size_t begin, size_t end) const {
    return (sum[end] - sum[begin] + mod) % mod;
  }
  inline T operator () (size_t end) const {
    return (*this)(0, end);
  }
  size_t size(void) const { return (int)sum.size() - 1; }
};

int main(int argc, char *argv[])
{
  vec<lli> a;
  vec<lli> b;
  // { int _; cin >> _; }
  PrefixSum<lli> sum[2];
  { int _; scanf("%d\n", &_); }
  int h, w, d;
  // while (cin >> h >> w >> d) {
  const int H = 2000 + 3;
  const int W = 2000 + 3;
  while (scanf("%d %d %d\n", &h, &w, &d) == 3) {
    static char g[H][W];
    for (int i =  h - 1; 0 <= i; --i) {
      scanf("%s\n", &g[i][0]);
    }
    static lli dp[H][W][2];
    for (int i = 0; i <= min(3, h); ++i) {
      for (int j = 0; j <= w; ++j) {
        dp[i][j][0] = dp[i][j][1] = 0;
      }
    }
    for (int j = 0; j < w; ++j) {
      if (g[0][j] == 'X') dp[0][j][0] = 1;
    }

    static int y;
    static int x;
    static pair<int, int> prev = make_pair(-1, -1);
    if (prev != make_pair(w, d)) {
      for (int j = 0; j < w; ++j) {
        if (sqrt(0 + j * j) <= d) y = j;
        else break;
        if (sqrt(1 + j * j) <= d) x = j;
      }
      prev = make_pair(w, d);
    }
    for (int j = 0; j < w; ++j) {
      if (g[0][j] != 'X') continue;
      for (int k = max(0, j - y); k <= min(j + y, w + 1); ++k) {
        if (j != k && g[0][k] == 'X') dp[0][k][1] += dp[0][j][0];
      }
    }

    a.resize(w);
    b.resize(w);
    {
      for (int j = 0; j < w; ++j) {
        a[j] = dp[0][j][0];
        b[j] = dp[0][j][1];
      }
      sum[0].rebuild(a);
      sum[1].rebuild(b);
    }

    for (int i = 1; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        a[j] = 0;
        if (g[i][j] == '#') continue;
        const int begin = max(j - x, 0);
        const int end = min(j + x + 1, w);
        a[j] = dp[i][j][0] = (sum[0](begin, end) + sum[1](begin, end)) % mod;
      }

      sum[0].rebuild(a);
      for (int j = 0; j < w; ++j) {
        b[j] = 0;
        if (g[i][j] == '#') continue;
        const int begin = max(j - y, 0);
        const int end = min(j + y + 1, w);
        b[j] = dp[i][j][1] = (sum[0](begin, end) - dp[i][j][0] + mod) % mod;
      }
      sum[1].rebuild(b);
    }

    const lli z = (sum[0](0, w) + sum[1](0, w)) % mod;
    // cout << z << "\n";
    printf("%lld\n", z);
  }
  return 0;
}
