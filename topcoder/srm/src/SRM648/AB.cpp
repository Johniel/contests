#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

int f(string s)
{
  int sum = 0;
  for (int i = 0; i < s.size(); ++i) {
    for (int j = i + 1; j < s.size(); ++j) {
      sum += (s[i] == 'A' && s[j] == 'B');
    }
  }
  return sum;
}

string bt(string s, int idx, const int K)
{
  if (idx == s.size()) {
    return f(s) == K ? s : "";
  }
  string t = s;
  t[idx] = 'A';
  int m = f(t);
  if (m == K) return t;
  return m <= K ? bt(t, idx + 1, K) : bt(s, idx +  1, K);
}

class AB {
public:
  string createString(int N, int K)
  {
    string t = bt(string(N, 'B'), 0, K);
    return f(t) == K ? t : "";
  }

// BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 2; string Arg2 = "ABB"; verify_case(0, Arg2, createString(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 0; string Arg2 = "BA"; verify_case(1, Arg2, createString(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 8; string Arg2 = ""; verify_case(2, Arg2, createString(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 10; int Arg1 = 12; string Arg2 = "BAABBABAAB"; verify_case(3, Arg2, createString(Arg0, Arg1)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {
  AB ___test;
  ___test.run_test(-1);
  for (int i = 1; i <= 50; ++i) {
  cout << i << endl;
    for (int j = 0; j <= 50; ++j) {
  cout << j << ' ' << ___test.createString(i, j) << endl;
    }
  }
}

// END CUT HERE
