#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

class TorusSailingEasy {
public:
  double expectedTime(int N, int M, int goalX, int goalY)
  {
    const int di[] = {-1, +1};
    const int dj[] = {-1, +1};

    double sum = 0;

    double prob[2][N][M];
    fill(&prob[0][0][0], &prob[2 - 1][N - 1][M - 1] + 1, 0);
    prob[0][0][0] = 1.0;

    for (int loop = 0; loop < 150000; ++loop) {
      int curr = loop % 2;
      int next = (curr + 1) % 2;
      for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
          prob[next][i][j] = 0;
        }
      }
      for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
          for (int d = 0; d < 2; ++d) {
            int ni = (i + di[d] + N) % N;
            int nj = (j + dj[d] + M) % M;
            prob[next][ni][nj] += prob[curr][i][j] / 2.0;
          }
        }
      }
      sum += (loop + 1) * prob[next][goalX][goalY];
      prob[next][goalX][goalY] = 0;
    }

    return (sum < 1e-11) ? -1.0 : sum;
  }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 1; int Arg3 = 1; double Arg4 = 1.0; verify_case(0, Arg4, expectedTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 0; int Arg3 = 1; double Arg4 = -1.0; verify_case(1, Arg4, expectedTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 1; int Arg3 = 1; double Arg4 = 2.0; verify_case(2, Arg4, expectedTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 6; int Arg2 = 1; int Arg3 = 3; double Arg4 = 27.0; verify_case(3, Arg4, expectedTime(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {
  TorusSailingEasy ___test;
  ___test.run_test(-1);
}

// END CUT HERE
