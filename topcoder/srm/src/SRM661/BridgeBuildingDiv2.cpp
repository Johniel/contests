#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

class BridgeBuildingDiv2 {
public:
  int minDiameter(vector <int> a, vector <int> b, int K)
  {
    const int N = a.size() + 1;
    const int M = N * 2 + 10;
    const int inf = (1 << 27);
    int mn = inf;
    int g[M][M];
    for (int bit = 0; bit < (1 << N); ++bit) {
      if (__builtin_popcount(bit) - K) continue;
      fill(&g[0][0], &g[M - 1][M - 1] + 1, inf);
      for (int i = 0; i < N - 1; ++i) {
        int j = N + i;
        g[i][i + 1] = g[i + 1][i] = a[i];
        g[j][j + 1] = g[j + 1][j] = b[i];
        g[i][i] = g[j][j] = 0;
      }
      for (int i = 0; i < N; ++i) {
        if (bit & (1 << i)) {
          g[i][N + i] = g[N + i][i] = 0;
        }
      }
      for (int k = 0; k < M; ++k) {
        for (int i = 0; i < M; ++i) {
          for (int j = 0; j < M; ++j) {
            g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
          }
        }
      }
      replace(&g[0][0], &g[M - 1][M - 1] + 1, inf, -1);
      mn = min(mn, *max_element(&g[0][0], &g[M - 1][M - 1] + 1));
    }
    return mn;
  }

// BEGIN CUT HERE
 	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2,1,1,1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,9,1,9,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; int Arg3 = 6; verify_case(0, Arg3, minDiameter(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {1,50,1,50,1,50,1,50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {50,1,50,1,50,1,50,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 9; int Arg3 = 8; verify_case(1, Arg3, minDiameter(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {50,10,15,31,20,23,7,48,5,50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,5,1,8,3,2,16,11,9,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arg3 = 124; verify_case(2, Arg3, minDiameter(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {2,4,10,2,2,22,30,7,28}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5,26,1,2,6,2,16,3,15}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; int Arg3 = 54; verify_case(3, Arg3, minDiameter(Arg0, Arg1, Arg2)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {
  BridgeBuildingDiv2 ___test;
  ___test.run_test(-1);
}

// END CUT HERE
