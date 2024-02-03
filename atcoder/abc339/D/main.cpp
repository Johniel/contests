// github.com/Johniel/contests
// atcoder/abc339/D/main.cpp

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

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
// constexpr lli mod = 1e9 + 7;
constexpr lli mod = 998244353;

const int N = 60 + 3;
char g[N][N];
int m[N][N][N][N];
inline int& read(pair<int, int> a, pair<int, int> b) {
  return m[a.first][a.second][b.first][b.second];
}
using ppii = pair<pair<int, int>, pair<int, int>>;
inline int& read(ppii p) {
  auto [a, b] = p;
  return m[a.first][a.second][b.first][b.second];
}
const int inf = 1 << 29;
int main(int argc, char *argv[])
{
  int n;
  while (cin >> n) {
    pair<int, int> a, b;
    a = make_pair(-1, -1);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> g[i][j];
        if (g[i][j] == 'P') {
          g[i][j] = '.';
          if (a.first == -1) a = make_pair(i, j);
          else b = make_pair(i, j);
        }
      }
    }
    fill(&m[0][0][0][0], &m[N - 1][N - 1][N - 1][N - 1] + 1, inf);
    queue<ppii> q;
    int z = inf;
    unless (a < b) swap(a, b);
    ppii ini = make_pair(a, b);
    read(ini) = 0;
    bool f = false;
    for (q.push(ini); q.size(); q.pop()) {
      auto curr = q.front();
      const auto [a, b] = curr;
      assert(read(curr) < inf);
      if (a == b) break;
      for (int d = 0; d < 4; ++d) {
        vec<pair<int, int>> v;
        v.push_back(a);
        v.push_back(b);
        each (p, v) {
          int ni = p.first + di[d];
          int nj = p.second + dj[d];
          unless (0 <= ni && ni < n) continue;
          unless (0 <= nj && nj < n) continue;
          if (g[ni][nj] == '.') p = make_pair(ni, nj);
        }
        auto next = make_pair(v[0], v[1]);
        unless (v[0] < v[1]) swap(v[0], v[1]);
        if (read(next) == inf) {
          read(next) = read(curr) + 1;
          if (next.first == next.second) {
            z = read(next);
            break;
          }
          q.push(next);
        }
      }
      if (z != inf) break;
    }
    if (z == inf) cout << -1 << endl;
    else cout << z << endl;
  }
  return 0;
}
