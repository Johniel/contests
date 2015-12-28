#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

bool possible(string s)
{
  map<char, int> cnt;
  for (int i = 0; i < s.size(); ++i) {
    ++cnt[s[i]];
  }

  int odd = 0;
  for (char c = 'a'; c <= 'z'; ++c) {
    if (cnt[c] % 2) ++odd;
  }

  return (s.size() % 2 == 0 && odd == 0) || (s.size() % 2 == 1 && odd == 1);
}

const int N = 100;
double nck[N][N];
double fact[N];
void init()
{
  for (int i = 0; i < N; ++i) {
    nck[i][i] = nck[i][0] = 1;
  }
  for (int i = 1; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      nck[i][j] = nck[i - 1][j - 1] + nck[i - 1][j];
    }
  }

  fact[0] = 1;
  for (int i = 1; i < N; ++i) {
    fact[i] = fact[i - 1] * (double)i;
  }
  return ;
}

class PalindromePermutations {
public:
  double palindromeProbability(string s)
  {
    init();
    if (!possible(s)) return 0.0;

    int odd = 1;
    map<char, int> cnt;
    for (char c = 'a'; c <= 'z'; ++c) {
      cnt[c] = count(s.begin(), s.end(), c);
      if (cnt[c] % 2) {
        odd = cnt[c];
        cnt[c] -= 1;
      }
    }

    int sum = 0;
    for (char c = 'a'; c <= 'z'; ++c) {
      if (cnt[c] % 2 == 0 && cnt[c]) {
        sum += cnt[c] / 2;
      }
    }

    double mul = 1;
    for (char c = 'a'; c <= 'z'; ++c) {
      if (cnt[c] % 2 == 0 && cnt[c]) {
        int a = cnt[c];
        int b = cnt[c] / 2;
        mul *= nck[a][b] * fact[b];
      }
    }

    return mul / fact[s.size()] * fact[sum] * odd;
  }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "haha"; double Arg1 = 0.3333333333333333; verify_case(0, Arg1, palindromeProbability(Arg0)); }
	void test_case_1() { string Arg0 = "xxxxy"; double Arg1 = 0.2; verify_case(1, Arg1, palindromeProbability(Arg0)); }
	void test_case_2() { string Arg0 = "xxxx"; double Arg1 = 1.0; verify_case(2, Arg1, palindromeProbability(Arg0)); }
	void test_case_3() { string Arg0 = "abcde"; double Arg1 = 0.0; verify_case(3, Arg1, palindromeProbability(Arg0)); }
	void test_case_4() { string Arg0 = "hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhff"; double Arg1 = 0.025641025641025637; verify_case(4, Arg1, palindromeProbability(Arg0)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {
  PalindromePermutations ___test;
  ___test.run_test(-1);
}

// END CUT HERE
