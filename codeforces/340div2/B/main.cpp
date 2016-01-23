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
    vector<int> v;
    for (int i = 0; i < n; ++i) {
      int m;
      scanf("%d", &m);
      v.push_back(m);
    }
    if (count(v.begin(), v.end(), 0) == v.size()) {
      puts("0");
      continue;
    }
    vector<int> u;
    for (int i = 0; i < v.size(); ++i) {
      if (v[i] == 1) u.push_back(i);
    }
    ull m = 1;
    for (int i = 0; i + 1 < u.size(); ++i) {
      m *= (ull)(u[i + 1] - u[i]);
    }
    printf("%llu\n", m);
  }
  return 0;
}
