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
  int n, m;
  while (cin >> n >> m) {
    vector<pair<int, int>> v;
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      v.push_back(make_pair(a, b));
    }

    const int N = 100000 + 10;
    bool  p[N];
    double q[N];
    fill(p, p + N, 0);
    fill(q, q + N, 1);
    p[1] = 1;

    each (i, v) {
      const int x = i.first;
      const int y = i.second;

      if (q[x] == 1) {
        p[y] |= p[x];
        p[x] = 0;
      } else {
        p[y] |= p[x];
      }
      --q[x];
      ++q[y];
    }

    // for (int i = 0; i <= n; ++i) {
    //   cout << i << ":" << p[i] << endl;
    // }
    
    int cnt = 0;
    for (int i = 0; i < N; ++i) {
      if (p[i]) ++cnt;
    }
    cout << cnt << endl;
  }
  return 0;
}
