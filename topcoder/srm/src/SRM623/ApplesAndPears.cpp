#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

class ApplesAndPears {
public:
  int getArea(vector <string> g, int K)
  {
    const string S = accumulate(g.begin(), g.end(), string(""));
    const int A = count(S.begin(), S.end(), 'A');
    const int P = count(S.begin(), S.end(), 'P');
    const int E = count(S.begin(), S.end(), '.');
    const int H = g.size();
    const int W = g[0].size();

    int mx = 0;
    for (int bi = 0; bi < H; ++bi) {
      for (int bj = 0; bj < W; ++bj) {
        for (int h = bi + 1; h <= H; ++h) {
          for (int w = bj + 1; w <= W; ++w) {
            int a = 0;
            int p = 0;
            int e = 0;
            for (int i = bi; i < h; ++i) {
              for (int j = bj; j < w; ++j) {
                a += (g[i][j] == 'A');
                p += (g[i][j] == 'P');
                e += (g[i][j] == '.');
              }
            }
            int ra = A - a;
            int rp = P - p;
            int re = E - e;
            if (set<int>({a, p, e}).count(a + p + e)) { // no move
              mx = max(mx, (h - bi) * (w - bj));
            }
            if (re >= a + p && a + p <= K) { // fill with empty
              mx = max(mx, (h - bi) * (w - bj));
            }
            if (E && ra >= e + p && e + p * 2 <= K) { // fill with apple
              mx = max(mx, (h - bi) * (w - bj));
            }
            if (E && rp >= e + a && e + a * 2 <= K) { // fill with pear
              mx = max(mx, (h - bi) * (w - bj));
            }
          }
        }
      }
    }
    return mx;
  }

// BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".A",
                                        "P."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 1; verify_case(0, Arg2, getArea(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {".A",
                                        "P."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2; verify_case(1, Arg2, getArea(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {".PP",
                                        "PPA",
                                        "PAP"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 6; verify_case(2, Arg2, getArea(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"A.P.PAAPPA",
                                        "PPP..P.PPP",
                                        "AAP.A.PAPA",
                                        "P.PA.AAA.A",
                                        "...PA.P.PA",
                                        "P..A.A.P..",
                                        "PAAP..A.A.",
                                        "PAAPPA.APA",
                                        ".P.AP.P.AA",
                                        "..APAPAA.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 21; verify_case(3, Arg2, getArea(Arg0, Arg1)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {
  ApplesAndPears ___test;
  ___test.run_test(-1);
}

// END CUT HERE
