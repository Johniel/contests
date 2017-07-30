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
  ios_base::sync_with_stdio(0);
  cin.tie(0);


  int n, m;
  while (cin >> n >> m) {
    set<int> x, y;
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      if (a == 1) x.insert(b);
      if (b == n) y.insert(a);
    }
    bool f = false;
    for (int i = 1; i <= n; ++i) {
      f = f || (x.count(i) && y.count(i));
    }
    cout << (f ? "POSSIBLE" : "IMPOSSIBLE") << endl;
  }
  return 0;
}
