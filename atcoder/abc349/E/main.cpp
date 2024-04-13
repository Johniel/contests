// github.com/Johniel/contests
// atcoder/abc349/E/main.cpp

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

const int N = 3;
lli g[N][N];

map<vec<vec<int>>, lli> memo;
const lli inf = 1LL << 40;
lli rec(vec<vec<int>> x)
{
  int e = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (x[i][j] == 0) ++e;
      else if (x[i][j] == 1) x[i][j] = 2;
      else if (x[i][j] == 2) x[i][j] = 1;
    }
  }
  if (memo.count(x)) return memo[x];
  {
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
        constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
        for (int d = 0; d < 8; ++d) {
          int ai = i + di[d] * 0;
          int bi = i + di[d] * 1;
          int ci = i + di[d] * 2;

          int aj = j + dj[d] * 0;
          int bj = j + dj[d] * 1;
          int cj = j + dj[d] * 2;

          unless (0 <= ci && ci < N) continue;
          unless (0 <= cj && cj < N) continue;
          if (x[ai][aj] == 1 && x[bi][bj] == 1 && x[ci][cj] == 1) return memo[x] = +inf;
          if (x[ai][aj] == 2 && x[bi][bj] == 2 && x[ci][cj] == 2) return memo[x] = -inf;
        }
      }
    }
  }
  if (e == 0) return memo[x] = 0;
  lli mx = -inf;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (x[i][j] == 0) {
        x[i][j] = 1;
        setmax(mx, g[i][j] - rec(x));
        x[i][j] = 0;
      }
    }
  }
  return memo[x] = mx;
}

int main(int argc, char *argv[])
{
  vec<int> v(N*N);
  while (cin >> v) {
    int k = 0;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        g[i][j] = v[k++];
      }
    }
    memo.clear();
    vec<vec<int>> x(N, vec<int>(N, 0));
    lli z = rec(x);
    // cout << z << endl;
    cout << (0 < z ? "Takahashi" : "Aoki") << endl;
  }
  return 0;
}
