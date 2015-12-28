#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

class ConnectingGameDiv2 {
public:
  int getmin(vector <string> b)
  {
    const int H = b.size();
    const int W = b[0].size();

    map<char, int> weight;
    each (c, accumulate(b.begin(), b.end(), string(""))) {
      ++weight[c];
    }

    priority_queue<tuple<int, int, int>> q;

    int cost[H][W];
    fill(&cost[0][0], &cost[H - 1][W - 1] + 1, (1 << 29));

    for (int i = 0; i < H; ++i) {
      q.push(make_tuple<int, int, int>(-1 * weight[b[i][0]], (int)i, 0));
    }

    while (q.size()) {
      const int c = -1 * get<0>(q.top());
      const int i = get<1>(q.top());
      const int j = get<2>(q.top());
      q.pop();
      if (cost[i][j] < c) continue;
      cost[i][j] = c;
      const int D = 8;
      const int di[D] = {-1, -1, -1, 0, 0, +1, +1, +1};
      const int dj[D] = {-1, 0, +1, -1, +1, -1, 0, +1};
      for (int d = 0; d < D; ++d) {
        int ni = i + di[d];
        int nj = j + dj[d];
        unless (0 <= ni && ni < H) continue;
        unless (0 <= nj && nj < W) continue;
        int nc = (b[i][j] != b[ni][nj]) ? c + weight[b[ni][nj]] : c;
        if (cost[ni][nj] > nc) {
          cost[ni][nj] = nc;
          q.push(make_tuple(-nc, ni, nj));
        }
      }
    }

    int mn = (1 << 28);
    for (int i = 0; i < H; ++i) {
      mn = min(mn, cost[i][W - 1]);
    }

    return mn;
  }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"AA"
,"BC"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, getmin(Arg0)); }
	void test_case_1() { string Arr0[] = {"AAB"
,"ACD"
,"CCD"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(1, Arg1, getmin(Arg0)); }
	void test_case_2() { string Arr0[] = {"iii"
,"iwi"
,"iii"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(2, Arg1, getmin(Arg0)); }
	void test_case_3() { string Arr0[] = {"rng58"
,"Snuke"
,"Sothe"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(3, Arg1, getmin(Arg0)); }
	void test_case_4() { string Arr0[] = {"yyAArJqjWTH5","yyEEruYYWTHG","hooEvutpkkb2","OooNgFFF9sbi","RRMNgFL99Vmm","R76XgFF9dVVV","SKnZUPf88Vee"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 14; verify_case(4, Arg1, getmin(Arg0)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {
  ConnectingGameDiv2 ___test;
  ___test.run_test(-1);
}

// END CUT HERE
