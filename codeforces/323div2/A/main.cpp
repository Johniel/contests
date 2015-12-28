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
  while (cin >> n) {
    vector<pair<int, int>> p;
    for (int i = 0; i < n * n; ++i) {
      pair<int, int> a;
      // cin >> a.first >> a.second;
      scanf("%d %d", &a.first, &a.second);
      --a.first;
      --a.second;
      p.push_back(a);
    }
    set<int> vis_h;
    set<int> vis_w;
    vector<int> v;
    for (int k = 0; k < n * n; ++k) {
      for (int d = 0; d < 4; ++d) {
        const int i = p[k].first;
        const int j = p[k].second;
        if (vis_h.count(i) == 0 && vis_w.count(j) == 0) {
          vis_h.insert(i);
          vis_w.insert(j);
          v.push_back(k + 1);
        }
      }
    }
    for (int i = 0; i < v.size(); ++i) {
      if (i) printf(" ");
      printf("%d", v[i]);
    }
    puts("");
  }
  return 0;
}
