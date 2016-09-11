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
  int x, y;
  while (scanf("%d%d", &x, &y) == 2) {
    vector<int> v = {y, y, y};
    int cnt = 0;

    while (v != vector<int>({x, x, x})) {
      // cout << v[0] << ' ' << v[1] << ' ' << v[2] << endl;
      int z = (v[1] + v[2]) - 1;
      v[0] = min(x, z);
      sort(v.begin(), v.end());
      ++cnt;
    }
    
    printf("%d\n", cnt);
  }
  return 0;
}
