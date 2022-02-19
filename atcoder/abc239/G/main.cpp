// atcoder/abc239/G/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
//#define endl "\n"

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

struct E {
  int src, dst;
  E() { src = dst = -1; }
  E(int s, int d) : src(s), dst(d) {}
  E rev(void) const { return E(dst, src); }
};

inline bool operator < (const E& a, const E& b)
{
  if (a.src != b.src) return a.src < b.src;
  return a.dst < b.dst;
}

inline bool operator == (const E& a, const E& b) { return a.dst == b.dst && a.src == b.src; }
inline bool operator != (const E& a, const E& b) { return !(a == b); }

template<int N>
struct MaxFlow {
  array<vector<E>, N> g;
  // MEMO: do not use parallel edge
  map<E, lli> cap;
  map<E, lli> flow;
  void init(void)
  {
    fill(g.begin(), g.end(), vector<E>());
    cap.clear();
    flow.clear();
    return ;
  }

  void add_edge(int src, int dst, lli c)
  {
    E a(src, dst);
    E b = a.rev();
    g[a.src].push_back(a);
    g[b.src].push_back(b);
    cap[a] = c;
    cap[b] = 0;
    flow[a] = flow[b] = 0;
    return ;
  }

  lli run(const int src, const int snk)
  {
    lli sum = 0;
    while (true) {
      E path[N] = {E(), };
      set<int> vis({src});
      queue<int> q;
      for (q.push(src); q.size(); q.pop()) {
        each (e, g[q.front()]) {
          if (!vis.count(e.dst) && 0 < cap[e] - flow[e]) {
            q.push(e.dst);
            vis.insert(e.dst);
            path[e.dst] = e;
          }
        }
      }
      if (!vis.count(snk)) break;
      lli mn = (1LL << 60) + 5;
      for (E e = path[snk]; e != E(); e = path[e.src]) {
        mn = min(mn, cap[e] - flow[e]);
      }
      for (E e = path[snk]; e != E(); e = path[e.src]) {
        flow[e] += mn;
        flow[e.rev()] -= mn;
      }
      sum += mn;
    }

    return sum;
  }

  pair<lli, vec<E>> min_cut(int src, int snk)
  {
    lli f = run(src, snk);
    queue<int> q;
    set<int> vis({src});
    for (q.push(src); q.size(); q.pop()) {
      const int curr = q.front();
      each (e, g[curr]) {
        if (!vis.count(e.dst) && 0 < cap[e] - flow[e]) {
          q.push(e.dst);
          vis.insert(e.dst);
        }
      }
    }
    vec<E> es;
    for (int i = 0; i < N; ++i) {
      each (e, g[i]) {
        if (vis.count(e.src) && !vis.count(e.dst) && cap[e] && cap[e] == flow[e]) {
          es.push_back(e);
        }
      }
    }
    return make_pair(f, es);
  }
};

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n, m;
  while (cin >> n >> m) {
    vec<pair<int, int>> v;
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      v.push_back({a - 1, b - 1});
    }

    for (int i = 0; i < m; ++i) {
      for (int j = i+1; j < m; ++j) {
        assert(v[i] != v[j]);
      }
    }

    vec<int> c(n);
    cin >> c;

    int in[n];
    int out[n];
    int cnt = 0;
    map<int, int> rev;
    for (int i = 0; i < n; ++i) {
      in[i] = cnt++;
      out[i] = cnt++;
      rev[in[i]] = i;
    }
    const lli inf = 1LL << 50;

    MaxFlow<300> g;
    for (int i = 0; i < n; ++i) {
      g.add_edge(in[i], out[i], (c[i] ? c[i] : inf));
    }
    each (e, v) {
      g.add_edge(out[e.first], in[e.second], inf);
      g.add_edge(out[e.second], in[e.first], inf);
    }
    pair<lli, vec<E>> cut = g.min_cut(in[0], out[n - 1]);
    cout << cut.first << endl;
    cout << cut.second.size() << endl;
    each (e, cut.second) cout << rev[e.src] + 1 << ' ';
    cout << endl;
  }
  return 0;
}
