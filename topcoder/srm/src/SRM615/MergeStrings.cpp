#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

struct St {
  string cost;
  size_t i, j;
  St(string _cost, size_t _i, size_t _j) : cost(_cost), i(_i), j(_j) {}
};
bool operator < (const St& a, const St& b)
{
  if (a.cost.size() < b.cost.size()) return a.cost.size() > b.cost.size();
  return a.cost > b.cost;
}

class MergeStrings {
public:
  string getmin(string S, string A, string B)
  {
    priority_queue<St> q;
    map<pair<int, int>, string> cost;
    for (q.push(St("", 0, 0)); q.size(); ) {
      St s = q.top();
      q.pop();
      if (cost[make_pair(s.i, s.j)] < s.cost) continue;
      if (s.i < A.size() && (S[s.i + s.j] == '?' || S[s.i + s.j] == A[s.i])) {
        St t = s;
        t.cost += A[t.i];
        ++t.i;
        pair<int, int> p = make_pair(t.i, t.j);
        if (!cost.count(p) || t.cost < cost[p]) {
          cost[p] = t.cost;
          q.push(t);
        }
      }
      if (s.j < B.size() && (S[s.i + s.j] == '?' || S[s.i + s.j] == B[s.j])) {
        St t = s;
        t.cost += B[t.j];
        ++t.j;
        pair<int, int> p = make_pair(t.i, t.j);
        if (!cost.count(p) || t.cost < cost[p]) {
          cost[p] = t.cost;
          q.push(t);
        }
      }
    }
    pair<int, int> p = make_pair(A.size(), B.size());
    if (cost.count(p)) return cost[p];
    return "";
  }
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "??CC??"; string Arg1 = "ABC"; string Arg2 = "BCC"; string Arg3 = "ABCCBC"; verify_case(0, Arg3, getmin(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "WHAT?"; string Arg1 = "THE"; string Arg2 = "WA"; string Arg3 = ""; verify_case(1, Arg3, getmin(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "PARROT"; string Arg1 = "PARROT"; string Arg2 = ""; string Arg3 = "PARROT"; verify_case(2, Arg3, getmin(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "???????????"; string Arg1 = "AZZAA"; string Arg2 = "AZAZZA"; string Arg3 = "AAZAZZAAZZA"; verify_case(3, Arg3, getmin(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "????K??????????????D???K???K????????K?????K???????"; string Arg1 = "KKKKKDKKKDKKDDKDDDKDKK"; string Arg2 = "KDKDDKKKDDKDDKKKDKDKKDDDDDDD"; string Arg3 = "KDKDKDKKKDDKDDKKKDKDKKDKDDDKDDDKKDKKKDKKDDKDDDKDKK"; verify_case(4, Arg3, getmin(Arg0, Arg1, Arg2)); }
// END CUT HERE
};
// BEGIN CUT HERE
int main() {
  MergeStrings ___test;
  ___test.run_test(-1);
}
// END CUT HERE
