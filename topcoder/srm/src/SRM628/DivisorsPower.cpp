#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

inline bool f(lli n, int m, lli N)
{
  lli a = 1;
  for (int i = 0; i < m; ++i) {
    a *= n;
  }

  if (a != N) return false;

  for (lli i = 1; i * i <= n; ++i) {
    if (n % i == 0) {
      m -= 2;
      if (i * i == n) {
        ++m;
      }
    }
  }

  return m == 0;
}

class DivisorsPower {
public:
  long long findArgument(long long n)
  {
    if (n == 1) return 1;

    const lli inf = (1LL << 62);
    lli mn = inf;
    for (double i = 2.0; i <= 60.0; ++i) {
      double j = pow((double)n, 1.0 / i);
      lli a = ceil(j);
      lli b = floor(j);
      if (a && f(a, i, n)) mn = min(mn, a);
      if (b && f(b, i, n)) mn = min(mn, b);
    }
    return mn == inf ? -1 : mn;
  }

// BEGIN CUT HERE
	public:
	void run_test(int Case) {
    if ((Case == -1) || (Case == 0)) test_case_0();
    if ((Case == -1) || (Case == 1)) test_case_1();
    if ((Case == -1) || (Case == 2)) test_case_2();
    if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 4LL; long long Arg1 = 2LL; verify_case(0, Arg1, findArgument(Arg0)); }
	void test_case_1() { long long Arg0 = 10LL; long long Arg1 = -1LL; verify_case(1, Arg1, findArgument(Arg0)); }
	void test_case_2() { long long Arg0 = 64LL; long long Arg1 = 4LL; verify_case(2, Arg1, findArgument(Arg0)); }
	void test_case_3() { long long Arg0 = 10000LL; long long Arg1 = 10LL; verify_case(3, Arg1, findArgument(Arg0)); }
	void test_case_4() { long long Arg0 = 2498388559757689LL; long long Arg1 = 49983883LL; verify_case(4, Arg1, findArgument(Arg0)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {
  DivisorsPower ___test;
  ___test.run_test(-1);
}

// END CUT HERE
