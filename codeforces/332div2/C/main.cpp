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

int main(int argc, char *argv[])
{
  int n;
  while (scanf("%d", &n) == 1) {
    int h[n];
    for (int i = 0; i < n; ++i) scanf("%d", h + i);

    int g[n];
    copy(h, h + n, g);
    sort(g, g + n);
    map<int, vector<int>> idx;
    for (int i = 0; i < n; ++i) {
      idx[g[i]].push_back(i);
    }

    auto fn = [] (pair<int, int> a, pair<int, int> b) {
      if (a.second < b.first) return false;
      if (b.second < a.first) return false;
      return true;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    
    for (int i = 0; i < n; ++i) {
      const int mn = min(i, idx[h[i]].front());
      const int mx = max(i, idx[h[i]].front());
      pair<int, int> p = make_pair(mn, mx);
      q.push(p);
      idx[g[i]].erase(idx[g[i]].begin());
    }

    int cnt = 1;
    while (1 < q.size()) {
      pair<int, int> a = q.top();
      q.pop();
      pair<int, int> b = q.top();
      q.pop();
      if (fn(a, b)) {
        q.push(make_pair(min(a.first, b.first), max(a.second, b.second)));
      } else {
        q.push(b);
        ++cnt;
      }
    }
    printf("%d\n", cnt);
  }
  return 0;
}
