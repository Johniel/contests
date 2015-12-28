#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

struct E {
  int src, dst, cost, cap, rev;
  E(int _src, int _dst, int _cost, int _cap, int _rev)
    : src(_src), dst(_dst), cost(_cost), cap(_cap), rev(_rev) {}
};

const int V = 100 + 5;
vector<E> g[V];
int cost[V], h[V], prevv[V], preve[V];

const int inf = (1 << 28);

void add_edge(int src, int dst, int cost, int cap)
{
  g[src].push_back(E(src, dst,  cost, cap, (int)g[dst].size()));
  g[dst].push_back(E(dst, src, -cost,   0, (int)g[src].size() - 1));
  return ;
}

int min_cost_flow(int src, int snk, int req)
{
  int ret = 0;
  fill(h, h + V, 0);
  while (0 < req) {
    priority_queue<pair<int, int>> q;
    fill(cost, cost + V, inf);
    cost[src] = 0;
    for (q.push(make_pair(-0, src)); q.size(); ) {
      pair<int, int> p = q.top();
      q.pop();
      int v = p.second;
      int c = -p.first;
      if (cost[v] < c) continue;
      for (int i = 0; i < g[v].size(); ++i) {
        E& e = g[v][i];
        int d = cost[v] + e.cost + h[e.src] - h[e.dst];
        if (0 < e.cap && d < cost[e.dst]) {
          cost[e.dst] = d;
          prevv[e.dst] = v;
          preve[e.dst] = i;
          q.push(make_pair(-cost[e.dst], e.dst));
        }
      }
    }
    if (cost[snk] == inf) break;
    for (int i = 0; i < V; ++i) {
      h[i] += cost[i];
    }
    int d = req;
    for (int v = snk; v != src; v = prevv[v]) {
      d = min(d, g[prevv[v]][preve[v]].cap);
    }
    req -= d;
    ret += d * h[snk];
    for (int v = snk; v != src; v = prevv[v]) {
      E& e = g[prevv[v]][preve[v]];
      e.cap -= d;
      g[v][e.rev].cap += d;
    }
  }
  return ret;
}

class SpecialCells {
public:
  int guess(vector <int> x, vector <int> y)
  {
    fill(g, g + V, vector<E>());

    set<pair<int, int>> taboo;

    vector<int> a = x;
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    vector<int> b = y;
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());

    for (int i = 0; i < x.size(); ++i) {
      taboo.insert(make_pair(x[i], y[i]));
    }

    for (int i = 0; i < a.size(); ++i) {
      for (int j = 0; j < b.size(); ++j) {
        add_edge(i, j + a.size(), taboo.count(make_pair(a[i], b[j])), 1);
      }
    }

    const int src = a.size() + b.size();
    const int snk = a.size() + b.size() + 1;

    for (int i = 0; i < a.size(); ++i) {
      add_edge(src, i, 0, count(x.begin(), x.end(), a[i]));
    }

    for (int j = 0; j < b.size(); ++j) {
      add_edge(j + a.size(), snk, 0, count(y.begin(), y.end(), b[j]));
    }

    return min_cost_flow(src, snk, inf);
  }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(0, Arg2, guess(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1,1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(1, Arg2, guess(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1,2,1,2,1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,1,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; verify_case(2, Arg2, guess(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 9; verify_case(3, Arg2, guess(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {1,100000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,100000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(4, Arg2, guess(Arg0, Arg1)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {
  SpecialCells ___test;
  ___test.run_test(-1);
}

// END CUT HERE
