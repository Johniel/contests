#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

const int V = 2000 + 5;
vector<pair<int, int>> g[V];
vector<int> h[V];

const int inf = 1 << 28;
int min_cost[V];

void sssp(void)
{
  fill(min_cost, min_cost + V, inf);
  min_cost[0] = 0;

  priority_queue<pair<int, int>> q;

  for (q.push(make_pair(0, 0)); q.size(); ) {
    int cost = -q.top().first;
    int curr =  q.top().second;
    q.pop();
    if (min_cost[curr] != cost) continue;
    each (e, g[curr]) {
      int next = e.first;
      int dist = e.second;
      if (min_cost[next] > min_cost[curr] + dist) {
        min_cost[next] = min_cost[curr] + dist;
        q.push(make_pair(-min_cost[next], next));
        h[next].clear();
      }
      if (min_cost[next] == min_cost[curr] + dist) {
        h[next].push_back(curr);
      }
    }
  }
  return ;
}

bool has0[V];

const int mod = 1000000009;

int memo[V];
int rec(int curr, int dst)
{
  if (has0[curr]) throw "";
  if (curr == dst) return 1;
  if (memo[curr] != -1) return memo[curr];
  int sum = 0;
  for (int i = 0; i < h[curr].size(); ++i) {
    int next = h[curr][i];
    (sum += rec(next, dst)) %= mod;
  }
  return memo[curr] = sum;
}

class DrivingPlans {
public:
  int count(int N, vector <int> A, vector <int> B, vector <int> C)
  {
    const int E = A.size();

    for (int i = 0; i < E; ++i) {
      --A[i];
      --B[i];
    }

    fill(g, g + V, vector<pair<int, int>>());
    fill(h, h + V, vector<int>());
    fill(has0, has0 + V, false);

    for (int i = 0; i < E; ++i) {
      g[A[i]].push_back(make_pair(B[i], C[i]));
      g[B[i]].push_back(make_pair(A[i], C[i]));
      if (!C[i]) {
        has0[A[i]] = has0[B[i]] = true;
      }
    }

    sssp();

    try {
      fill(memo, memo + V, -1);
      return rec(N - 1, 0);
    } catch (const char* str) {
      return -1;
    }
  }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arr1[] = {1,1,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,3,4,4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,1,1,1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 2; verify_case(0, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 4; int Arr1[] = {1,1,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,3,4,4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,1,1,0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = -1; verify_case(1, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 7; int Arr1[] = {1,1,2,3,4,4,5,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,3,4,4,5,6,7,7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,1,2,2,3,3,4,4}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 4; verify_case(2, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {
  DrivingPlans ___test;
  ___test.run_test(-1);
}

// END CUT HERE
