// github.com/Johniel/contests
// codeforces/938div3/F/main.cpp

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

__attribute__((constructor)) static void _____(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

// constexpr lli mod = 1e9 + 7;
constexpr lli mod = 998244353;

const int N = 200 + 3;
lli dp[N][N][N];
lli z[N][N][N];

int main(int argc, char *Argv[])
{
  fill(&dp[0][0][0], &dp[N - 1][N - 1][N - 1] + 1, 0);
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      for (int k = 0; k < N; ++k) {
        if (i) setmax(dp[i][j][k], dp[i - 1][j][k] + (i % 2 == j % 2 && j % 2 == k % 2));
        if (j) setmax(dp[i][j][k], dp[i][j - 1][k] + (i % 2 == j % 2 && j % 2 == k % 2));
        if (k) setmax(dp[i][j][k], dp[i][j][k - 1] + (i % 2 == j % 2 && j % 2 == k % 2));
      }
    }
  }
  fill(&z[0][0][0], &z[N - 1][N - 1][N - 1] + 1, 0);
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      for (int k = 0; k < N; ++k) {
        z[i][j][k] = dp[i][j][k];
        if (i) setmax(z[i][j][k], dp[i - 1][j][k]);
        if (j) setmax(z[i][j][k], dp[i][j - 1][k]);
        if (k) setmax(z[i][j][k], dp[i][j][k - 1]);
      }
    }
  }

  // cout << dp[1][1][1] << endl;
  // cout << z[1][1][1] << endl;
  // cout << dp[2][0][0] << endl;

  { int _; cin >> _; }
  vec<int> a(4);
  while (cin >> a) {
    lli w = dp[a[0]][a[1]][a[2]];
    // cout << endl;
    // cout << a << endl;
    // cout << w << '*' << (a[3] + 1) << endl;

    if (w == 0) cout << a[3]/2 << endl;
    else cout << w + (a[3] / 2) << endl;
  }
  return 0;
}
