// atcoder/arc006/C/main.cpp
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

constexpr lli mod = 1e9 + 7;

struct Edge {
  int src, dst;
  Edge() { src = dst = -1; }
  Edge(int s, int d) : src(s), dst(d) {}
  Edge rev(void) const { return Edge(dst, src); }
};

inline bool operator < (const Edge& a, const Edge& b)
{
  if (a.src != b.src) return a.src < b.src;
  return a.dst < b.dst;
}

inline bool operator == (const Edge& a, const Edge& b)
{
  return a.dst == b.dst && a.src == b.src;
}

inline bool operator != (const Edge& a, const Edge& b)
{
  return !(a == b);
}

inline ostream& operator << (ostream& os, Edge e)
{
  os << make_pair(e.src, e.dst);
  return os;
}

const int N = 100 + 10;
vector<Edge> g[N];

// do not use parallel edge
map<Edge, lli> cap;

void add_edge(int src, int dst, lli c)
{
  Edge a(src, dst);
  Edge b = a.rev();
  g[a.src].push_back(a);
  g[b.src].push_back(b);
  cap[a] += c;
  return ;
}

lli max_flow(int src, int snk)
{
  lli sum = 0;
  while (true) {
    Edge path[N] = {Edge(), };
    set<int> vis({src});
    queue<int> q;
    for (q.push(src); q.size(); q.pop()) {
      each (e, g[q.front()]) {
        if (!vis.count(e.dst) && cap[e]) {
          q.push(e.dst);
          vis.insert(e.dst);
          path[e.dst] = e;
        }
      }
    }
    if (path[snk] == Edge()) {
      break;
    }
    lli mn = 1LL << 60;
    for (Edge e = path[snk]; e != Edge(); e = path[e.src]) {
      mn = min(mn, cap[e]);
    }
    for (Edge e = path[snk]; e != Edge(); e = path[e.src]) {
      cap[e] -= mn;
      cap[e.rev()] += mn;
    }
    sum += mn;
  }

  return sum;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    vector<lli> v(n);
    cin >> v;
    each (i, v) --i;

    const int M = N / 2;

    fill(g, g + N, vector<Edge>());
    cap.clear();
    const int src = N - 1;
    const int snk = N - 2;
    for (int i = 0; i < v.size(); ++i) {
      for (int j = i + 1; j < v.size(); ++j) {
        if (v[i] >= v[j]) add_edge(i, j + M, 1);
      }
    }

    for (int i = 0; i < v.size(); ++i) {
      add_edge(src, i, 1);
      add_edge(i + M, snk, 1);
    }

    cout << n - max_flow(src, snk) << endl;
  }

  return 0;
}
