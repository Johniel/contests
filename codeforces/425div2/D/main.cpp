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

constexpr int NODE = 100000 + 5;
constexpr int DEPTH = log2(NODE) + 1;

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

  int n, q;
  while (cin >> n >> q) {
    vector<int> e[n];
    for (int i = 0; i < n - 1; ++i) {
      int j;
      cin >> j;
      e[i + 1].push_back(j - 1);
      e[j - 1].push_back(i + 1);
    }
    int depth[n];
    function<void(int, int)> rec = [&] (int curr, int prev) {
      each (next, e[curr]) {
        if (next != prev) {
          P[next] = curr;
          depth[next] = depth[curr] + 1;
          rec(next, curr);
        }
      }
      return ;
    };

    const int root = 0;
    depth[root] = 0;
    rec(root, -1);
    P[root] = root;
    LCA(n);

    while (q--) {
      vector<int> v(3);
      each (i, v) { cin >> i; --i; }
      int mx = 0;
      sort(v.begin(), v.end());
      do {
        int x = query(v[0], v[1]);
        int y = query(v[0], v[2]);
        int z = query(v[1], v[2]);

        if (depth[z] > max(depth[x], depth[y])) {
          int w = query(v[0], z);
          mx = max(mx, depth[z] - depth[w] + depth[v[0]] - depth[w] + 1);
        } else {
          mx = max(mx, depth[v[0]] - max(depth[x], depth[y]) + 1);
        }
      } while (next_permutation(v.begin(), v.end()));
      cout << mx << endl;
    }
    cout << endl;
  }

  return 0;
}
