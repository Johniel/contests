#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

class PairGame {
public:
  int maxSum(int a, int b, int c, int d)
  {
    queue<pair<int, int>> q;

    set<pair<int, int>> vis1;
    vis1.insert(make_pair(a, b));
    for (q.push(make_pair(a, b)); q.size(); q.pop()) {
      pair<int, int> p = q.front();
      pair<int, int> s = make_pair(p.first - p.second, p.second);
      pair<int, int> t = make_pair(p.first, p.second - p.first);
      if (0 < s.first && vis1.count(s) == 0) {
        vis1.insert(s);
        q.push(s);
      }
      if (0 < t.second && vis1.count(t) == 0) {
        vis1.insert(t);
        q.push(t);
      }
    }

    set<pair<int, int>> vis2;
    vis2.insert(make_pair(c, d));
    for (q.push(make_pair(c, d)); q.size(); q.pop()) {
      pair<int, int> p = q.front();
      pair<int, int> s = make_pair(p.first - p.second, p.second);
      pair<int, int> t = make_pair(p.first, p.second - p.first);
      if (0 < s.first && vis2.count(s) == 0) {
        vis2.insert(s);
        q.push(s);
      }
      if (0 < t.second && vis2.count(t) == 0) {
        vis2.insert(t);
        q.push(t);
      }
    }

    int mx = -1;
    each (i, vis1) {
      if (vis2.count(i)) {
        mx = max(mx, (i.first + i.second));
      }
    }
    return mx;
  }

// BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { int Arg0 = 1; int Arg1 = 2; int Arg2 = 2; int Arg3 = 1; int Arg4 = 2; verify_case(0, Arg4, maxSum(Arg0, Arg1, Arg2, Arg3)); }
  void test_case_1() { int Arg0 = 15; int Arg1 = 4; int Arg2 = 10; int Arg3 = 7; int Arg4 = 7; verify_case(1, Arg4, maxSum(Arg0, Arg1, Arg2, Arg3)); }
  void test_case_2() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 10; int Arg3 = 10; int Arg4 = -1; verify_case(2, Arg4, maxSum(Arg0, Arg1, Arg2, Arg3)); }
  void test_case_3() { int Arg0 = 1000; int Arg1 = 1001; int Arg2 = 2000; int Arg3 = 2001; int Arg4 = 1001; verify_case(3, Arg4, maxSum(Arg0, Arg1, Arg2, Arg3)); }
  void test_case_4() { int Arg0 = 10944; int Arg1 = 17928; int Arg2 = 7704; int Arg3 = 21888; int Arg4 = 144; verify_case(4, Arg4, maxSum(Arg0, Arg1, Arg2, Arg3)); }
  void test_case_5() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 1; int Arg3 = 1; int Arg4 = 2; verify_case(5, Arg4, maxSum(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {
  PairGame ___test;
  ___test.run_test(-1);
}

// END CUT HERE
