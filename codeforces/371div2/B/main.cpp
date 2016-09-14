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
  lli n;
  while (scanf("%lld", &n) == 1) {
    vector<lli> v;
    for (int i = 0; i < n; ++i) {
      lli a;
      scanf("%lld", &a);
      v.push_back(a);
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    
    if (v.size() == 1) puts("YES");
    else if (v.size() == 2) puts("YES");
    else if (v.size() == 3 && v[1] - v[0] == v[2] - v[1]) puts("YES");
    else puts("NO");
  }
  return 0;
}
