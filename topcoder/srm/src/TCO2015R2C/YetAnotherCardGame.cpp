#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;


const int N = 55;
int num[2][N];

int C = 0;
int memo[N][N][N][N];

int rec(int a, int b, int i, int j)
{
  if (a < 0 || b < 0) return -(1 << 29);
  const int turn = (C * 2) - a - b;
  const int prev = num[i][j];

  if ((turn % 2 == 0) && a == 0) return 0;
  if ((turn % 2 == 1) && b == 0) return 0;

  int& ret = memo[a][b][i][j];
  if (ret != -1) return ret;

  int mx = (turn % 2) ? rec(a, b - 1, i, j) : rec(a - 1, b, i, j);
  for (int k = 0; k < N; ++k) {
    if (prev < num[turn % 2][k]) {
      const int x = rec(a, b - 1, turn % 2, k) + 1;
      const int y = rec(a - 1, b, turn % 2, k) + 1;
      mx = max(mx, (turn % 2) ? x : y);
    }
  }

  return ret = mx;
}

class YetAnotherCardGame {
public:
  int maxCards(vector <int> x, vector <int> y)
  {
    C = x.size();
    fill(&num[0][0], &num[2 - 1][N - 1], -1);
    x.push_back(0);
    y.push_back(0);
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    for (int i = 0; i < x.size(); ++i) {
      num[0][i] = x[i];
      num[1][i] = y[i];
    }

    fill(&memo[0][0][0][0], &memo[N - 1][N - 1][N - 1][N - 1], -1);
    return rec(x.size() - 1, y.size() - 1, 0, 0);
  }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(0, Arg2, maxCards(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1, 1, 1, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1, 1, 1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(1, Arg2, maxCards(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1, 4, 6, 7, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 7, 1, 5, 7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; verify_case(2, Arg2, maxCards(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {19, 99, 86, 30, 98, 68, 73, 92, 37, 69, 93, 28, 58, 36, 86, 32, 46, 34, 71, 29}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {28, 29, 22, 75, 78, 75, 39, 41, 5, 14, 100, 28, 51, 42, 9, 25, 12, 59, 98, 83}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 28; verify_case(3, Arg2, maxCards(Arg0, Arg1)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {
  YetAnotherCardGame ___test;
  ___test.run_test(-1);
}

// END CUT HERE
