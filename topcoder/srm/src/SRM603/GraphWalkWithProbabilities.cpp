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

const int N = 50 + 5;
const int D = N * 4;
double memo[D][N];

vector<int> w;
vector<int> l;

bool g[N][N];

double rec(int depth, int curr)
{
  if (depth == D) return (double)w[curr] / (w[curr] + l[curr]);

  double& ret = memo[depth][curr];
  if (ret != -1) return ret;

  double mx = 0;
  for (int next = 0; next < N; ++next) {
    if (g[curr][next]) {
      double p = 0;
      p += rec(depth + 1, next) * (100.0 - l[next] - w[next]) / 100.0;
      p += (double)w[next] / 100.0;
      mx = max(mx, p);
    }
  }

  return ret = mx;
}

class GraphWalkWithProbabilities {
public:
  double findprob(vector <string> G, vector <int> w_, vector <int> l_, int Start)
  {
    w = w_;
    l = l_;
    fill(&g[0][0], &g[N - 1][N - 1] + 1, false);
    for (int i = 0; i < G.size(); ++i) {
      for (int j = 0; j < G.size(); ++j) {
        g[i][j] = (G[i][j] == '1');
      }
    }
    fill(&memo[0][0], &memo[D - 1][N - 1] + 1, -1);
    return rec(0, Start);
  }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; double Arg4 = 0.5; verify_case(0, Arg4, findprob(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { string Arr0[] = {"11","11"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {60,40}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {40,60}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; double Arg4 = 0.6; verify_case(1, Arg4, findprob(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { string Arr0[] = {"11","11"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3,4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; double Arg4 = 0.4285714285714286; verify_case(2, Arg4, findprob(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { string Arr0[] = {"110","011","001"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,1,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {20,20,10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; double Arg4 = 0.405; verify_case(3, Arg4, findprob(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { string Arr0[] = {"111","111","011"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {100,1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,50,50}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; double Arg4 = 0.5; verify_case(4, Arg4, findprob(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};



// BEGIN CUT HERE

int main() {
  GraphWalkWithProbabilities ___test;
  ___test.run_test(-1);
}

// END CUT HERE
