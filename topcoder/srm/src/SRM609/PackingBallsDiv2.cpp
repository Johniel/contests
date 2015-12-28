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

class PackingBallsDiv2 {
public:
  int minPacks(int R, int G, int B)
  {
    int ret = 0;
    ret += (R / 3); R %= 3;
    ret += (G / 3); G %= 3;
    ret += (B / 3); B %= 3;

    int mn = min(R, min(G, B));
    ret += mn;
    R -= mn;
    G -= mn;
    B -= mn;

    // 0 0 1
    // 0 1 1
    // 0 1 2
    // 0 0 2
    // 0 2 2
    if (R || G || B) {
      if (R + G + B == 4) ret += 2;
      if (R + G + B == 3) ret += 2;
      if (R + G + B <  3) ret += 1;
    }
    return ret;
  }


};





// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
