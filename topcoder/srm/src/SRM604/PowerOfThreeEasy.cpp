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

lli X, Y;

struct S { lli x; lli y; lli k; };

bool operator < (const S &a, const S &b)
{
  if (a.x != b.x) return a.x < b.x;
  if (a.y != b.y) return a.y < b.y;
  return a.k < b.k;
}



class PowerOfThreeEasy {
public:
  string ableToGet(int x_, int y_)
  {
    X = x_;
    Y = y_;

    if (X == 0 && Y == 0) return "Possible";

    const int M = 10000;
    lli p3[M];
    p3[0] = 1;
    p3[1] = 3;
    for (int i = 1; i < M; ++i) {
      p3[i] = p3[i - 1] * 3LL;
    }

    queue<S> q;
    set<S> vis;
    S ini = (S){0, 0, 0};
    for (q.push(ini); q.size(); q.pop()) {
      S s = q.front();
      if (p3[s.k] < 0) { cout << "TEST" << endl; break; }
      S a = s;
      a.x += p3[s.k];
      ++a.k;
      S b = s;
      b.y += p3[s.k];
      ++b.k;
      S t[] = {a, b};
      for (int i = 0; i < 2; ++i) {
        if (t[i].x == X && t[i].y == Y) return "Possible";
        if (!vis.count(t[i])) {
          lli v = labs(Y - t[i].y);
          lli u = labs(X - t[i].x);
          lli mn = 1LL << 62;
          if (v) mn = min(mn, v);
          if (u) mn = min(mn, u);
          if (p3[t[i].k] <= mn) {
            vis.insert(t[i]);
            q.push(t[i]);
          }
        }
      }
    }
    return "Impossible";
  }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 3; string Arg2 = "Possible"; verify_case(0, Arg2, ableToGet(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 1; string Arg2 = "Impossible"; verify_case(1, Arg2, ableToGet(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 0; string Arg2 = "Impossible"; verify_case(2, Arg2, ableToGet(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 1; int Arg1 = 9; string Arg2 = "Impossible"; verify_case(3, Arg2, ableToGet(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 3; int Arg1 = 10; string Arg2 = "Possible"; verify_case(4, Arg2, ableToGet(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 1093; int Arg1 = 2187; string Arg2 = "Possible"; verify_case(5, Arg2, ableToGet(Arg0, Arg1)); }
	void test_case_6() { int Arg0 = 0; int Arg1 = 0; string Arg2 = "Possible"; verify_case(6, Arg2, ableToGet(Arg0, Arg1)); }

// END CUT HERE

};



// BEGIN CUT HERE

int main() {
  PowerOfThreeEasy ___test;
  ___test.run_test(-1);
}

// END CUT HERE
