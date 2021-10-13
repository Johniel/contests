// codeforces/731div3/G/main.cpp
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

namespace {
#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

  constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
  constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
  constexpr lli mod = 1e9 + 7;

  struct Edge{
    int src, dst;
    Edge(int s, int d) : src(s), dst(d) {}
  };
  typedef vector<Edge> Edges;
  typedef vector<Edges> Graph;

  void visit(const Graph &G, int n, int order[], int &time, bool visited[])
  {
    visited[n] = true;
    FOR(e, G[n]){
      if(!visited[e->dst])
        visit(G, e->dst, order, time, visited);
    }
      order[--time] = n;
    return ;
  }

  vector< vector<int> > detectSCC(const Graph &G)
  {
    const int size = G.size();
    bool visited[size];
    int order[size], scc[size], time, prev = size - 1;
    vector< vector<int> > S;
    Graph H(size);
    fill(order, order + size, -1);
    fill(scc, scc + size, -1);
    REP(i, size){
      FOR(e, G[i])
        H[e->dst].push_back(Edge(e->dst, e->src));
    }
    time = size;
    fill(visited, visited + size, false);
    REP(i, size){
      if(!visited[i])
        visit(G, i, order, time, visited);
    }
    time = size;
    fill(visited, visited + size, false);
    REP(i, size){
      if(!visited[order[i]]){
        visit(H, order[i], scc, time, visited);
        int j = prev;
        vector<int> T;
        for(j=prev; 0 <= j && scc[j] != -1; --j)
          T.push_back(scc[j]);
        prev = j;
        S.push_back(T);
      }
    }
    return S;
  }
};

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int _;
  cin >> _;

  int n, m;
  while (cin >> n >> m) {
    Graph g(n);
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[a].push_back(Edge(a, b));
    }

    vec<vec<int>> scc = detectSCC(g);
    set<int> s;
    map<int, int> color;
    for (int i = 0; i < scc.size(); ++i) {
      each (j, scc[i]) color[j] = i;
    }
    for (int i = 0; i < n; ++i) {
      each (e, g[i]) {
        if (color[e.src] == color[e.dst]) {
          s.insert(e.src);
          s.insert(e.dst);
        }
      }
    }

    const int N = 4 * 1e5 + 3;
    static int z[N];
    fill(z, z + N, 0);
    function<void(int)> rec = [&] (int curr) {
      if (z[curr] == 0) z[curr] = 1;
      else if (z[curr] == 1) z[curr] = 2;
      each (e, g[curr]) {
        int next = e.dst;
        if (z[next] == 0 || z[next] == 1) rec(next);
      }
      return ;
    };
    rec(0);
    function<void(int)> rec2 = [&] (int curr) {
      z[curr] = -1;
      each (e, g[curr]) {
        int next = e.dst;
        if (z[next] == 1 || z[next] == 2) rec2(next);
      }
      return ;
    };
    for (int i = 0; i < n; ++i) {
      if ((z[i] == 1 || z[i] == 2) && s.count(i)) rec2(i);
    }
    for (int i = 0; i < n; ++i) {
      cout << z[i] << ' ';
    }
    cout << endl;
  }

  return 0;
}
