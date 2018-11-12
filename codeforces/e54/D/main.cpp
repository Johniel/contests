#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; each (i, v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { each (i, v) is >> i; return is; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

struct E {
  int src, dst;
  lli cost;
};

const int N = 3 * 1e5 + 10;
vector<E> g[N];
vector<int> h[N];
lli cost[N];
bool vis[N];
const lli inf = 1LL << 60;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m, k;
  while (cin >> n >> m >> k) {
    fill(g, g + N, vector<E>());
    fill(h, h + N, vector<int>());
    fill(cost, cost + N, inf);
    fill(vis, vis + N, false);

    map<pair<int, int>, int> name;
    map<int, pair<int, int>> es;

    for (int i = 0; i < m; ++i) {
      int a, b, c;
      cin >> a >> b >> c;
      --a;
      --b;
      g[a].push_back(E{a, b, c});
      g[b].push_back(E{b, a, c});

      pair<int, int> x = make_pair(a, b);
      pair<int, int> y = make_pair(b, a);
      name[x] = name[y] =  i;
      es[i] = x;
    }

    priority_queue<pair<int, pair<int, int>>> q;
    cost[0] = 0;
    vis[0] = true;
    q.push(make_pair(0, make_pair(0, -1)));
    
    while (q.size()) {
      pair<int, pair<int, int>> p = q.top();
      q.pop();
      int C = -1 * p.first;
      int curr = p.second.first;
      int no = p.second.second;
      if (cost[curr] != C) continue;
      if (!vis[curr]) {
        pair<int, int> e = es[no];
        h[e.first].push_back(e.second);
        h[e.second].push_back(e.first);
        vis[curr] = true;
        // cout << make_pair(e.first + 1, e.second + 1) << endl;
      }
      each (e, g[curr]) {
        if (cost[e.dst] > cost[e.src] + e.cost) {
          cost[e.dst] = cost[e.src] + e.cost;
          pair<int, int> key = make_pair(e.src, e.dst);
          q.push(make_pair(-cost[e.dst], make_pair(e.dst, name[key])));
        }
      }
    }

    vector<int> u;
    {
      set<int> visited;
      visited.insert(0);
      queue<int> q;
      for (q.push(0); q.size(); q.pop()) {
        int curr = q.front();
        each (next, h[curr]) {
          if (visited.count(next)) continue;
          q.push(next);
          visited.insert(next);
          pair<int, int> key = make_pair(curr, next);
          u.push_back(name[key]);
        }
      }
    }
    // cout << "u: " << u << endl;
    while (k < u.size()) u.pop_back();
    cout << u.size() << endl;
    each (i, u) cout << i + 1 << ' '; cout << endl;
  }
  
  return 0;
}
