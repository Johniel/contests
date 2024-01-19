// github.com/Johniel/contests
// codeforces/859div4/F/main.cpp

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

int main(int argc, char *argv[])
{
  { int _; cin >> _; }
  int h, w, i1, j1, i2, j2;
  str d;
  while (cin >> h >> w >> i1 >> j1 >> i2 >> j2 >> d) {
    --i1;
    --j1;
    --i2;
    --j2;
    const int di[] = {+1, -1, +1, -1};
    const int dj[] = {-1, -1, +1, +1};
    map<str, int> dir;
    dir["DL"] = 0;
    dir["UL"] = 1;
    dir["DR"] = 2;
    dir["UR"] = 3;
    map<tuple<int, int, int>, int> cost;
    tuple<int, int, int> src = make_tuple(i1, j1, dir[d]);
    cost[src] = 0;
    deque<tuple<int, int, int>> q;
    for (q.push_back(src); q.size(); ) {
      const auto curr = q.front();
      q.pop_front();
      const auto [i, j, d] = curr;
      int nd = d;
      {
        int ni = i + di[nd];
        int nj = j + dj[nd];
        unless (0 <= ni) nd ^= (1 << 0);
        unless (ni < h) nd ^= (1 << 0);
        unless (0 <= nj) nd ^= (1 << 1);
        unless (nj < w) nd ^= (1 << 1);
      }
      nd %= 4;
      int ni = i + di[nd];
      int nj = j + dj[nd];
      unless (0 <= ni && ni < h) continue;
      unless (0 <= nj && nj < w) continue;
      auto next = make_tuple(ni, nj, nd);
      if (cost.count(next)) continue;
      cost[next] = cost[curr] + (nd != d);
      if (nd == d) q.push_front(next);
      else q.push_back(next);
    }
    int z = 1 << 29;
    bool found = false;
    for (int d = 0; d < 4; ++d) {
      auto t = make_tuple(i2, j2, d);
      if (cost.count(t)) {
        found = true;
        setmin(z, cost[t]);
      }
    }
    if (found) cout << z << endl;
    else cout << -1 << endl;
  }
  return 0;
}
