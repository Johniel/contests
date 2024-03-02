// github.com/Johniel/contests
// atcoder/abc343/E/main.cpp

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

const int N = 200 + 7 + 3;
int g[N][N][N];
int m[4];

inline void fn(int a, int b, int c, int x) {
  for (int i = 0; i < 7; ++i) {
    for (int j = 0; j < 7; ++j) {
      for (int k = 0; k < 7; ++k) {
        int i_ = i + a + N / 2;
        int j_ = j + b + N / 2;
        int k_ = k + c + N / 2;
        --m[g[i_][j_][k_]];
        g[i_][j_][k_] += x;
        ++m[g[i_][j_][k_]];
      }
    }
  }
  return ;
};

int main(int argc, char *argv[])
{
  vec<int> req(3);
  while (cin >> req) {
    req.insert(req.begin(), -1);
    fill(&g[0][0][0], &g[N - 1][N - 1][N - 1] + 1, 0);
    m[0] = m[1] = m[2] = m[3] = 0;
    fn(0, 0, 0, +1);
    const int P = 8;
    const int Q = 8;
    for (int a2 = 0; a2 < +P; ++a2) {
      for (int b2 = 0; b2 < +P; ++b2) {
        for (int c2 = 0; c2 < +P; ++c2) {
          fn(a2, b2, c2, +1);
          bool f = true;
          f = f && (0 <= m[2] - req[3]);
          f = f && (req[2] <= m[2] - req[3] + m[1]);
          f = f && (req[1] <= m[1] + 7*7*7 - (m[2] - req[3]));
          if (f) {
            for (int a3 = 0; a3 < +Q; ++a3) {
              for (int b3 = -Q; b3 < +Q; ++b3) {
                for (int c3 = -Q; c3 < +Q; ++c3) {
                  fn(a3, b3, c3, +1);
                  if (m[1] == req[1] && m[2] == req[2] && m[3] == req[3]) {
                    cout << "Yes" << endl;
                    cout << 0 << ' ' << 0 << ' ' << 0 << ' '
                         << a2 << ' ' << b2 << ' ' << c2 << ' '
                         << a3 << ' ' << b3 << ' ' << c3 << endl;
                    goto E;
                    // exit(0);
                  }
                  fn(a3, b3, c3, -1);
                }
              }
            }
          }
          fn(a2, b2, c2, -1);
        }
      }
    }
    cout << "No" << endl;
    E:
    req.resize(3);
  }
  return 0;
}
