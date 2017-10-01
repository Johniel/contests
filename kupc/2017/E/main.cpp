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

const int N = 100000 + 5;
vector<int> g[N];
set<int> vis;
vector<int> path;

void rec(int curr)
{
  vis.insert(curr);
  path.push_back(curr);
  each (next, g[curr]) {
    if (vis.count(next)) continue;
    rec(next);
  }
  return ;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  while (cin >> n >> m) {
    fill(g, g + N, vector<int>());
    
    vector<lli> v(n);
    each (i, v) cin >> i;

    vector<pair<int, int>> ks(m);
    each (i, ks) {
      int x, y;
      cin >> x >> y;
      --x;
      --y;
      i = make_pair(min(x, y), max(x, y));
    }
    sort(ks.begin(), ks.end());

    each (e, ks) {
      g[e.first].push_back(e.second);
      g[e.second].push_back(e.first);
    }

    lli sum = 0;

    vis.clear();
    for (int i = 0; i < n; ++i) {
      if (vis.count(i) == 0) {
        path.clear();
        rec(i);
        
        int key = 0;
        lli w = 0;
        lli mn = 1LL << 60;
        each (j, path) {
          w += v[j];
          mn = min(mn, v[j]);
          key += g[j].size();
        }
        key /= 2;

        if (key) {
          if (path.size() == 1) {
            sum += w;
          } else if (path.size() <= key) {
            sum += w;
          } else {
            sum += w - mn;
          }
        }
      }
    }

    cout << sum << endl;

  }
  
  return 0;
}
