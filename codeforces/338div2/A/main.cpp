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
  while (scanf("%d%d", &n, &m) == 2) {
    set<int> v;
    for (int i = 0; i < n; ++i) {
      int a;
      scanf("%d", &a);
      for (int j = 0; j < a; ++j) {
        int b;
        scanf("%d", &b);
        v.insert(b);
      }
    }
    puts(v.size() == m ? "YES" : "NO");
  }
  return 0;
}
