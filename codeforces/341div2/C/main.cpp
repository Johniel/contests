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

double g(pair<int, int> a, int p)
{
  return (a.second / p - (a.first - 1) / p) / (double)(a.second - a.first + 1);
}

double f(pair<int, int> a, pair<int, int> b, int p)
{
  return 1.0 - (1.0 - g(a, p)) * (1.0 - g(b, p));
}

int main(int argc, char *argv[])
{
  int n, p;
  while (scanf("%d%d", &n, &p) == 2) {
    vector<pair<int, int>> v;
    for (int i = 0; i < n; ++i) {
      int a, b;
      scanf("%d%d", &a, &b);
      v.push_back(make_pair(a, b));
    }

    double e = 0.0;
    for (int i = 0; i < v.size(); ++i) {
      int j = (i + 1) % v.size();
      e += f(v[i], v[j], p) * 2000.0;
    }
    printf("%.10lf\n", e);
  }
  return 0;
}
