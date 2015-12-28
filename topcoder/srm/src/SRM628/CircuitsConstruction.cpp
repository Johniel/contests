#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

class CircuitsConstruction {
public:
  int maximizeResistance(string cir, vector <int> cond)
  {
    const int N = cir.size();

    reverse(cir.begin(), cir.end());

    stack<int> s;
    for (int i = 0; i < N; ++i) {
      if (cir[i] == 'X') {
        s.push(1);
      }
      if (cir[i] == 'A') {
        int a = s.top(); s.pop();
        int b = s.top(); s.pop();
        s.push(a + b);
      }
      if (cir[i] == 'B') {
        int a = s.top(); s.pop();
        int b = s.top(); s.pop();
        s.push(max(a, b));
      }
    }

    sort(cond.begin(), cond.end());
    reverse(cond.begin(), cond.end());
    return accumulate(cond.begin(), cond.begin() + s.top(), 0);
  }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "BXBXX"; int Arr1[] = {8, 2, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 8; verify_case(0, Arg2, maximizeResistance(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "AAXXAXAXX"; int Arr1[] = {1, 1, 2, 8, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 22; verify_case(1, Arg2, maximizeResistance(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "AXBXX"; int Arr1[] = {8, 2, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 11; verify_case(2, Arg2, maximizeResistance(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "BAAXBXXBXAXXBBAXXBXXAAXXX"; int Arr1[] = {17, 7, 21, 102, 56, 72, 88, 15, 9, 192, 16, 8, 30}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 454; verify_case(3, Arg2, maximizeResistance(Arg0, Arg1)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {
  CircuitsConstruction ___test;
  ___test.run_test(-1);
}

// END CUT HERE
