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

class PalindromicSubstringsDiv2 {
public:
  int count(vector <string> S1, vector <string> S2)
  {
    string s = "";
    s += accumulate(S1.begin(), S1.end(), string(""));
    s += accumulate(S2.begin(), S2.end(), string(""));

    int ret = 0;
    const int N = s.size();

    for (int i = 0; i < N; ++i) {
      for (int len = 0; len < N; ++len) {
        int j = i - len;
        int k = i + len;
        if (0 <= j && k < N && s[j] == s[k]) {
          ++ret;
        } else {
          break;
        }
      }
    }

    for (int i = 0; i + 1 < N; ++i) {
      if (s[i] == s[i + 1]) {
        for (int len = 0; len < N; ++len) {
          int j = i - len;
          int k = i + len + 1;
          if (0 <= j && k < N && s[j] == s[k]) {
            ++ret;
          } else {
            break;
          }
        }
      }
    }

    return ret;
  }


};





// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
