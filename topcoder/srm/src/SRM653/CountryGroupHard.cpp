#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;


const int N = 100 + 10;
int memo[N];

vector<int> a;

int rec(int idx)
{
  if (a.size() == idx) return 1;
  if (a.size() < idx) return 0;
  int& ret = memo[idx];
  if (ret != -1) return ret;

  int sum = 0;

  for (int i = 1; idx + i <= a.size(); ++i) {
    bool f = true;
    for (int j = idx; j < idx + i; ++j) {
      f = f && (a[j] == 0 || a[j] == i);
    }
    if (f) sum += rec(idx + i);
  }
  return ret = min(sum, 7);
}

class CountryGroupHard {
public:
  string solve(vector <int> a_)
  {
    a = a_;
    fill(memo, memo + N, -1);
    int n = rec(0);
    return n == 1 ? "Sufficient" : "Insufficient";
  }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,2,3,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Sufficient"; verify_case(0, Arg1, solve(Arg0)); }
	void test_case_1() { int Arr0[] = {0,2,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Insufficient"; verify_case(1, Arg1, solve(Arg0)); }
	void test_case_2() { int Arr0[] = {0,3,0,0,3,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Sufficient"; verify_case(2, Arg1, solve(Arg0)); }
	void test_case_3() { int Arr0[] = {0,0,3,3,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Insufficient"; verify_case(3, Arg1, solve(Arg0)); }
	void test_case_4() { int Arr0[] = {2,2,0,2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Sufficient"; verify_case(4, Arg1, solve(Arg0)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {
  CountryGroupHard ___test;
  ___test.run_test(-1);
}

// END CUT HERE
