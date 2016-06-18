#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef complex<double> point;

template<typename P, typename Q>
ostream& operator << (ostream& os, pair<P, Q> p)
{
  os << "(" << p.first << "," << p.second << ")";
  return os;
}

namespace std {
  bool operator < (point a, point b)
  {
    if (a.real() != b.real()) return a.real() < b.real();
    return a.imag() < b.imag();
  }
};

int gcd(int a, int b)
{
  if (a < b) swap(a, b);
  return b ? gcd(a%b, b) : a;
}

class BearBall {
public:
  int countThrows(vector <int> x, vector <int> y) 
  {
    const int N = x.size();
    int C = 0;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        C += abs(i - j);
      }
    }
    bool f = false;
    
    int ret = 0;
    for (int i = 0; i < N; ++i) {
      map<point, int> angle;
      for (int j = 0; j < N; ++j) {
        if (i == j) continue;
        int dx = x[j] - x[i];
        int dy = y[j] - y[i];
        int d = gcd(abs(dx), abs(dy));
        dx /= d;
        dy /= d;
        ++angle[point(dx, dy)];
      }
      if (angle.size() == 1) f = true;
      each (j, angle) ret += 1 + (j.second - 1) * 2;
    }

    if (f) return C;
    return ret;
  }
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,4,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,10,7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; verify_case(0, Arg2, countThrows(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {0,0,0,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1,2,0,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 22; verify_case(1, Arg2, countThrows(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {5,7,9,11}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4,3,2,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 20; verify_case(2, Arg2, countThrows(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {10,10,50,50,90,90}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5,17,5,17,5,17}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 34; verify_case(3, Arg2, countThrows(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {-100, -90, -80, -70, -85, -90, 0, 20}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-5, -8, -13, -21, -13, -13, -13, -69}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 68; verify_case(4, Arg2, countThrows(Arg0, Arg1)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {
  BearBall ___test;
  ___test.run_test(-1);
}

// END CUT HERE
