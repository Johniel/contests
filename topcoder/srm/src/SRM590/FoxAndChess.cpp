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

class FoxAndChess {
public:
  string ableToMove(string A, string B)
  {
    const string T = "Possible";
    const string F = "Impossible";

    if (count(A.begin(), A.end(), 'L') != count(B.begin(), B.end(), 'L')) return F;
    if (count(A.begin(), A.end(), 'R') != count(B.begin(), B.end(), 'R')) return F;

    const int size = A.size();

    vector<int> lA;
    vector<int> rA;
    for (int i = 0; i < size; ++i) {
      if (A[i] == 'R') rA.push_back(i);
      if (A[i] == 'L') lA.push_back(i);
    }

    vector<int> lB;
    vector<int> rB;
    for (int i = 0; i < size; ++i) {
      if (B[i] == 'R') rB.push_back(i);
      if (B[i] == 'L') lB.push_back(i);
    }

    const int size_r = rA.size();
    const int size_l = lA.size();

    //
    for (int i = 0; i < size_r; ++i) {
      unless (rA[i] <= rB[i]) return F;
      int cnt_a = 0;
      int cnt_b = 0;
      for (int j = 0; j < size_l; ++j) {
        cnt_a += (lA[j] <= rA[i]);
        cnt_b += (lB[j] <= rB[i]);
      }
      if (cnt_a != cnt_b) return F;
    }

    //
    for (int i = 0; i < size_l; ++i) {
      unless (lA[i] >= lB[i]) return F;
      int cnt_a = 0;
      int cnt_b = 0;
      for (int j = 0; j < size_r; ++j) {
        cnt_a += (rA[j] <= lA[i]);
        cnt_b += (rB[j] <= lB[i]);
      }
      if (cnt_a != cnt_b) return F;
    }

    return T;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "R..."; string Arg1 = "..R."; string Arg2 = "Possible"; verify_case(0, Arg2, ableToMove(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "..R."; string Arg1 = "R..."; string Arg2 = "Impossible"; verify_case(1, Arg2, ableToMove(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = ".L.R.R."; string Arg1 = "L...R.R"; string Arg2 = "Possible"; verify_case(2, Arg2, ableToMove(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = ".L.R."; string Arg1 = ".R.L."; string Arg2 = "Impossible"; verify_case(3, Arg2, ableToMove(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "LRLLRLRLLRLLRLRLRL"; string Arg1 = "LRLLRLRLLRLLRLRLRL"; string Arg2 = "Possible"; verify_case(4, Arg2, ableToMove(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "L"; string Arg1 = "."; string Arg2 = "Impossible"; verify_case(5, Arg2, ableToMove(Arg0, Arg1)); }

// END CUT HERE

};



// BEGIN CUT HERE

int main() {
  FoxAndChess ___test;
  ___test.run_test(-1);
}

// END CUT HERE
