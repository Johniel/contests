#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

class EmoticonsDiv1 {
public:
  int printSmiles(int smiles)
  {
    const int inf = (1 << 29);
    const int N = 1000 + 10;
    int cost[N][N];
    fill(&cost[0][0], &cost[N - 1][N - 1] + 1, inf);
    cost[1][0] = 0;

    queue<pair<int, int>> q;
    for (q.push(make_pair(1, 0)); q.size(); q.pop()) {
      pair<int, int> p = q.front();
      if (p.first && cost[p.first - 1][p.second] == inf) {
        cost[p.first - 1][p.second] = cost[p.first][p.second] + 1;
        q.push(make_pair(p.first - 1, p.second));
      }
      if (cost[p.first][p.first] == inf) {
        cost[p.first][p.first] = cost[p.first][p.second] + 1;
        q.push(make_pair(p.first, p.first));
      }
      if (p.first + p.second < N && cost[p.first + p.second][p.second] == inf) {
        cost[p.first + p.second][p.second] = cost[p.first][p.second] + 1;
        q.push(make_pair(p.first + p.second, p.second));
      }
    }

    int mn = inf;
    for (int i = 0; i < N; ++i) {
      mn = min(mn, cost[smiles][i]);
    }
    return mn;
  }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; verify_case(0, Arg1, printSmiles(Arg0)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 4; verify_case(1, Arg1, printSmiles(Arg0)); }
	void test_case_2() { int Arg0 = 6; int Arg1 = 5; verify_case(2, Arg1, printSmiles(Arg0)); }
	void test_case_3() { int Arg0 = 18; int Arg1 = 8; verify_case(3, Arg1, printSmiles(Arg0)); }
	void test_case_4() { int Arg0 = 11; int Arg1 = 8; verify_case(4, Arg1, printSmiles(Arg0)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {
  EmoticonsDiv1 ___test;
  ___test.run_test(-1);
}

// END CUT HERE
