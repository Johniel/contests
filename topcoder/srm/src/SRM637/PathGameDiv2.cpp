#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

int f(int i, int j, vector<string> g)
{
  int cnt = 0;
  const int W = g[0].size();
  while (j < W) {
    g[i][j] = '@';
    ++cnt;
    if (g[i][j + 1] == '#') i = i ^ 1;
    else ++j;
  }
  return cnt;
}

class PathGameDiv2 {
public:
  int calc(vector <string> g)
  {
    int black = 0;
    for (int i = 0; i < g.size(); ++i) {
      black += count(g[i].begin(), g[i].end(), '.');
    }

    const int x = (g[0][0] == '.') ? f(0, 0, g) : (1 << 29);
    const int y = (g[1][0] == '.') ? f(1, 0, g) : (1 << 29);

    return black - min(x, y);
  }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"#...."
,"...#."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, calc(Arg0)); }
	void test_case_1() { string Arr0[] = {"#"
,"."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, calc(Arg0)); }
	void test_case_2() { string Arr0[] = {"."
,"."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, calc(Arg0)); }
	void test_case_3() { string Arr0[] = {"....#.##.....#..........."
,"..#......#.......#..#...."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 13; verify_case(3, Arg1, calc(Arg0)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {
  PathGameDiv2 ___test;
  ___test.run_test(-1);
}

// END CUT HERE
