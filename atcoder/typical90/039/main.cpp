// atcoder/typical90/039/main.cpp
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

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;

#include "atcoder/lazysegtree"
#include "atcoder/modint"

using namespace std;
using namespace atcoder;

struct S {
  lli value;
  int size;
};
struct F {
  lli added;
};
S op(S a, S b) { return S{a.value + b.value, a.size + b.size}; }
S e() { return S{0, 0}; }
S mapping(F f, S s) { return S{s.value + f.added * s.size, s.size}; }
F composition(F a, F b) { return F{a.added + b.added}; }
F id() { return F{0}; }

const int N = 1e5 + 3;
vec<int> g[N];

int cost[N];
int cnt;
int preord[N];
int postord[N];
void rec1(int curr, int prev)
{
  preord[curr] = cnt++;
  if (curr == 0) {
    cost[curr] = 0;
  } else {
    cost[curr] = cost[prev] + 1;
  }
  each (next, g[curr]) {
    unless (next == prev) rec1(next, curr);
  }
  postord[curr] = cnt;
  return ;
}

lazy_segtree<S, op, e, F, mapping, composition, id> seg;
int n;
lli rec2(int curr, int prev)
{
  lli z = seg.all_prod().value;
  each (next, g[curr]) {
    if (next == prev) continue;
    seg.apply(0, preord[next], F{+1});
    seg.apply(preord[next], postord[next], F{-1});
    seg.apply(postord[next], n, F{+1});
    z += rec2(next, curr);
    seg.apply(0, preord[next], F{-1});
    seg.apply(preord[next], postord[next], F{+1});
    seg.apply(postord[next], n, F{-1});
  }
  return z;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

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
    cnt = 0;
    rec1(0, 0);

    vec<S> ini(n, S{0});
    for (int i = 0; i < n; ++i) {
      ini[preord[i]] = S{cost[i], 1};
    }
    seg = lazy_segtree<S, op, e, F, mapping, composition, id>(ini);
    cout << rec2(0, 0) / 2 << endl;;
  }

  return 0;
}
