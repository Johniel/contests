#include <algorithm>
#include <complex>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <vector>

#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()
#define each(i, c) FOR(i, c)

#define VAR(a) cout << #a << " : " << a << endl;
#define LOG()  cout << __LINE__ << ", " << __func__ << endl;

typedef long long int lli;

using namespace std;

int main(int argc, char *argv[])
{
  int n;
  string s;
  while (cin >> n >> s) {
    double a = count(s.begin(), s.end(), 'A');
    double b = count(s.begin(), s.end(), 'B');
    double c = count(s.begin(), s.end(), 'C');
    double d = count(s.begin(), s.end(), 'D');
    double f = count(s.begin(), s.end(), 'F');
    double sum = a * 4.0 + b * 3.0 + c * 2.0 + d * 1.0 + f * 0.0;
    printf("%.10lf\n", sum / s.size());
  }

  return 0;
}
