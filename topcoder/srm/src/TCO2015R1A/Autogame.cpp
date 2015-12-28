#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

const lli mod = 1000000007;

const int N = 55;
int g[N][N];

const int inf = 1 << 29;

class Autogame {
public:
  int wayscnt(vector <int> a, const int K)
  {
    const int M = a.size();

    set<vector<int>> vis;
    vector<int> v;
    for (int i = 0; i < M; ++i) {
      v.push_back(i);
    }
    int k = K;
    while (vis.count(v) == 0 && k--) {
      vis.insert(v);
      for (int i = 0; i < v.size(); ++i) {
        v[i] = a[v[i]] - 1;
      }
    }

    lli ret = 1;
    map<int, int> cnt;
    for (int i = 0; i < v.size(); ++i) {
      ++cnt[v[i]];
    }
    vector<lli> u;
    each (p, cnt) {
      u.push_back(p.second + 1);
    }
    each (i, u) {
      ret *= i % mod;
      ret %= mod;
    }

    return ret;
    // return (ret * (1LL << u.size())) % mod;
  }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 8; verify_case(0, Arg2, wayscnt(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 4; verify_case(1, Arg2, wayscnt(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {2,1}	; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 42; int Arg2 = 4; verify_case(2, Arg2, wayscnt(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {2,3,4,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 9; verify_case(3, Arg2, wayscnt(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {4,4,3,2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 18; verify_case(4, Arg2, wayscnt(Arg0, Arg1)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {
  Autogame ___test;
  ___test.run_test(-1);
}

// END CUT HERE
