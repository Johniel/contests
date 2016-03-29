#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;


class BracketSequenceDiv1 {
public:
  long long count(string s)
  {
    lli sum = 0;
    const int n = s.size() / 2;
    map<string, lli> cnt;
    for (int bit = 0; bit < (1 << n); ++bit) {
      string t;
      bool f = true;
      for (int i = 0; i < n; ++i) {
        if ((1 << i) & bit) {
          if (t.empty()) {
            if (s[i] == '(' || s[i] == '[') t += s[i];
            else f = false;
          } else if ((t.back() == '(' && s[i] == ')') ||
                     (t.back() == '[' && s[i] == ']')) {
            t.pop_back();
          } else if ((t.back() == '(' || t.back() == '[') && (s[i] == '(' || s[i] == '[')) {
            t += s[i];
          } else {
            f = false;
          }
        }
      }
      cnt[t] += f;
    }
    s = s.substr(n);
    each (c, s) {
      if (0) ;
      else if (c == '(') c = ')';
      else if (c == '[') c = ']';
      else if (c == ')') c = '(';
      else if (c == ']') c = '[';      
    }
    reverse(s.begin(), s.end());
    for (int bit = 0; bit < (1 << s.size()); ++bit) {
      string t;
      bool f = true;
      for (int i = 0; i < s.size(); ++i) {
        if ((1 << i) & bit) {
          if (t.empty()) {
            if (s[i] == '(' || s[i] == '[') t += s[i];
            else f = false;
          } else if ((t.back() == '(' && s[i] == ')') || (t.back() == '[' && s[i] == ']')) {
            t.pop_back();
          } else if ((t.back() == '(' || t.back() == '[') && (s[i] == '(' || s[i] == '[')) {
            t += s[i];
          } else {
            f = false;
          }
        }
      }
      sum += cnt[t] * f;
    }
    return sum - 1;
  }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "()[]"; long long Arg1 = 3LL; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { string Arg0 = "())"; long long Arg1 = 2LL; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { string Arg0 = "()()"; long long Arg1 = 4LL; verify_case(2, Arg1, count(Arg0)); }
	void test_case_3() { string Arg0 = "([)]"; long long Arg1 = 2LL; verify_case(3, Arg1, count(Arg0)); }
	void test_case_4() { string Arg0 = "())[]][]([]()]]()]]]"; long long Arg1 = 3854LL; verify_case(4, Arg1, count(Arg0)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {
  BracketSequenceDiv1 ___test;
  ___test.run_test(-1);
}

// END CUT HERE
