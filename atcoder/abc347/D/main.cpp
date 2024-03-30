// github.com/Johniel/contests
// atcoder/abc347/D/main.cpp

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

int main(int argc, char *argv[])
{
  int a, b;
  lli c;
  while (cin >> a >> b >> c) {
    const int N = 62;
    // const int N = 10;
    static bool dp[N][N][N];
    fill(&dp[0][0][0], &dp[N - 1][N - 1][N - 1] + 1, false);
    dp[0][0][0] = true;
    static pair<int, int> path[N][N][N];
    fill(&path[0][0][0], &path[N - 1][N - 1][N - 1] + 1, make_pair(-1, -1));
    path[0][0][0] = make_pair(0, 0);
    for (int i = 0; i < N - 1; ++i) {
      for (int x = 0; x <= a; ++x) {
        for (int y = 0; y <= b; ++y) {
          unless (dp[i][x][y]) continue;
          for (lli s = 0; s <= 1; ++s) {
            for (lli t = 0; t <= 1; ++t) {
              if (((s ^ t) << i) == (c & (1LL << i))) {
                if (x + s <= a && y + t <= b) {
                  dp[i + 1][x + s][y + t] = true;
                  path[i + 1][x + s][y + t] = make_pair(s, t);
                }
              }
            }
          }
        }
      }
    }
    unless (dp[N - 1][a][b]) {
      cout << -1 << endl;
      continue;
    }
    int x = a;
    int y = b;
    int i = N - 1;
    lli A = 0;
    lli B = 0;
    while (i) {
      pair<int, int> p = path[i][x][y];
      assert(p != make_pair(-1, -1));
      --i;
      if (p.first) A += (1LL << i);
      if (p.second) B += (1LL << i);
      x -= p.first;
      y -= p.second;
    }
    if (__builtin_popcountll(A) != a) swap(A, B);
    cout << A << ' ' << B << endl;
    assert(__builtin_popcountll(A) == a);
    assert(__builtin_popcountll(B) == b);
    assert(c == (A ^ B));
    assert(x == 0);
    assert(y == 0);
  }
  return 0;
}
