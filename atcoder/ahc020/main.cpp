// github.com/Johniel/contests
// atcoder/ahc020/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
// #define endl "\n"

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; for (auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, set<T> s) { os << "#{"; for (auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "{"; for (auto& i: m) os << i << ","; os << "}"; return os; }
template<typename E, size_t N> istream& operator >> (istream& is, array<E, N>& a) { for (auto& i: a) is >> i; return is; }
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[" << N << "]{"; for (auto& i: a) os << i << ","; os << "}"; return os; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

__attribute__((constructor)) static void ___initio(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});

namespace math {
  lli isqrt(lli x){
    lli sqrtx = sqrt(x) - 1;
    while (sqrtx + 1 <= x / (sqrtx + 1)) {
      sqrtx++;
    }
    return sqrtx;
  }
}


struct UnionFind {
  vector<int> r, p;
  UnionFind(int n) {
    r.resize(n, 0);
    p.resize(n, -1);
  }
  void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return ;
    if (r[a] > r[b]) {
      p[a] += p[b];
      p[b] = a;
    } else {
      p[b] += p[a];
      p[a] = b;
      if (r[a] == r[b]) ++r[b];
    }
    return ;
  }
  int find(int a) {
    return (p[a] < 0) ? a : p[a] = find(p[a]);
  }
  bool same(int a, int b) {
    return find(a) == find(b);
  }
  size_t size(int n) {
    return -p.at(find(n));
  }
};

vec<pair<lli, lli>> baseStation;
vec<pair<lli, lli>> citizens;

using Edge = pair<int, int>;
Edge newEdge(int x, int y)
{
  return make_pair(min(x, y), max(x, y));
}

struct Cable {
  int x, y;
  lli cost;
  Edge edge(void) const { return make_pair(x, y); }
  Edge redge(void) const { return make_pair(y, x); }
};
istream& operator >> (istream& is, Cable& c)
{
  is >> c.x >> c.y >> c.cost;
  --c.x;
  --c.y;
  unless (c.x < c.y) swap(c.x, c.y);
  return is;
}
ostream& operator << (ostream& os, Cable& c)
{
  os << "Cable{" << c.edge() << c.cost << "}";
  return os;
}
vec<Cable> cables;

lli dist(pair<lli, lli> a, pair<lli, lli> b)
{
  lli x = (a.first - b.first);
  lli y = (a.second - b.second);
  x *= x;
  y *= y;
  // return round(sqrt(x + y));
  return ceil(sqrt(x + y));
}

const int N = 100;
const int M = 300;
const int K = 5000;

struct Result {
  lli cost;
  vec<int> b;
  vec<lli> p;
  Result better(Result other) {
    if (cost < other.cost) return *this;
    return other;
  }
  void show(void) const {
    each (i, p) cout << i << ' '; cout << endl;
    cout << endl;
    each (i, b) cout << i << ' '; cout << endl;
  }
};


Result solve02(const int n, const int m, const int c, const str BS)
{
  lli s = 0;

  map<pair<int, int>, int> edgeNo;
  static lli mn[N];
  fill(mn, mn + N, 1LL << 61);
  for (int i = 0; i < cables.size(); ++i) {
    edgeNo[cables[i].edge()] = i;
    edgeNo[cables[i].redge()] = i;

    setmin(mn[cables[i].x], cables[i].cost);
    setmin(mn[cables[i].y], cables[i].cost);
  }

  vec<int> b(m, 0);
  vec<lli> p(n, 0);
  static lli bestDist[K];
  static int bestBaseStation[K];
  fill(bestBaseStation, bestBaseStation + K, -1);
  for (int i = 0; i < c; ++i) {
    for (int j = 0; j < n; ++j) {
      if (BS[j] == '0') continue;
      lli d = dist(baseStation[j], citizens[i]);
      unless (d <= 5000) continue;
      if (bestBaseStation[i] == -1 || d < bestDist[i]) {
        bestDist[i] = d;
        bestBaseStation[i] = j;
      }
    }
  }
  vec<pair<int, lli>> v;
  for (int i = 0; i < c; ++i) {
    v.push_back(make_pair(bestBaseStation[i], bestDist[i]));
  }
  sort(v.begin(), v.end(), [&] (auto a, auto b) {
    // return a.second < b.second;
    return (a.second * a.second) + mn[a.first] < (b.second * b.second) + mn[b.first];
  });
  reverse(v.begin(), v.end());
  static bool reached[K];
  fill(reached, reached + K, false);
  set<int> u;
  {
    set<int> vis;
    each (i, v) {
      const int st = i.first;
      const lli d = i.second;
      lli x = 0;
      if (vis.count(st)) continue; vis.insert(st);
      int r = 0;
      for (int j = 0; j < c; ++j) {
        if (reached[j]) continue;
        lli req = dist(baseStation[st], citizens[j]);
        if (req <= d) {
          setmax(x, req);
          ++r;
          reached[j] = true;
          //u.push_back(j);
          u.insert(j);
        }
      }
      if (r) {
        s += x * x;
        setmax(p[st], x);
        // p[st] = x;
        // cout << u << endl;
      }
    }
  }
  // cout << u.size() << ' ' << c << endl;
  assert(u.size() == c);
  assert(count(reached, reached + c, 0) == 0);

  static int path[N];
  fill(path, path + N, -1);
  static bool pop[N];
  fill(pop, pop + N, false);

  vec<pair<int, lli>> g[N];
  each (e, cables) {
    g[e.x].push_back(make_pair(e.y, e.cost));
    g[e.y].push_back(make_pair(e.x, e.cost));
  }
  priority_queue<pair<double, int>> q;
  for (q.push(make_pair(0, 0)); q.size(); ) {
    pair<double, int> p = q.top();
    q.pop();
    const double cost = abs(p.first);
    const int curr = p.second;
    if (pop[curr]) continue;
    pop[curr] = true;
    each (e, g[curr]) {
      const double c = e.second;
      const int next = e.first;
      if (path[next] == -1) {
        q.push(make_pair(-c, next));
        path[next] = curr;
      }
    }
  }

  {
    static bool vis[N];
    fill(vis, vis + N, false);
    vis[0] = true;
    for (int i = 0; i < n; ++i) {
      if (p[i] == 0) continue;
      int curr = i;
      while (path[curr] != curr) {
        if (vis[curr]) break;
        vis[curr] = true;
        int j = edgeNo[make_pair(path[curr], curr)];
        b[j] = 1;
        s += cables[j].cost;
        curr = path[curr];
      }
    }
  }

  Result r;
  r.cost = s;
  r.p = p;
  r.b = b;
  return r;
}

uint32_t xorshift(void)
{
  // https://shindannin.hatenadiary.com/entry/2021/03/06/115415
  static uint32_t x = 123456789;
  static uint32_t y = 362436069;
  static uint32_t z = 521288629;
  static uint32_t w = 88675123;
  uint32_t t;

  t = x ^ (x << 11);
  x = y; y = z; z = w;
  return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
}

void solve03(const int n, const int m, const int c)
{
  str s(n, '1');
  Result b = solve02(n, m, c, s);
  vec<lli> v(n);
  v[0] = b.cost;
  for (int i = 1; i < s.size(); ++i) {
    s[i] = '0';
    Result r = solve02(n, m, c, s);
    s[i] = '1';
    v[i] = r.cost;
    b = b.better(r);
  }
  vec<int> idx(v.size());
  iota(idx.begin(), idx.end(), 0);
  sort(idx.begin(), idx.end(), [&] (auto i, auto j) { return v[i] < v[j]; });
  if (2 <= v.size() && v[0] == 0 || v[1] == 0) {
    s[v[0]] = s[v[1]] = '0';
    Result r = solve02(n, m, c, s);
    s[v[0]] = s[v[1]] = '1';
    b = b.better(r);
  }
  b.show();
  return ;
}

int main(int argc, char *argv[])
{
  int n, m, k;
  while (cin >> n >> m >> k) {
    baseStation.resize(n);
    cables.resize(m);
    citizens.resize(k);
    cin >> baseStation >> cables >> citizens;
    solve03(n, m, k);
  }
  return 0;
}
