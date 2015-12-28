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

class LCMSetEasy {
public:
  string include(vector <int> S, int x)
  {
    sort(S.begin(), S.end());
    if (binary_search(S.begin(), S.end(), x)) {
      return "Possible";
    }

    // 1,000,000,000,
    const int M = 100000;
    bool prime[M];
    fill(prime, prime + M, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i * i < M; ++i) {
      for (int j = 2; i * j < M; ++j) {
        prime[i * j] = false;
      }
    }

    vector<int> p;
    for (int i = 0; i < M; ++i) {
      if (prime[i]) p.push_back(i);
    }

    const int N = S.size();
    map<int, int> A;
    map<int, int> B;

    const int P = p.size();
    int n = x;
    for (int i = 0; i < P; ++i) {
      while (n % p[i] == 0) {
        ++A[p[i]];
        n /= p[i];
      }
    }
    if (n != 1) ++A[n];

    for (int i = 0; i < N; ++i) {
      int n = S[i];
      map<int, int> C;
      for (int j = 0; j < P; ++j) {
        while (n % p[j] == 0) {
          ++C[p[j]];
          n /= p[j];
        }
      }
      if (n != 1) ++C[n];
      bool flg = true;
      each (j, C) {
        int m = j->first;
        flg = flg && (0 < A.count(m));
        flg = flg && (C[m] <= A[m]);
      }
      if (flg) {
        each (j, C) {
          int m = j->first;
          B[m] = max(B[m], C[m]);
        }
      }
    }

    bool flg = (A.size() == B.size());
    each (i, A) {
      int m = i->first;
      flg = flg && (A[m] == B[m]);
    }
    return flg ? "Possible" : "Impossible";
  }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2,3,4,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 20; string Arg2 = "Possible"; verify_case(0, Arg2, include(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {2,3,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 611; string Arg2 = "Impossible"; verify_case(1, Arg2, include(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {2,3,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; string Arg2 = "Possible"; verify_case(2, Arg2, include(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1,2,3,4,5,6,7,8,9,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 24; string Arg2 = "Possible"; verify_case(3, Arg2, include(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {100,200,300,400,500,600}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2000; string Arg2 = "Possible"; verify_case(4, Arg2, include(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {100,200,300,400,500,600}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8000; string Arg2 = "Impossible"; verify_case(5, Arg2, include(Arg0, Arg1)); }
	void test_case_6() { int Arr0[] = {1000000000,999999999,999999998}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 999999999; string Arg2 = "Possible"; verify_case(6, Arg2, include(Arg0, Arg1)); }

// END CUT HERE

};



// BEGIN CUT HERE

int main() {
  LCMSetEasy ___test;
  ___test.run_test(-1);
}

// END CUT HERE
