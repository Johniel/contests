// github.com/Johniel/contests
// atcoder/arc015/C/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define each_with_index(i, e, c) for (const auto i: views::iota(0, (int)c.size())) if (auto& e = c.at(i); true)
#define each_pair(p, c) for (const auto _i: views::iota(0, (int)c.size())) if (std::pair<const int, decltype((c.at(_i)))> p = {_i, c[_i]}; true)
#define unless(cond) if (!(cond))
// #define endl "\n"

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p);
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p);
template<typename P, typename Q, typename R> ostream& operator << (ostream& os, tuple<P, Q, R> t) { os << "(" << get<0>(t) << "," << get<1>(t) << "," << get<2>(t) << ")"; return os; }
template<typename P, typename Q, typename R> istream& operator >> (istream& is, tuple<P, Q, R>& t) { is >> get<0>(t) >> get<1>(t) >> get<2>(t); return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; for (auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, set<T> s) { os << "#{"; for (auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "{"; for (auto& i: m) os << i << ","; os << "}"; return os; }
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

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
// constexpr lli mod = 1e9 + 7;
constexpr lli mod = 998244353;

#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>
using bigint = boost::multiprecision::cpp_int;

int main(int argc, char *argv[])
{
  int n;
  while (cin >> n) {
    str dst[n];
    lli a[n];
    str src[n];
    for (int i = 0; i < n; ++i) {
      cin >> dst[i] >> a[i] >> src[i];
    }
    map<str, int> label;
    for (int i = 0; i < n; ++i) {
      unless (label.count(dst[i])) label[dst[i]] = label.size();
      unless (label.count(src[i])) label[src[i]] = label.size();
    }
    map<int, str> inv;
    each (i, label) inv[i.second] = i.first;
    const int M = label.size();

    vec<vec<double>> g(M, vec<double>(M, -1));
    for (int i = 0; i < n; ++i) {
      int x = label[src[i]];
      int y = label[dst[i]];
      g[y][x] = a[i];
      g[x][y] = 1.0 / a[i];
    }

    for (int k = 0; k < M; ++k) {
      for (int i = 0; i < M; ++i) {
        for (int j = 0; j < M; ++j) {
          if (g[i][k] < 0 || g[k][j] < 0 || 0 <= g[i][j]) continue;
          g[i][j] = g[i][k] * g[k][j];
        }
      }
    }
    int SRC, DST;
    double mx = 0;
    for (int i = 0; i < M; ++i) {
      for (int j = 0; j < M; ++j) {
        if (mx < g[i][j]) {
          mx = g[i][j];
          SRC = i;
          DST = j;
        }
      }
    }
    cout << 1 << inv[SRC] << '=' << (lli)(g[SRC][DST] + 1e-6) << inv[DST] << endl;
  }
  return 0;
}
