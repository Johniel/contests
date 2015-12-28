#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

const int H = 4;
const int W = 4;
int g[H][W];

int f()
{
  int a = 0;
  const int D = 4;
  const int di[] = {0, 0, -1, +1};
  const int dj[] = {-1, +1, 0, 0};
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      for (int d = 0; d < D; ++d) {
        int ni = i + di[d];
        int nj = j + dj[d];
        if (0 <= ni && ni < H && 0 <= nj && nj < W) {
          a += max(0, g[i][j] - g[ni][nj]);
        }
      }
    }
  }
  a += 16;
  for (int i = 0; i < H; ++i) {
    a += g[i][0];
    a += g[i][W - 1];
  }
  for (int j = 0; j < W; ++j) {
    a += g[0][j];
    a += g[H -1][j];
  }
  return a;
}

class SixteenBricks {
public:
  int maximumSurface(vector <int> h)
  {
    sort(h.begin(), h.end());

    g[0][0] = h.back(); h.pop_back();
    g[3][3] = h.back(); h.pop_back();

    g[0][2] = h.back(); h.pop_back();
    g[1][3] = h.back(); h.pop_back();
    g[2][0] = h.back(); h.pop_back();
    g[3][1] = h.back(); h.pop_back();

    g[1][1] = h.back(); h.pop_back();
    g[2][2] = h.back(); h.pop_back();

    int mx = 0;
    sort(h.begin(), h.end());
    do {
      int k = 0;
      for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
          if ((i + j) % 2) {
            g[i][j] = h[k++];
          }
        }
      }
      mx = max(mx, f());
    } while (next_permutation(h.begin(), h.end()));
    return mx;
  }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 32; verify_case(0, Arg1, maximumSurface(Arg0)); }
	void test_case_1() { int Arr0[] = {1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 64; verify_case(1, Arg1, maximumSurface(Arg0)); }
	void test_case_2() { int Arr0[] = {77, 78, 58, 34, 30, 20, 8, 71, 37, 74, 21, 45, 39, 16, 4, 59}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1798; verify_case(2, Arg1, maximumSurface(Arg0)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {
  SixteenBricks ___test;
  ___test.run_test(-1);
}

// END CUT HERE
