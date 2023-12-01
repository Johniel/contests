#include <algorithm>
#include <complex>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()
#define each(i, c) FOR(i, c)

#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

int main(int argc, char *argv[])
{
  int N;
  while (cin >> N) {
    vector< vector<int> > v;
    for (int i = 0; i < N; ++i) {
      int a, b, c;
      cin >> a >> b >> c;
      vector<int> u;
      u.push_back(a);
      u.push_back(b);
      u.push_back(c);
      sort(u.begin(), u.end());
      v.push_back(u);
    }
    sort(v.begin(), v.end());
    int a, b, c;
    a = b = c = 1;
    for (int i = 0; i < N; ++i) {
      a = max(a, v[i][0]);
      b = max(b, v[i][1]);
      c = max(c, v[i][2]);
    }
    cout << a * b * c << endl;
  }
  return 0;
}
