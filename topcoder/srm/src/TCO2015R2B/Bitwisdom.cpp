#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

class Bitwisdom {
public:
  double expectedActions(vector <int> p)
  {
    if (p.size() == 1) return p[0] / 100.0;

    double ret = 0;

    const int M = p.size();
    const int N = 300 + 10;
    double dp[N][2][N];

    fill(&dp[0][0][0], &dp[N - 1][2 - 1][N - 1] + 1, 0);
    dp[1][0][0] = (100 - p[0]) / 100.0;
    for (int i = 0; i < M; ++i) {
      for (int j = 0; j < 2; ++j) {
        for (int k = 0; k < M; ++k) {
          dp[i + 1][0][k] += dp[i][j][k] * (100.0 - p[i]) / 100.0;
          dp[i + 1][1][k + (j == 0)] += dp[i][j][k] * (p[i]) / 100.0;
        }
      }
    }
    // 0...0
    // 0...1
    {
      for (int k = 0; k < N; ++k) {
        ret += dp[M][0][k] * (k * 2);
        if (k) ret += dp[M][1][k] * ((k - 1) * 2 + 1);
      }
    }

    fill(&dp[0][0][0], &dp[N - 1][2 - 1][N - 1] + 1, 0);
    dp[1][1][1] = p[0] / 100.0;
    for (int i = 0; i < M; ++i) {
      for (int j = 0; j < 2; ++j) {
        for (int k = 0; k < M; ++k) {
          dp[i + 1][0][k] += dp[i][j][k] * (100.0 - p[i]) / 100.0;
          dp[i + 1][1][k + (j == 0)] += dp[i][j][k] * (p[i]) / 100.0;
        }
      }
    }
    // 1...0
    // 1...1
    {
      for (int k = 1; k < N; ++k) {
        ret += dp[M][0][k] * ((k - 1) * 2 + 1);
        if (2 <= k) ret += dp[M][1][k] * ((k - 2) * 2 + 2);
      }
    }
    ret += dp[M][1][1] * 1;

    return ret;
  }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {100, 100, 100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 1.0; verify_case(0, Arg1, expectedActions(Arg0)); }
	void test_case_1() { int Arr0[] = {50, 50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.75; verify_case(1, Arg1, expectedActions(Arg0)); }
	void test_case_2() { int Arr0[] = {0, 40, 50, 60}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 1.4; verify_case(2, Arg1, expectedActions(Arg0)); }
	void test_case_3() { int Arr0[] = {37, 63, 23, 94, 12}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 2.6820475464; verify_case(3, Arg1, expectedActions(Arg0)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {
  Bitwisdom ___test;
  ___test.run_test(-1);
}

// END CUT HERE
