#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

bool f(vector<int> cnt, int target)
{
  if (cnt[target] == 0) return false;

  const int T = cnt[target];
  cnt.erase(cnt.begin() + target);

  sort(cnt.begin(), cnt.end());
  reverse(cnt.begin(), cnt.end());

  while (cnt[1]) {
    --cnt[0];
    --cnt[1];
    sort(cnt.begin(), cnt.end());
    reverse(cnt.begin(), cnt.end());
  }

  return *max_element(cnt.begin(), cnt.end()) < T;
}

class HappyLetterDiv1 {
public:
  string getHappyLetters(string s)
  {
    const int N = 300;
    vector<int> cnt(N);
    for (int i = 0; i < s.size(); ++i) {
      cnt[s[i]] = count(s.begin(), s.end(), s[i]);
    }

    string ret = "";
    for (int i = 0; i < N; ++i) {
      if (f(cnt, i)) ret += i;
    }

    return ret;
  }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "aabbacccc"; string Arg1 = "abc"; verify_case(0, Arg1, getHappyLetters(Arg0)); }
	void test_case_1() { string Arg0 = "aaaaaaaccdd"; string Arg1 = "a"; verify_case(1, Arg1, getHappyLetters(Arg0)); }
	void test_case_2() { string Arg0 = "ddabccadb"; string Arg1 = "abcd"; verify_case(2, Arg1, getHappyLetters(Arg0)); }
	void test_case_3() { string Arg0 = "aaabbb"; string Arg1 = ""; verify_case(3, Arg1, getHappyLetters(Arg0)); }
	void test_case_4() { string Arg0 = "rdokcogscosn"; string Arg1 = "cos"; verify_case(4, Arg1, getHappyLetters(Arg0)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {
  HappyLetterDiv1 ___test;
  ___test.run_test(-1);
}

// END CUT HERE
