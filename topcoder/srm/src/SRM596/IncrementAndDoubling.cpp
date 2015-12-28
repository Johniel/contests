#include <algorithm>
#include <complex>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <numeric>
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

const int inf = (1 << 28);
const int N = 1005;
const int D = 11;
int dp[D][N];

void f(void)
{
  fill(&dp[0][0], &dp[D - 1][N - 1] + 1, inf);
  dp[0][0] = 0;
  dp[0][1] = 1;
  for (int d = 0; d + 1 < D; ++d) {
    for (int n = 0; n + 1 < N; ++n) {
      if (d + 1 < D && n * 2 < N) {
        dp[d + 1][n * 2] = min(dp[d + 1][n * 2], dp[d][n] + 1);
      }
      dp[d][n + 1] = min(dp[d][n + 1], dp[d][n] + 1);
    }
  }
  return ;
}

const int M = 52;
int memo[M][D];
int rec(int n, int mx, const vector<int>& a)
{
  if (n == a.size()) return 0;
  int& ret = memo[n][mx];
  if (ret != -1) return ret;

  int mn = 1 << 28;
  for (int d = 0; d < D; ++d) {
    if (dp[d][a[n]] < inf) {
      int cost = dp[d][a[n]];
      if (d <= mx) cost -= d;
      mn = min(mn, rec(n + 1, d, a) + cost);
    }
  }

  return ret = mn;
}

class IncrementAndDoubling {
public:
  int getMin(vector <int> a)
  {
    f();
    fill(&memo[0][0], &memo[M - 1][D - 1] + 1, -1);
    return rec(0, 0, a);
  }

// BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, getMin(Arg0)); }
	void test_case_1() { int Arr0[] = {16, 16, 16}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(1, Arg1, getMin(Arg0)); }
	void test_case_2() { int Arr0[] = {100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; verify_case(2, Arg1, getMin(Arg0)); }
	void test_case_3() { int Arr0[] = {0, 0, 1, 0, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(3, Arg1, getMin(Arg0)); }
	void test_case_4() { int Arr0[] = {123, 234, 345, 456, 567, 789}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 40; verify_case(4, Arg1, getMin(Arg0)); }
	void test_case_5() { int Arr0[] = {7,5,8,1,8,6,6,5,3,5,5,2,8,9,9,4,6,9,4,4,1,9,9,2,8,4,7,4,8,8,6,3,9,4,3,4,5,1,9,8,3,8,3,7,9,3,8,4,4,7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 84; verify_case(5, Arg1, getMin(Arg0)); }

// END CUT HERE

};



// BEGIN CUT HERE

int main() {
  IncrementAndDoubling ___test;
  ___test.run_test(-1);
}

// END CUT HERE
