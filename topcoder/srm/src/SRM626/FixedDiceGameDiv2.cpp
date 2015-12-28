#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

class FixedDiceGameDiv2 {
public:
  double getExpectation(int a, int b)
  {
    double sum = 0;
    int cnt = 0;
    for (int i = 0; i < a; ++i) {
      for (int j = 0; j < b; ++j) {
        if (i > j) {
          sum += (i + 1);
          ++cnt;
        }
      }
    }
    return sum / cnt;
  }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; double Arg2 = 2.0; verify_case(0, Arg2, getExpectation(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 2; double Arg2 = 3.2; verify_case(1, Arg2, getExpectation(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 3; double Arg2 = 2.6666666666666665; verify_case(2, Arg2, getExpectation(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 11; int Arg1 = 13; double Arg2 = 7.999999999999999; verify_case(3, Arg2, getExpectation(Arg0, Arg1)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {
  FixedDiceGameDiv2 ___test;
  ___test.run_test(-1);
}

// END CUT HERE
