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

string S, T;

const int N = 50 + 1;
const int M = 10;
int g[M][M];
int memo[N][N][M][2];

int rec(int begin, int end, int r, bool f)
{
  int& ret = memo[begin][end][r][f];
  if (ret != -1) return ret;

  int mn = 0;
  for (int i = begin; i < end; ++i) {
    int a = (S[i] - '0' + r) % 10;
    int b = (T[i] - '0');
    mn += g[a][b];
  }

  if (f) {
    for (int i = 1; i < 10; ++i) {
      int x = (r + i) % 10;
      mn = min(mn, rec(begin, end, x, false) + g[r][x]);
    }
  }

  for (int i = begin + 1; i < end; ++i) {
    mn = min(mn, rec(begin, i, r, true) + rec(i, end, r, true));
  }

  return ret = mn;
}


class CombinationLockDiv2 {
public:
  int minimumMoves(string S_, string T_)
  {
    S = S_;
    T = T_;

    fill(&g[0][0], &g[M - 1][M - 1] + 1, (1 << 28));
    for (int i = 0; i < M; ++i) {
      int j = (i + 1) % M;
      int k = (i + M - 1) % M;
      g[i][j] = g[j][i] = 1;
      g[i][k] = g[k][i] = 1;
      g[i][i] = 0;
    }
    for (int k = 0; k < M; ++k) {
      for (int i = 0; i < M; ++i) {
        for (int j = 0; j < M; ++j) {
          g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
        }
      }
    }

    fill(&memo[0][0][0][0], &memo[N - 1][N - 1][M - 1][2 - 1] + 1, -1);
    return rec(0, S.size(), 0, true);
  }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "123"; string Arg1 = "112"; int Arg2 = 1; verify_case(0, Arg2, minimumMoves(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "1"; string Arg1 = "7"; int Arg2 = 4; verify_case(1, Arg2, minimumMoves(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "607"; string Arg1 = "607"; int Arg2 = 0; verify_case(2, Arg2, minimumMoves(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "1234"; string Arg1 = "4567"; int Arg2 = 3; verify_case(3, Arg2, minimumMoves(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "020"; string Arg1 = "909"; int Arg2 = 2; verify_case(4, Arg2, minimumMoves(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "4423232218340"; string Arg1 = "6290421476245"; int Arg2 = 18; verify_case(5, Arg2, minimumMoves(Arg0, Arg1)); }

// END CUT HERE

};



// BEGIN CUT HERE

int main() {
  CombinationLockDiv2 ___test;
  ___test.run_test(-1);
}

// END CUT HERE
