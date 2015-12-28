#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

class EllysLamps {
public:
  int getMin(string ls)
  {
    const int N = 60;
    const int M = ls.size();
    int dp[N];
    fill(dp, dp + N, -(1 << 29));
    dp[0] = 0;
    for (int i = 0; i < M; ++i) {
      if (i + 1 < M && ls[i] != ls[i + 1]) {
        dp[i + 2] = max(dp[i + 2], dp[i] + 1);
      }
      if (i + 2 < M && ls[i] == 'Y' && ls[i] == ls[i + 1] && ls[i] == ls[i + 2]) {
        dp[i + 3] = max(dp[i + 3], dp[i] + 1);
      }
      dp[i + 1] = max(dp[i + 1], dp[i]);
    }
    return *max_element(dp, dp + N);
  }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "YNNYN"; int Arg1 = 2; verify_case(0, Arg1, getMin(Arg0)); }
	void test_case_1() { string Arg0 = "NNN"; int Arg1 = 0; verify_case(1, Arg1, getMin(Arg0)); }
	void test_case_2() { string Arg0 = "YY"; int Arg1 = 0; verify_case(2, Arg1, getMin(Arg0)); }
	void test_case_3() { string Arg0 = "YNYYYNNNY"; int Arg1 = 3; verify_case(3, Arg1, getMin(Arg0)); }
	void test_case_4() { string Arg0 = "YNYYYYNYNNYYNNNNNNYNYNYNYNNYNYYYNY"; int Arg1 = 13; verify_case(4, Arg1, getMin(Arg0)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {
  EllysLamps ___test;
  ___test.run_test(-1);
}

// END CUT HERE
