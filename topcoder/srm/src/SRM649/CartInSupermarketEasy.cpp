#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

const int N = 100 + 5;
const int K = 100 + 5;
int memo[N][K];

int rec(int n, int k)
{
  if (memo[n][k] != -1) return memo[n][k];
  int mn = n;
  if (k) {
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j <= k - 1; ++j) {
        mn = min(mn, max(rec(i, j), rec(n - i, (k - 1) - j)) + 1);
      }
    }
  }
  return memo[n][k] = mn;
}

class CartInSupermarketEasy {
public:
  int calc(int n, int k)
  {
    fill(&memo[0][0], &memo[N - 1][K - 1] + 1, -1);
    return rec(n, k);
  }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 0; int Arg2 = 5; verify_case(0, Arg2, calc(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 2; int Arg2 = 4; verify_case(1, Arg2, calc(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 15; int Arg1 = 4; int Arg2 = 6; verify_case(2, Arg2, calc(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 7; int Arg1 = 100; int Arg2 = 4; verify_case(3, Arg2, calc(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 45; int Arg1 = 5; int Arg2 = 11; verify_case(4, Arg2, calc(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 100; int Arg1 = 100; int Arg2 = 8; verify_case(5, Arg2, calc(Arg0, Arg1)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {
  CartInSupermarketEasy ___test;
  ___test.run_test(-1);
}

// END CUT HERE
