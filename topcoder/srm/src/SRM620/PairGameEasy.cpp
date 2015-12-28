#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

class PairGameEasy {
public:
  string able(int a, int b, int c, int d)
  {
    const int N = 1000 + 1;
    static bool vis[N][N];
    fill(&vis[0][0], &vis[N - 1][N - 1] + 1, false);
    vis[a][b] = true;
    queue<pair<int, int>> q;
    for (q.push(make_pair(a, b)); q.size(); q.pop()) {
      pair<int, int> p = q.front();
      int m = p.first + p.second;
      unless (m < N) continue;
      if (!vis[p.first][m]) {
        q.push(make_pair(p.first, m));
        vis[p.first][m] = true;
      }
      if (!vis[m][p.second]) {
        q.push(make_pair(m, p.second));
        vis[m][p.second] = true;
      }
    }
    return vis[c][d] ? "Able to generate" : "Not able to generate";
  }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 2; int Arg2 = 3; int Arg3 = 5; string Arg4 = "Able to generate"; verify_case(0, Arg4, able(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 2; int Arg2 = 2; int Arg3 = 1; string Arg4 = "Not able to generate"; verify_case(1, Arg4, able(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 2; int Arg3 = 999; string Arg4 = "Not able to generate"; verify_case(2, Arg4, able(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 2; int Arg3 = 1000; string Arg4 = "Able to generate"; verify_case(3, Arg4, able(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 47; int Arg1 = 58; int Arg2 = 384; int Arg3 = 221; string Arg4 = "Able to generate"; verify_case(4, Arg4, able(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arg0 = 1000; int Arg1 = 1000; int Arg2 = 1000; int Arg3 = 1000; string Arg4 = "Able to generate"; verify_case(5, Arg4, able(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {
  PairGameEasy ___test;
  ___test.run_test(-1);
}

// END CUT HERE
