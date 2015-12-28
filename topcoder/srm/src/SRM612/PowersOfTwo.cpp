#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

class PowersOfTwo {
public:
  long long count(vector<long long> ps)
  {
    const int N = 100;
    const int M = 64;

    lli dp[N][M];
    fill(&dp[0][0], &dp[N - 1][M - 1] + 1, 0);

    lli bs[N];
    fill(bs, bs + N, 0);

    for (int i = 0; i < M; ++i) {
      bs[i] = std::count(ps.begin(), ps.end(), (1LL << i));
    }

    dp[0][0] = 1;
    for (int i = 0; i + 1 < N; ++i) {
      for (int j = 0; j < M; ++j) {
        int c = j + bs[i];
        dp[i + 1][c / 2] += dp[i][j];
        if (c) dp[i + 1][(c - 1) / 2] += dp[i][j];
      }
    }

    return dp[N - 1][0];
  }


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long Arr0[] = {1,2}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 4LL; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { long Arr0[] = {1,1,1,1}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 5LL; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { long Arr0[] = {1,2,2,2,4,4,16}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 32LL; verify_case(2, Arg1, count(Arg0)); }
	void test_case_3() { long Arr0[] = {1,32,1,16,32}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 18LL; verify_case(3, Arg1, count(Arg0)); }
	void test_case_4() { lli Arr0[] = {1048576,1073741824LL,549755813888LL,70368744177664LL,4398046511104LL,262144,1048576,2097152,8796093022208,
                                     1048576,1048576,35184372088832LL,2097152,256,256,256,262144,1048576,1048576,70368744177664LL,262144,1048576}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 18432LL; verify_case(4, Arg1, count(Arg0)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {
  PowersOfTwo ___test;
  ___test.run_test(-1);
}

// END CUT HERE
