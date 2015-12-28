#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

const int A = 62;
const int B = 10000;
lli memo[A][B];
vector<int> bit;

lli rec(int nth, int carry)
{
  if (carry < 0) return 0;
  if ((nth + 1) * 2 < carry) return 0;
  if (nth == 0) {
    return (bit[nth] + carry) <= 2;
  }

  lli& ret = memo[nth][carry];
  if (ret != -1) return ret;

  lli sum = 0;

  sum += rec(nth - 1, (bit[nth] + carry - 0) * 2);
  sum += rec(nth - 1, (bit[nth] + carry - 1) * 2);
  sum += rec(nth - 1, (bit[nth] + carry - 2) * 2);

  return ret = sum;
}

class TaroCoins {
public:
  long long getNumber(lli N)
  {
    bit = vector<int>(A, 0);
    for (int i = 0; i < 63; ++i) {
      if (N & (1LL << i)) bit[i] = 1;
    }
    fill(&memo[0][0], &memo[A - 1][B - 1] + 1, -1);
    return rec(A - 1, 0);
  }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 1LL; long long Arg1 = 1LL; verify_case(0, Arg1, getNumber(Arg0)); }
	void test_case_1() { long long Arg0 = 6LL; long long Arg1 = 3LL; verify_case(1, Arg1, getNumber(Arg0)); }
	void test_case_2() { long long Arg0 = 47LL; long long Arg1 = 2LL; verify_case(2, Arg1, getNumber(Arg0)); }
	void test_case_3() { long long Arg0 = 256LL; long long Arg1 = 9LL; verify_case(3, Arg1, getNumber(Arg0)); }
	void test_case_4() { long long Arg0 = 8489289LL; long long Arg1 = 6853LL; verify_case(4, Arg1, getNumber(Arg0)); }
	void test_case_5() { long long Arg0 = 1000000000LL; long long Arg1 = 73411LL; verify_case(5, Arg1, getNumber(Arg0)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {
  TaroCoins ___test;
  ___test.run_test(-1);
}

// END CUT HERE
