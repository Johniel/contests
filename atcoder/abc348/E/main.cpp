// github.com/Johniel/contests
// atcoder/abc348/E/main.cpp

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

#include "atcoder/lazysegtree"
#include "atcoder/modint"

using namespace std;
using namespace atcoder;

using mint = modint998244353;
template<int m> ostream& operator << (ostream& os, static_modint<m> x) { os << x.val(); return os; }
template<int m> ostream& operator << (ostream& os, dynamic_modint<m> x) { os << x.val(); return os; }

using S = pair<lli, lli>; // Ci,dist
using F = lli;
S op(S l, S r) {
  lli sum = l.first + r.first;
  lli d = l.second + r.second;
  return make_pair(sum, d);
}
S e() { return S{0, 0}; }
S mapping(F l, S r) {
  r.first += r.second * l;
  return r;
}
F composition(F l, F r) { return r + l; } // lが後。
F id() { return 0; }

const int N = 1e5 + 3;
vec<int> g[N];
vec<lli> c;

vec<lli> dist;
vec<int> preord;
vec<int> post;
map<int, int> inv;

vec<int> A(N,0);
vec<int> B(N,0);
void rec1(int curr, int prev)
{
  A[curr] = preord.size();
  preord.push_back(curr);
  if (curr) dist[curr] = dist[prev] + 1;
  each (next, g[curr]) {
    if (next == prev) continue;
    rec1(next, curr);
  }
  B[curr] = preord.size();
  post.push_back(curr);
  return ;
}

vec<lli> r;
void rec(int curr, int prev, lazy_segtree<S, op, e, F, mapping, composition, id>& seg)
{
  const int n = dist.size();
  {
    auto p = seg.all_prod();
    r.push_back(p.first);
  }
  each (next, g[curr]) {
    if (next == prev) continue;
    int begin, end;
    begin = inv[next];

    begin = A[next];
    end = B[next];

    seg.apply(0, n, +1);
    seg.apply(begin, end, -2);
    rec(next, curr, seg);
    seg.apply(begin, end, +2);
    seg.apply(0, n, -1);
  }
  return ;
}

int main(int argc, char *argv[])
{
  int n;
  while (cin >> n) {
    fill(g, g + N, vec<int>());
    for (int i = 0; i < n - 1; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    c.resize(n);
    cin >> c;
    dist.resize(n, 0);
    preord.clear();
    inv.clear();
    rec1(0, 0);
    for (int i = 0; i < preord.size(); ++i) {
      inv[preord[i]] = i;
    }
    r.clear();
    vec<S> ini(n);
    for (int i = 0; i < n; ++i) {
      ini[inv[i]] = make_pair(dist[i] * c[i], c[i]);
    }
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(ini);
    rec(0, 0, seg);
    cout << *min_element(r.begin(), r.end()) << endl;
  }
  return 0;
}
