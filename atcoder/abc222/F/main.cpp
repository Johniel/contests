// atcoder/abc222/F/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; for (auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, set<T> s) { os << "#{"; for (auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "{"; for (auto& i: m) os << i << ","; os << "}"; return os; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

using lli = long long int;
using ull = unsigned long long;
using point = complex<double>;
using str = string;
template<typename T> using vec = vector<T>;

#include "atcoder/lazysegtree"
using namespace atcoder;

const lli inf = 1LL << 60;

struct S { lli a; };
struct F { lli m; };
S op(S l, S r) { return S{max(l.a, r.a)}; }
S e() { return S{-inf}; }
S mapping(F l, S r) { return S{r.a + l.m}; }
F composition(F l, F r) { return F{r.m + l.m}; }
F id() { return F{0}; }

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;

const int N = 2 * 1e5 + 3;
vec<pair<int, int>> g[N];
vec<int> d;
const int PRE = 0;
const int POST = 1;
vec<pair<int, int>> occ;
map<pair<int, int>, int> ord;

lli cost0[N];
void rec1(int curr, int prev, lli sum)
{
  occ.push_back(make_pair(PRE, curr));
  cost0[curr] = sum + d[curr];
  each (e, g[curr]) {
    int next = e.first;
    int cost = e.second;
    if (next == prev) continue;
    rec1(next, curr, sum + cost);
  }
  occ.push_back(make_pair(POST, curr));
  return ;
}

lazy_segtree<S, op, e, F, mapping, composition, id> seg;

vec<lli> mx;
int n;
void rec2(int curr, int prev)
{
  pair<int, int> p = make_pair(PRE, curr);
  int nth = ord[p];
  auto tmp = seg.prod(nth, nth + 1);
  seg.set(nth, S{-inf});
  setmax(mx[curr], seg.all_prod().a);
  seg.set(nth, tmp);

  each (e, g[curr]) {
    int next = e.first;
    int cost = e.second;
    if (next == prev) continue;
    pair<int, int> a = make_pair(PRE, next);
    pair<int, int> b = make_pair(POST, next);
    int x = ord[a];
    int y = ord[b];
    int begin = min(x, y);
    int end = max(x, y) + 1;
    seg.apply(0, occ.size(), F{+cost});
    seg.apply(begin, end, F{2 * -cost});
    rec2(next, curr);
    seg.apply(0, occ.size(), F{-cost});
    seg.apply(begin, end, F{2 * +cost});
  }
  return ;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  while (cin >> n) {
    fill(g, g + N, vec<pair<int, int>>());
    for (int i = 0; i < n - 1; ++i) {
      int a, b, c;
      cin >> a >> b >> c;
      --a;
      --b;
      g[a].push_back(make_pair(b, c));
      g[b].push_back(make_pair(a, c));
    }
    d.resize(n);
    cin >> d;

    occ.clear();
    rec1(0, 0, 0);
    for (int i = 0; i < occ.size(); ++i) {
      ord[occ[i]] = i;
    }

    vec<S> ini(occ.size(), S{-inf});
    each (i, occ) {
      if (i.first == POST) ini[ord[i]] = S{-inf};
      else ini[ord[i]] = S{cost0[i.second]};
    }

    seg = lazy_segtree<S, op, e, F, mapping, composition, id>(ini);
    mx = vec<lli>(n, -inf);
    rec2(0, 0);
    each (i, mx) cout << i << endl;
  }

  return 0;
}
