#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

class MicroStrings {
public:
  string makeMicroString(int A, int D)
  {
    ostringstream oss;
    while (0 <= A) {
      oss << A;
      A -= D;
    }
    return oss.str();
  }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 12; int Arg1 = 5; string Arg2 = "1272"; verify_case(0, Arg2, makeMicroString(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 2; string Arg2 = "31"; verify_case(1, Arg2, makeMicroString(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 31; int Arg1 = 40; string Arg2 = "31"; verify_case(2, Arg2, makeMicroString(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 30; int Arg1 = 6; string Arg2 = "3024181260"; verify_case(3, Arg2, makeMicroString(Arg0, Arg1)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {
  MicroStrings ___test;
  ___test.run_test(-1);
}

// END CUT HERE
