#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

bool f(vector <int> pos, vector <int> cnt, int time)
{
  int lower = *min_element(pos.begin(), pos.end()) - time;
  for (int i = 0; i < pos.size(); ++i) {
    lower = max(lower, pos[i] - time);
    for (int j = 0; j < cnt[i]; ++j) {
      if (pos[i] + time < lower) return false;
      lower++;
    }
  }
  return true;
}

class CatsOnTheLineDiv2 {
public:
  string getAnswer(vector <int> pos, vector <int> cnt, int time)
  {
    int N = pos.size();
    vector<pair<int, int>> v;
    for (int i = 0; i < N; ++i) {
      v.push_back(make_pair(pos[i], cnt[i]));
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < N; ++i) {
      pos[i] = v[i].first;
      cnt[i] = v[i].second;
    }

    bool tmp = f(pos, cnt, time);
    reverse(pos.begin(), pos.end());
    reverse(cnt.begin(), cnt.end());
    return (tmp || f(pos, cnt, time)) ? "Possible" : "Impossible";
  }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2();
 if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); +
+iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl;
else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) /
 sizeof(Arr1[0]))); int Arg2 = 3; string Arg3 = "Possible"; verify_case(0, Arg3, getAnswer(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) /
 sizeof(Arr1[0]))); int Arg2 = 2; string Arg3 = "Impossible"; verify_case(1, Arg3, getAnswer(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {0, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1)
                                                                                                                                                                   / sizeof(Arr1[0]))); int Arg2 = 0; string Arg3 = "Impossible"; verify_case(2, Arg3, getAnswer(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {5, 0, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 3, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; string Arg3 = "Impossible"; verify_case(3, Arg3, getAnswer(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {5, 1, -10, 7, 12, 2, 10, 20}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3, 4, 2, 7, 1, 4, 3, 4};
 vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; string Arg3 = "Possible"; verify_case(4, Arg3, getAnswer(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE

int main() {
  CatsOnTheLineDiv2 ___test;
  ___test.run_test(-1);
}

// END CUT HERE
