#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

bool f(vector<vector<int>> v, vector<string> s, int idx)
{
  bool flg = true;
  for (int i = 0; i < v.size(); ++i) {
    for (int j = 0; j + 1 < v[i].size(); ++j) {
      flg = flg && (s[v[i][j]][idx] <= s[v[i][j + 1]][idx]);
    }
  }
  return flg;
}

vector<vector<int>> g(vector<vector<int>> v, vector<string> s, int idx)
{
  vector<vector<int>> u;
  for (int i = 0; i < v.size(); ++i) {
    vector<int> w(1, v[i][0]);
    for (int j = 0; j + 1 < v[i].size(); ++j) {
      if (s[v[i][j]][idx] != s[v[i][j + 1]][idx]) {
        u.push_back(w);
        w.clear();
      }
      w.push_back(v[i][j + 1]);
    }
    if (w.size()) u.push_back(w);
  }
  return u;
}

bool fin(vector<vector<int>> v)
{
  bool flg = true;
  for (int i = 0; i < v.size(); ++i) {
    for (int j = 0; j + 1 < v[i].size(); ++j) {
      flg = flg && (v[i][j] < v[i][j + 1]);
    }
  }
  return flg;
}

class CandidatesSelection {
public:
  string possible(vector <string> score, vector <int> result)
  {
    const string T = "Possible";
    const string F = "Impossible";
    const int N = score[0].size();
    set<int> vis;
    vector<vector<int>> v(1, result);
    while (!fin(v)) {
      int valid = -1;
      for (int i = 0; i < N; ++i) {
        if (!vis.count(i) && f(v, score, i)) {
          valid = i;
        }
      }
      if (valid == -1) {
        break;
      }
      v = g(v, score, valid);
      vis.insert(valid);
    }
    return fin(v) ? T : F;
  }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"CC", "AA", "BB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Possible"; verify_case(0, Arg2, possible(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"BAB", "ABB", "AAB", "ABA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,0,1,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Possible"; verify_case(1, Arg2, possible(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"BAB", "ABB", "AAB", "ABA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1, 3, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Impossible"; verify_case(2, Arg2, possible(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"AAA", "ZZZ"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Impossible"; verify_case(3, Arg2, possible(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"ZZZ", "AAA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Possible"; verify_case(4, Arg2, possible(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"ZYYYYX","YXZYXY","ZZZZXX","XZXYYX","ZZZYYZ","ZZXXYZ","ZYZZXZ","XZYYZX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3,7,1,0,2,5,6,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Possible"; verify_case(5, Arg2, possible(Arg0, Arg1)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {
  CandidatesSelection ___test;
  ___test.run_test(-1);
}

// END CUT HERE
