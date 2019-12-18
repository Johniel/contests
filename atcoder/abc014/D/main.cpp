// atcoder/abc014/D/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

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

const int N = 1e5 + 5;
vector<int> g[N];

const int NODE = N;
const int DEPTH = (int)(log((double)NODE) / log(2.0) + 1.0);
// const int DEPTH = 18;

// T: dp table
// P: parent,first ancestor
// L: level, depth
int T[NODE][DEPTH], P[NODE], L[NODE];

int addLevel(int node)
{
  if (L[node] != -1) return L[node];
  else return L[node] = addLevel(P[node]) + 1;
}

// ! keep P[root] = root
void LCA(const int &node)
{
  const int root = 0;
  fill(L, L + node, -1);
  L[root] = 0;
  for (int i = 0; i < node; ++i) {
    L[i] = addLevel(i);
  }

  fill(&T[0][0], &T[NODE - 1][DEPTH], -1);
  for (int i = 0; i < node; ++i) {
    T[i][0] = P[i];
  }
  for(int j = 1; (1 << j) < node; ++j){
    for (int i = 0; i < node; ++i) {
      if (T[i][j - 1] != -1) {
        T[i][j] = T[T[i][j - 1]][j - 1];
      }
    }
  }

  return ;
}

int query(int a, int b)
{
  if (L[a] < L[b]) swap(a, b);

  int lg = 1;
  while ((1 << lg) <= L[a]) ++lg;
  --lg;

  for (int i = lg; 0 <= i; --i) {
    if (L[a] - (1 << i) >= L[b]) {
      a = T[a][i];
    }
  }

  if (a == b) return a;
  for (int i = lg; 0 <= i; --i) {
    if (T[a][i] != -1 && T[a][i] != T[b][i]) {
      a = T[a][i];
      b = T[b][i];
    }
  }

  return P[a];
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    fill(g, g + N, vector<int>());
    for (int i = 0; i < n - 1; ++i) {
      int x, y;
      cin >> x >> y;
      --x;
      --y;
      g[x].push_back(y);
      g[y].push_back(x);
    }

    static int cost[N];
    cost[0] = 0;
    set<int> vis;
    function<void(int, int)> rec = [&] (int curr, int prev) {
      P[curr] = prev;
      if (curr) cost[curr] = cost[prev] + 1;
      vis.insert(curr);
      each (next, g[curr]) {
        if (vis.count(next)) continue;
        rec(next, curr);
      }
      return ;
    };
    rec(0, 0);
    LCA(n);

    int q;
    cin >> q;
    while (q--) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      int c = query(a, b);
      // cout << a + 1 << ' ' << b + 1 << ' ' << c + 1 << ' ' << cost[a] << ' ' << cost[b] << ' ' << cost[c] << endl;
      cout << cost[a] + cost[b] - cost[c] * 2 + 1 << endl;
    }
    // cout << endl;
  }

  return 0;
}
