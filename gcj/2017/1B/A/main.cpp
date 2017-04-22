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

  int tc;
  cin >> tc;
  while (tc--) {

    double D;
    int N;
    cin >> D >> N;
    pair<int, double> p[N];
    for (int i = 0; i < N; ++i) {
      cin >> p[i].first >> p[i].second;
    }
    sort(p, p + N);

    int idx = N - 1;
    for (int i = N - 2; 0 <= i; --i) {
      double t = (D - p[idx].first) / p[idx].second;
      if (p[i].first + t * p[i].second <= D) {
        idx = i;
      }
    }
    double t = (D - p[idx].first) / p[idx].second;
    static int tc = 0;
    printf("Case #%d: %.10lf\n", ++tc, D / t);
  }
  
  return 0;
}
