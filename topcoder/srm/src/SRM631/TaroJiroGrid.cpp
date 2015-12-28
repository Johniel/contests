#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

bool valid(vector<string> g)
{
  const int N = g.size();


  for (int j = 0; j < N; ++j) {
    int cnt = 1;
    for (int i = 1; i < N; ++i) {
      if (g[i - 1][j] != g[i][j]) cnt = 0;
      ++cnt;
      if (N / 2 < cnt) return false;
    }
  }

  return true;
}

class TaroJiroGrid {
public:
  int getNumber(vector <string> g)
  {
    if (valid(g)) return 0;

    const int N = g.size();

    for (int i = 0; i < N; ++i) {
      each (c, string("WB")) {
        vector<string> f = g;
        for (int j = 0; j < N; ++j) {
          f[i][j] = c;
        }
        if (valid(f)) return 1;
      }
    }

    return 2;
  }

// BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { string Arr0[] = {"WB",
                                        "BB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, getNumber(Arg0)); }
  void test_case_1() { string Arr0[] = {"WB",
                                        "WW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, getNumber(Arg0)); }
  void test_case_2() { string Arr0[] = {"WB",
                                        "WB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, getNumber(Arg0)); }
  void test_case_3() { string Arr0[] = {"WBBW",
                                        "WBWB",
                                        "WWBB",
                                        "BWWW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(3, Arg1, getNumber(Arg0)); }
  void test_case_4() { string Arr0[] = {"WBBWBB",
                                        "BBWBBW",
                                        "WWBWBW",
                                        "BWWBBB",
                                        "WBWBBW",
                                        "WWWBWB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(4, Arg1, getNumber(Arg0)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {
  TaroJiroGrid ___test;
  ___test.run_test(-1);
}

// END CUT HERE
