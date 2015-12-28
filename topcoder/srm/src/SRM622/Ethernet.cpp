#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

const int V = 60;
const int D = 550;
int memo[V][D];

int max_dist;
vector<pair<int, int>> g[V];

int rec(int curr, int limit)
{
  int& ret = memo[curr][limit];
  if (ret != -1) return ret;

  int mn = 1;
  each (e, g[curr]) {
    mn += rec(e.first, max_dist);
  }

  for (int i = 0; i < g[curr].size(); ++i) {
    int next = g[curr][i].first;
    int next_d = g[curr][i].second;
    for (int used = next_d; used <= limit; ++used) {
      int rem = min(used, max_dist - used);
      int sum = rec(next, used - next_d);
      for (int j = 0; j < g[curr].size(); ++j) {
        if (i == j) continue;
        int sibl = g[curr][j].first;
        int sibl_d = g[curr][j].second;
        if (sibl_d > rem) {
          int n = rec(sibl, max_dist);
          sum += n;
        } else {
          int n = rec(sibl, max_dist);
          int m = rec(sibl, rem - sibl_d) - 1;
          sum += min(n, m);
        }
      }
      mn = min(mn, sum);
    }
  }

  return ret = mn;
}

class Ethernet {
public:
  int connect(vector <int> parent, vector <int> dist, int maxDist)
  {
    max_dist = maxDist;
    fill(g, g + V, vector<pair<int, int>>());
    for (int i = 0; i < parent.size(); ++i) {
      int src = parent[i];
      int dst = i + 1;
      g[src].push_back(make_pair(dst, dist[i]));
    }
    fill(&memo[0][0], &memo[V - 1][D - 1] - 1, -1);
    return rec(0, maxDist);
  }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 1; verify_case(0, Arg3, connect(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {0,0,0,0,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,4,5,6,7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 8; int Arg3 = 4; verify_case(1, Arg3, connect(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {0,1,2,3,4,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,4,5,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; int Arg3 = 3; verify_case(2, Arg3, connect(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {0,0,0,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,1,1,1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 2; verify_case(3, Arg3, connect(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {0,1,0,3,0,5,0,6,0,6,0,6,4,6,9,4,5,5,2,5,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {93,42,104,105,59,73,161,130,30,81,62,93,131,133,139,5,13,34,25,111,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 162; int Arg3 = 11; verify_case(4, Arg3, connect(Arg0, Arg1, Arg2)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {
  Ethernet ___test;
  ___test.run_test(-1);
}

// END CUT HERE
