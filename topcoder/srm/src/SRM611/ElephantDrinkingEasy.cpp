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

int f(const vector<string>& G, int A, int B, int C, int D)
{
  const int H = G.size();
  const int W = G[0].size();
  int g[H][W];
  fill(&g[0][0], &g[H - 1][W - 1] + 1, 0);

  // |
  // v
  for (int w = 0; w < W; ++w) {
    if (A & (1 << w)) {
      bool flg = false;
      for (int h = 0; h < H; ++h) {
        ++g[h][w];
        if (G[h][w] == 'Y') {
          flg = true;
          break;
        }
      }
      if (!flg) return 0;
    }
  }

  // ->
  for (int h = 0; h < H; ++h) {
    if (B & (1 << h)) {
      bool flg = false;
      for (int w = 0; w < W; ++w) {
        ++g[h][w];
        if (G[h][w] == 'Y') {
          flg = true;
          break;
        }
      }
      if (!flg) return 0;
    }
  }

  // ^
  // |
  for (int w = 0; w < W; ++w) {
    if (C & (1 << w)) {
      bool flg = false;
      for (int h = H - 1; 0 <= h; --h) {
        ++g[h][w];
        if (G[h][w] == 'Y') {
          flg = true;
          break;
        }
      }
      if (!flg) return 0;
    }
  }

  // <-
  for (int h = 0; h < H; ++h) {
    if (D & (1 << h)) {
      bool flg = false;
      for (int w = W - 1; 0 <= w; --w) {
        ++g[h][w];
        if (G[h][w] == 'Y') {
          flg = true;
          break;
        }
      }
      if (!flg) return 0;
    }
  }

  if (2 <= *max_element(&g[0][0], &g[H - 1][W - 1] + 1)) {
    return 0;
  }

  return __builtin_popcount(A) + __builtin_popcount(B) + __builtin_popcount(C) + __builtin_popcount(D);
}

class ElephantDrinkingEasy {
public:
  int maxElephants(vector <string> G)
  {
    const int N = G.size();
    vector<int> v;
    for (int bit = 0; bit < (1 << N); ++bit) {
      v.push_back(bit);
    }

    int mx = 0;

    const int M = v.size();
    for (int i = 0; i < M; ++i) {
      for (int j = 0; j < M; ++j) {
        for (int k = 0; k < M; ++k) {
          for (int l = 0; l < M; ++l) {
            mx = max(mx, f(G, v[i], v[j], v[k], v[l]));
          }
        }
      }
    }
    return mx;
  }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"NNNNN",
 "NNYYN",
 "NYNNN",
 "NNYNN",
 "NNNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(0, Arg1, maxElephants(Arg0)); }
	void test_case_1() { string Arr0[] = {"YYY",
 "YYY",
 "YYY"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(1, Arg1, maxElephants(Arg0)); }
	void test_case_2() { string Arr0[] =  {"YNYN",
  "NNYY",
  "YYNN",
  "YYYY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(2, Arg1, maxElephants(Arg0)); }
	void test_case_3() { string Arr0[] =  {"YNYN",
  "YNYY",
  "YYNN",
  "YYYY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(3, Arg1, maxElephants(Arg0)); }
	void test_case_4() { string Arr0[] = {"YYNYN",
 "NYNNY",
 "YNYNN",
 "YYNYY",
 "YYNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(4, Arg1, maxElephants(Arg0)); }
	void test_case_5() { string Arr0[] = {"YYNYN",
 "NYNYY",
 "YNYYN",
 "YYNYY",
 "YYNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 13; verify_case(5, Arg1, maxElephants(Arg0)); }
	void test_case_6() { string Arr0[] = {"NN",
 "NN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(6, Arg1, maxElephants(Arg0)); }

// END CUT HERE

};



// BEGIN CUT HERE

int main() {
  ElephantDrinkingEasy ___test;
  ___test.run_test(-1);
}

// END CUT HERE
