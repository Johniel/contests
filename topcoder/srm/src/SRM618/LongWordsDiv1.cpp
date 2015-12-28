#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

class LongWordsDiv1 {
public:
  int count(int n)
  {
    const lli mod = 1000000007;
    const int N = 5000 + 100;
    lli dp[N];
    fill(dp, dp + N, 0);
    dp[0] = 1;
    for (int i = 1; i < N; ++i) {
      dp[i] = (dp[i] + dp[i - 1]) % mod; // aXXXa
      for (int j = 1; j <= i - 2; ++j) {
        dp[i] += (dp[i - j - 1] * dp[j]) % mod; // aXXXaYYYa
        dp[i] %= mod;
      }
    }
    lli ret = dp[n];
    for (int i = 1; i <= n; ++i) {
      ret = (ret * i) % mod;
    }
    return ret;
  }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 1080; verify_case(2, Arg1, count(Arg0)); }
	void test_case_3() { int Arg0 = 100; int Arg1 = 486425238; verify_case(3, Arg1, count(Arg0)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {
  LongWordsDiv1 ___test;
  ___test.run_test(-1);
}

// END CUT HERE
