#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

template<typename P, typename Q>
ostream& operator << (ostream& os, pair<P, Q> p)
{
  os << "(" << p.first << "," << p.second << ")";
  return os;
}

template<typename T>
ostream& operator << (ostream& os, vector<T> v)
{
  os << "(";
  each (i, v) os << i << ",";
  os << ")";
  return os;
}

struct Edge {
  int src, dst;
  Edge() { src = dst = -1; }
  Edge(int s, int d) : src(s), dst(d) {}
  Edge rev(void) const { return Edge(dst, src); }
};

inline
bool operator < (const Edge& a, const Edge& b)
{
  if (a.src != b.src) return a.src < b.src;
  return a.dst < b.dst;
}

inline
bool operator == (const Edge& a, const Edge& b)
{
  return a.dst == b.dst && a.src == b.src;
}

inline
bool operator != (const Edge& a, const Edge& b)
{
  return !(a == b);
}

inline
ostream& operator << (ostream& os, Edge e)
{
  os << make_pair(e.src, e.dst);
  return os;
}

const int N = 100 + 10;
vector<Edge> g[N];

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
    cap.clear();
    fill(g, g + N, vector<Edge>());

    vector<lli> a(n);
    each (i, a) cin >> i;

    const int src = N - 1;
    const int snk = N - 2;
    const lli inf = 1LL << 60;

    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if ((j + 1) % (i + 1) == 0) {
          add_edge(i, j, inf);
        }
      }
    }

    for (int i = 0; i < n; ++i) {
      if (0 <= a[i]) {
        add_edge(i, snk, a[i]);
      } else {
        add_edge(src, i, -a[i]);
      }
    }

    lli sum = 0;
    each (i, a) sum += (0 < i) * i;
    cout << sum - max_flow(src, snk) << endl;
  }

  return 0;
}

