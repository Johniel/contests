// github.com/Johniel/contests
// atcoder/abc345/E/main.cpp

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

__attribute__((constructor)) static void ___initio(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

// constexpr lli mod = 1e9 + 7;
constexpr lli mod = 998244353;

const int N = 2 * 1e5 + 3;
const int K = 500 + 3;
const lli inf = (1LL << 60);
const pair<lli, int> P = make_pair(-inf, N);
const array<pair<lli, int>, 2> nil({P, P});

inline pair<lli, int> append(const array<pair<lli, int>, 2>& x, pair<lli, int> p)
{
  pair<lli, int> mx = P;
  each (i, x) {
    if (i.second != p.second) {
      setmax(mx, make_pair(p.first + i.first, p.second));
    }
  }
  return mx;
}

inline array<pair<lli, int>, 2> merge(const array<pair<lli, int>, 2>& x, const pair<lli, int>& a, const pair<lli, int> b = P)
{
  vec<pair<lli, int>> v(4);
  v.shrink_to_fit();
  v[0] = x[0];
  v[1] = x[1];
  v[2] = a;
  v[3] = b;
  sort(v.begin(), v.end());
  array<pair<lli, int>, 2> z;
  z[0] = v[3];
  z[1] = v[2];
  if (z[0].second == z[1].second) z[1] = v[1];
  return z;
}

inline array<pair<lli, int>, 2> merge(const array<pair<lli, int>, 2>& x, const array<pair<lli, int>, 2>& y)
{
  return merge(x, y[0], y[1]);
}

int main(int argc, char *argv[])
{
  int n, rm;
  while (cin >> n >> rm) {
    vec<pair<lli, int>> v(n);
    each (i, v) cin >> i.second >> i.first;
    static array<pair<lli, int>, 2> dp[2][K];
    for (int i = 0; i < K; ++i) {
      dp[0][i] = dp[1][i] = nil;
    }
    dp[0][0][0] = make_pair(0, N);
    for (int i = 0; i < v.size(); ++i) {
      const int curr = i % 2;
      const int next = (i + 1) % 2;
      for (int j = 0; j < K; ++j) {
        dp[next][j] = nil;
      }
      for (int j = 0; j <= rm; ++j) {
        dp[next][j] = merge(dp[next][j], append(dp[curr][j], v[i]));
        dp[next][j + 1] = merge(dp[next][j + 1], dp[curr][j]);
      }
    }
    lli z = max(dp[n%2][rm][0], dp[n%2][rm][1]).first;
    cout << max<lli>(-1, z) << endl;
  }
  return 0;
}
