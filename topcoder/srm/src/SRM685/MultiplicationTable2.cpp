#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

template<typename P, typename Q>
ostream& operator << (ostream& os, pair<P, Q> p)
{
  os << "(" << p.first << "," << p.second << ")";
  return os;
}

const int inf = 1 << 28;

class MultiplicationTable2 {
public:
  int minimalGoodSet(vector <int> table)
  {
    const int n = sqrt(table.size());
    int g[n][n];
    map<pair<int, int>, int> name;
    for (int i = 0, k = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        g[i][j] = table[k++];
      }
    }
    int mn = inf;

    const int M = 55;

    bool vis[M];
    for (int src = 0; src < n; ++src) {
      fill(vis, vis + M, false);
      vis[src] = true;
      queue<int> q;
      for (q.push(src); q.size(); q.pop()) {
        int curr = q.front();
        for (int i = 0; i < n; ++i) {
          if (!vis[i]) continue;
          int x = g[curr][i];
          if (!vis[x]) {
            vis[x] = true;
            q.push(x);
          }
          int y = g[i][curr];
          if (!vis[y]) {
            vis[y] = true;
            q.push(y);
          }          
        }
      }
      mn = min<int>(mn, count(vis, vis + n, true));
    }
    
    return mn;
  }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,1,2,3,
 1,0,3,2,
 2,0,1,3,
 1,2,3,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, minimalGoodSet(Arg0)); }
	void test_case_1() { int Arr0[] = {0,1,2,3,
 1,2,3,0,
 2,3,0,1,
 3,0,1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, minimalGoodSet(Arg0)); }
	void test_case_2() { int Arr0[] = {1,1,1,1,
 2,2,2,2,
 3,3,3,3,
 0,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(2, Arg1, minimalGoodSet(Arg0)); }
	void test_case_3() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(3, Arg1, minimalGoodSet(Arg0)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {
  MultiplicationTable2 ___test;
  ___test.run_test(-1);
}

// END CUT HERE
