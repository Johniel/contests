#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

inline ull rhash(const string& s)
{
  ull h = 0;
  for (int i = 0; i < s.size(); ++i) {
    h = (h + (s[i] - '0' + 1)) * 41;
  }
  return h;
}

class Similars {
public:
  int maxsim(int L, int R)
  {
    // L = 1; R = 100000;
    map<ull, bool> vis;

    int mx = 0;

    char buff[1000];
    for (int b = L; b <= R; ++b) {
      sprintf(buff, "%d", b);
      string s(buff);
      sort(s.begin(), s.end());
      s.erase(unique(s.begin(), s.end()), s.end());
      vector<string> v;
      const int BIT = 1 << s.size();
      for (int bit = 0; bit < BIT; ++bit) {
        string t;
        for (int i = 0; i < s.size(); ++i) {
          if (bit & (1 << i)) {
            t += s[i];
          }
        }
        v.push_back(t);
      }
      for (int i = 0; i < v.size(); ++i) {
        if (vis[rhash(v[i])]) {
          mx = max<int>(mx, v[i].size());
        }
      }
      for (int i = 0; i < v.size(); ++i) {
        vis[rhash(v[i])] = true;
      }
    }
    return mx;
  }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 10; int Arg2 = 1; verify_case(0, Arg2, maxsim(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 99; int Arg2 = 2; verify_case(1, Arg2, maxsim(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 99; int Arg1 = 100; int Arg2 = 0; verify_case(2, Arg2, maxsim(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 1000; int Arg1 = 1010; int Arg2 = 2; verify_case(3, Arg2, maxsim(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 444; int Arg1 = 454; int Arg2 = 2; verify_case(4, Arg2, maxsim(Arg0, Arg1)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {
  Similars ___test;
  ___test.run_test(-1);
}

// END CUT HERE
