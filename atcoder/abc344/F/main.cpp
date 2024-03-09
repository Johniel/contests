// github.com/Johniel/contests
// atcoder/abc344/F/main.cpp

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

int main(int argc, char *argv[])
{
  int n;
  while (cin >> n) {
    const int N = 80 + 3;
    static int gain[N][N];
    static int right[N][N];
    static int down[N][N];
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> gain[i][j];
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n - 1; ++j) {
        cin >> right[i][j];
      }
    }
    for (int i = 0; i < n - 1; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> down[i][j];
      }
    }
    vec<int> v;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        v.push_back(gain[i][j]);
      }
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    map<int, int> ord;
    for (int i = 0; i < v.size(); ++i) {
      ord[v[i]] = i;
    }

    const int M = N * N;
    static pair<lli, lli> dp[N][N][M]; // {回数、所持金}
    const lli inf = 1LL << 60;
    const pair<lli, lli> nil = make_pair(inf, inf);
    fill(&dp[0][0][0], &dp[N - 1][N - 1][M - 1], nil);
    dp[0][0][ord[gain[0][0]]] = make_pair(0, 0);

    auto better = [] (pair<lli, lli> a, pair<lli, lli> b) {
      if (a.first == b.first) {
        if (a.second > b.second) return a;
        return b;
      }
      if (a.first < b.first) return a;
      return b;
    };

    // cout << v << endl;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        for (int k = 0; k < v.size(); ++k) {
          if (dp[i][j][k] == nil) continue;
          if (j + 1 < n) { // R
            lli req = max(0LL, right[i][j] - dp[i][j][k].second);
            lli b = v[k];
            lli a = (req + b - 1) / b;
            pair<lli, lli> p = dp[i][j][k];
            p.first += a + 1;
            p.second += a * b;
            p.second -= right[i][j];
            assert(0 <= p.second);
            const int nk = max(k, ord[gain[i][j + 1]]);
            dp[i][j + 1][nk] = better(dp[i][j + 1][nk], p);
          }
          if (i + 1 < n) { // D
            lli req = max(0LL, down[i][j] - dp[i][j][k].second);
            lli b = v[k];
            lli a = (req + b - 1) / b;
            pair<lli, lli> p = dp[i][j][k];
            p.first += a + 1;
            p.second += a * b;
            p.second -= down[i][j];
            assert(0 <= p.second);
            const int nk = max(k, ord[gain[i + 1][j]]);
            dp[i + 1][j][nk] = better(dp[i + 1][j][nk], p);
          }
        }
      }
    }
    lli z = inf;
    for (int i = 0; i < M; ++i) {
      setmin(z, dp[n - 1][n - 1][i].first);
    }
    cout << z << endl;
  }
  return 0;
}
