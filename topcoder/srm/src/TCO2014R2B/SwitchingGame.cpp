#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

pair<string, int> f(string s, string t)
{
  bool on2off = 0;
  bool off2on = 0;
  const int M = s.size();
  for (int i = 0; i < M; ++i) {
    if (t[i] == '?') {
    } else if (s[i] == t[i]) {
    } else if (s[i] != t[i]) {
      if (s[i] != '?') {
        if (s[i] == '+') on2off = true;
        if (s[i] == '-') off2on = true;
      }
      s[i] = t[i];
    }
  }
  for (int i = 0; i < M; ++i) {
    if (t[i] == '?' && s[i] == '-' && off2on) {
      s[i] = '?';
    }
    if (t[i] == '?' && s[i] == '+' && on2off) {
      s[i] = '?';
    }
  }
  return make_pair(s, on2off + off2on);
}

class SwitchingGame {
public:
  int timeToWin(vector <string> states)
  {
    const int M = states[0].size();
    states.insert(states.begin(), string(M, '-'));
    int sum = 0;
    for (int i = 0; i + 1 < states.size(); ++i) {
      pair<string, int> p = f(states[i], states[i + 1]);
      sum += p.second + 1;
      states[i + 1] = p.first;
    }
    return sum;
  }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2()
; if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end();
++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else
{ cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"++--",
 "--++"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(0, Arg1, timeToWin(Arg0)); }
	void test_case_1() { string Arr0[] = {"+-++",
 "+-++"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(1, Arg1, timeToWin(Arg0)); }
	void test_case_2() { string Arr0[] = {"++",
 "+?",
 "?+",
 "++"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(2, Arg1, timeToWin(Arg0)); }
	void test_case_3() { string Arr0[] = {"+",
 "?",
 "?",
 "?",
 "-"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(3, Arg1, timeToWin(Arg0)); }

	void test_case_4() { string Arr0[] = {"+??+++",
 "++??+-",
 "?++??+",
 "?-+-??",
 "??+?++",
 "++-?+?",
 "?++?-+",
 "?--+++",
 "-??-?+"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 20; verify_case(4, Arg1, timeToWin(Arg0)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {
  SwitchingGame ___test;
  ___test.run_test(-1);
}

// END CUT HERE
