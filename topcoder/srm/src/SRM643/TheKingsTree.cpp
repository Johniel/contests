#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

const int N = 55;
vector<int> g[N];

int memo[N][N][N];

int rec(int curr, int r, int b)
{
  int& ret = memo[curr][r][b];
  if (ret != -1) return ret;

  int p = r + 1;
  each (next, g[curr]) p += rec(next, r + 1, b);

  int q = b + 1;
  each (next, g[curr]) q += rec(next, r, b + 1);

  return ret = min(p, q);
}

class TheKingsTree {
public:
  int getNumber(vector <int> P)
  {
    P.insert(P.begin(), -1);
    fill(g, g + N, vector<int>());
    for (int i = 0; i < P.size(); ++i) {
      g[P[i]].push_back(i);
    }
    fill(&memo[0][0][0], &memo[N - 1][N - 1][N - 1] + 1, -1);
    return rec(0, 0, 0);
  }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(0, Arg1, getNumber(Arg0)); }
	void test_case_1() { int Arr0[] = {0, 1, 2, 3, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(1, Arg1, getNumber(Arg0)); }
	void test_case_2() { int Arr0[] = {0, 1, 2, 3, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(2, Arg1, getNumber(Arg0)); }
	void test_case_3() { int Arr0[] = {0, 0, 1, 0, 4, 3, 5, 2, 0, 7, 9, 2, 4, 5, 3, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 26; verify_case(3, Arg1, getNumber(Arg0)); }
	void test_case_4() { int Arr0[] = {}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(4, Arg1, getNumber(Arg0)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {
  TheKingsTree ___test;
  ___test.run_test(-1);
}

// END CUT HERE
