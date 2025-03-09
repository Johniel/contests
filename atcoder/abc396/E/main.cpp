// github.com/Johniel/contests
// atcoder/abc396/E/main.cpp

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

const int N = 2 * 1e5 + 3;

vec<pair<int, int>> g[N];
int main(int argc, char *argv[])
{
  int n, m;
  while (cin >> n >> m) {
    fill(g, g + N, vec<pair<int, int>>());
    for (int i = 0; i < m; ++i) {
      int x, y, z;
      cin >> x >> y >> z;
      --x;
      --y;
      // --z;
      g[x].push_back(make_pair(y, z));
      g[y].push_back(make_pair(x, z));
    }
    vec<lli> a;
    a.resize(n, 0);
    vec<int> vis(n, 0);
    vec<vec<int>> h;
    for (int i = 0; i < n; ++i) {
      if (vis[i]) continue;
      vis[i] = 1;
      vec<int> u;
      queue<int> q;
      for (q.push(i); q.size(); q.pop()) {
        const int curr = q.front();
        vis[curr] = 1;
        u.push_back(curr);
        each (e, g[curr]) {
          auto [next, z] = e;
          if (!vis[next]) {
            a[next] = a[curr] ^ z;
            q.push(next);
            vis[next] = 1;
          }
        }
      }
      h.push_back(u);
    }
    bool f = true;
    for (int i = 0; i < n; ++i) {
      each (e, g[i]) {
        auto [j, z] = e;
        f = f && (a[i] != -1);
        f = f && (a[i] == (a[j] ^ z));
      }
    }
    if (!f) {
      cout << -1 << endl;
      continue;
    }
    each (v, h) {
      vec<int> f(30, 0);
      each (i, v) {
        for (int j = 0; j < 30; ++j) {
          if (a[i] & (1 << j)) ++f[j];
        }
      }
      for (int j = 0; j < 30; ++j) {
        if ((v.size() + 1) / 2 <= f[j]) {
          each (i, v) a[i] ^= (1 << j);
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      cout << a[i] << ' ';
    }
    cout << endl;
  }
  return 0;
}
