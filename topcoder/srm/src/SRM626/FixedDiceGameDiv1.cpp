#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

class FixedDiceGameDiv1 {
public:
  double getExpectation(int a, int b, int c, int d)
  {
    const int N = 60;
    const int M = N * N;

    static double dp1[N][M];
    fill(&dp1[0][0], &dp1[N - 1][M - 1] + 1, 0);
    dp1[0][0] = 1.0;

    static double dp2[N][M];
    fill(&dp2[0][0], &dp2[N - 1][M - 1] + 1, 0);
    dp2[0][0] = 1.0;

    for (int i = 0; i < 55; ++i) {
      for (int j = 0; j < M; ++j) {
        for (int k = 1; k <= b; ++k) {
          if (j + k < M) dp1[i + 1][j + k] += dp1[i][j] / (double)b;
        }
        for (int k = 1; k <= d; ++k) {
          if (j + k < M) dp2[i + 1][j + k] += dp2[i][j] / (double)d;
        }
      }
    }

    double n = 0;
    double m = 0;
    for (int alice = 0; alice <= (a * b); ++alice) {
      for (int bob = 0; bob < alice; ++bob) {
        if (dp1[a][alice] && dp2[c][bob]) {
          n += alice * dp1[a][alice] * dp2[c][bob];
          m += dp1[a][alice] * dp2[c][bob];
        }
      }
    }

    return m ? n / m : -1;
  }


};




// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
