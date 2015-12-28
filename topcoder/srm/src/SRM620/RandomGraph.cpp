#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

class RandomGraph {
public:
  double probability(int n, int p)
  {
    const double q = 0.001 * p;
    const int N = 55;
    static double dp[N][N][N];
    fill(&dp[0][0][0], &dp[N - 1][N - 1][N - 1] + 1, 0);
    dp[0][0][0] = 1;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        for (int k = 0; k < N; ++k) {
          double m = (3 * i) + (2 * j) + (1 * k);
          if (n <= m) continue;
          // x
          dp[i][j][k + 1] += dp[i][j][k] * pow(1.0 - q, m);
          if (k) {
            // o-x
            dp[i][j + 1][k - 1] += dp[i][j][k] * pow(1.0 - q, m - 1) * q * k;
          }
          if (j) {
            // o-o-x
            dp[i + 1][j - 1][k] += dp[i][j][k] * pow(1.0 - q, m - 1) * q * (2 * j);
            //   x
            //  / \
            // o---o
            dp[i + 1][j - 1][k] += dp[i][j][k] * pow(1.0 - q, m - 2) * q * q * j;
          }
          if (2 <= k) {
            // o-x-o
            dp[i + 1][j][k - 2] += dp[i][j][k] * pow(1.0 - q, m - 2) * q * q * (k * (k - 1) / 2);
          }
        }
      }
    }
    double sum = 0;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        for (int k = 0; k < N; ++k) {
          if ((3 * i) + (2 * j) + (1 * k) == n) {
            sum += dp[i][j][k];
          }
        }
      }
    }
    return 1.0 - sum;
  }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 7; int Arg1 = 0; double Arg2 = 0.0; verify_case(0, Arg2, probability(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 620; double Arg2 = 0.0; verify_case(1, Arg2, probability(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 500; double Arg2 = 0.59375; verify_case(2, Arg2, probability(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 8; int Arg1 = 100; double Arg2 = 0.33566851611343496; verify_case(3, Arg2, probability(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 15; int Arg1 = 50; double Arg2 = 0.5686761670525845; verify_case(4, Arg2, probability(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 50; int Arg1 = 10; double Arg2 = 0.7494276522159893; verify_case(5, Arg2, probability(Arg0, Arg1)); }
	void test_case_6() { int Arg0 = 50; int Arg1 = 1000; double Arg2 = 1.0; verify_case(6, Arg2, probability(Arg0, Arg1)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {
  RandomGraph ___test;
  ___test.run_test(-1);
}

// END CUT HERE
