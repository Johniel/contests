#include <bits/stdc++.h>

#define each(i, c) for(auto& i : c)
#define unless(cond) if(!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

class HappyLetterDiv2 {
public:
  char getHappyLetter(string s)
  {
    const int N = 300;
    pair<int, char> mx[N];
    for (char c = 'a'; c <= 'z'; ++c) {
      mx[(int)c] = make_pair(count(s.begin(), s.end(), c), c);
    }
    sort(mx, mx + N);

    return s.size() / 2 < mx[N - 1].first ? mx[N - 1].second : '.';
  }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const char &Expected, const char &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "aacaaa"; char Arg1 = 'a'; verify_case(0, Arg1, getHappyLetter(Arg0)); }
	void test_case_1() { string Arg0 = "dcdjx"; char Arg1 = '.'; verify_case(1, Arg1, getHappyLetter(Arg0)); }
	void test_case_2() { string Arg0 = "bcbbbbba"; char Arg1 = 'b'; verify_case(2, Arg1, getHappyLetter(Arg0)); }
	void test_case_3() { string Arg0 = "aabc"; char Arg1 = '.'; verify_case(3, Arg1, getHappyLetter(Arg0)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {
  HappyLetterDiv2 ___test;
  ___test.run_test(-1);
}

// END CUT HERE
