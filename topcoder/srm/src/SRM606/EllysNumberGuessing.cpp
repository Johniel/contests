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

class EllysNumberGuessing {
public:
  int getNumber(vector <int> g, vector <int> a)
  {
    int mx = 0;
    map<int, int> cnt;
    const int N = g.size();
    for (int i = 0; i < N; ++i) {
      int n = g[i] - a[i];
      int m = g[i] + a[i];
      if (1 <= n && n <= 1000000000) {
        mx = max(mx, ++cnt[n]);
      }
      if (1 <= m && m <= 1000000000) {
        mx = max(mx, ++cnt[m]);
      }
    }
    int n = 0;
    int m = 0;
    each (i, cnt) {
      if (i->second == mx) {
        ++n;
        m = i->first;
      }
    }
    if (mx == N && n == 1) return m;
    if (mx != N) return -2;
    return -1;
  }


};





// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
