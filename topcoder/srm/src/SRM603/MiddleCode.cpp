#include <algorithm>
#include <complex>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()
#define each(i, c) FOR(i, c)

#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

class MiddleCode {
public:
  string encode(string s)
  {
    string t;
    while (s.size()) {
      if (s.size() % 2) {
        int a = s.size() / 2;
        t += s[a];
        s.erase(s.begin() + a);
      } else {
        int a = s.size() / 2;
        int b = a - 1;
        t += min(s[a], s[b]);
        s.erase(s.begin() + (s[a] < s[b] ? a : b));
      }
      cout << s << ", " << t << endl;
    }
    return t;
  }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "word"; string Arg1 = "ordw"; verify_case(0, Arg1, encode(Arg0)); }
	void test_case_1() { string Arg0 = "aaaaa"; string Arg1 = "aaaaa"; verify_case(1, Arg1, encode(Arg0)); }
	void test_case_2() { string Arg0 = "abacaba"; string Arg1 = "caabbaa"; verify_case(2, Arg1, encode(Arg0)); }
	void test_case_3() { string Arg0 = "shjegr"; string Arg1 = "ejghrs"; verify_case(3, Arg1, encode(Arg0)); }
	void test_case_4() { string Arg0 = "adafaaaadafawafwfasdaa"; string Arg1 = "afawadafawafaafsadadaa"; verify_case(4, Arg1, encode(Arg0)); }

// END CUT HERE

};



// BEGIN CUT HERE

int main() {
  MiddleCode ___test;
  ___test.run_test(-1);
}

// END CUT HERE
