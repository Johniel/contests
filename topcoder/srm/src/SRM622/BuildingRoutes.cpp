#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

class BuildingRoutes {
public:
  int build(vector <string> dist, int T)
  {
    const int N = dist.size();
    int g[N][N];
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        g[i][j] = dist[i][j] - '0';
      }
    }
    for (int k = 0; k < N; ++k) {
      for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
          g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
        }
      }
    }

    int sum = 0;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        if (dist[i][j] - '0' != g[i][j]) continue;
        int cnt = 0;
        for (int a = 0; a < N; ++a) {
          for (int b = 0; b < N; ++b) {
            cnt += (g[a][b] == g[a][i] + g[i][j] + g[j][b]);
          }
        }
        sum += (T <= cnt) * (dist[i][j] - '0');
      }
    }
    return sum;
  }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"011",
 "101",
 "110"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 6; verify_case(0, Arg2, build(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"033",
 "309",
 "390"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 12; verify_case(1, Arg2, build(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"0123",
 "1023",
 "1203",
 "1230"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 5; verify_case(2, Arg2, build(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"05789654",
 "10347583",
 "65085479",
 "55602398",
 "76590934",
 "57939045",
 "12345608",
 "68647640"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 40; verify_case(3, Arg2, build(Arg0, Arg1)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {
  BuildingRoutes ___test;
  ___test.run_test(-1);
}

// END CUT HERE
