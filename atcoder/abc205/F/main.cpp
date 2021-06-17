// atcoder/abc205/F/main.cpp
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
    cap[a] += c;
    cap[b] = 0;
    flow[a] = flow[b] = 0;
    return ;
  }

  lli run(int src, int snk)
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
      if (path[snk] == E()) {
        break;
      }
      lli mn = 1LL << 60;
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
};
constexpr int N = 500 + 5;
MaxFlow<N> mf;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int h, w, n;
  while (cin >> h >> w >> n) {
    mf.init();
    const int src = N - 1;
    const int snk = N - 2;

    int cnt = 0;
    vec<int> col(w);
    vec<int> row(h);
    vec<int> v1(n);
    vec<int> v2(n);
    for (int i = 0; i < col.size(); ++i) col[i] = cnt++;
    for (int i = 0; i < row.size(); ++i) row[i] = cnt++;
    for (int i = 0; i < v1.size(); ++i) v1[i] = cnt++;
    for (int i = 0; i < v2.size(); ++i) v2[i] = cnt++;

    for (int i = 0; i < h; ++i) {
      mf.add_edge(src, row[i], 1);
    }
    for (int j = 0; j < w; ++j) {
      mf.add_edge(col[j], snk, 1);
    }
    for (int i = 0; i < n; ++i) {
      mf.add_edge(v1[i], v2[i], 1);
    }
    for (int i = 0; i < n; ++i) {
      int a, b, c, d;
      cin >> a >> b >> c >> d;
      --a;
      --b;
      for (int j = a; j < c; ++j) {
        mf.add_edge(row[j], v1[i], 1);
      }
      for (int j = b; j < d; ++j) {
        mf.add_edge(v2[i], col[j], 1);
      }
    }
    cout << mf.run(src, snk) << endl;
  }

  return 0;
}
