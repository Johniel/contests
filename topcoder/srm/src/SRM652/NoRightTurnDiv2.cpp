#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

namespace std {
  inline
  bool operator < (point a, point b){
    if(a.real() != b.real())return a.real() < b.real();
    return a.imag() < b.imag();
  }  
};

point normal(point v)
{
  return v * point(0, -1);
}
 
double dot(point a, point b)
{
  return (a.real() * b.real() + a.imag() * b.imag());
}
 
double cross(point a, point b)
{
  return (a.real() * b.imag() - a.imag() * b.real());
}

namespace CCW{
  enum{ RIGHT = 1, LEFT = -1, FRONT = -2, BACK = +2, OTHER = 0 };
};
int ccw(point a, point b, point c)
{
  b -= a;
  c -= a;
  if (cross(b, c) < 0) return CCW::RIGHT;
  if (cross(b, c) > 0) return CCW::LEFT;
  if (dot(b, c) < 0) return CCW::BACK;
  if (norm(b) < norm(c)) return CCW::FRONT;
  return CCW::OTHER;
}
 
class NoRightTurnDiv2 {
public:
  vector <int> findPath(vector <int> x, vector <int> y) 
  {
    const int N = x.size();
    vector<point> p(N);
    for (int i = 0; i < N; ++i) {
      p[i] = point(x[i], y[i]);
    }
    
    vector<int> v;
    v.push_back(0);

    for (int i = 0; i < N; ++i) {
      if (p[i] < p[v[0]]) {
        v[0] = i;
      }
    }

    bool used[N];
    fill(used, used + N, false);
    used[v[0]] = true;

    for (int i = 0; i < N - 1; ++i) {
      for (int j = 0; j < N; ++j) {
        if (used[j]) continue;
        bool f = true;
        for (int k = 0; k < N; ++k) {
          if (j == k) continue;
          if (used[k]) continue;
          f = f && (ccw(p[v[i]], p[j], p[k]) == CCW::LEFT);
        }
        if (f) {
          v.push_back(j);
          used[j] = true;
          break;
        }
      }
    }

    return v;
  }
  
// BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {-10, 0, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10, -10, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 1, 2 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, findPath(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {0,0,-3,-3,3,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1,1,-3,3,-3,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 4, 5, 3, 2, 1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, findPath(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {10,9,8,7,6,5,4,3,2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,4,9,16,25,36,49,64,81,100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, findPath(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {0, 2,-2, 4,-4, 2,-2, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 2, 4, 4, 6, 6, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {4, 2, 0, 1, 3, 5, 6, 7 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, findPath(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {-76,98,83,58,-15,94,21,55,80,84,-39,-90,-46,100,-80,-49,-2,-70,36,48,88,10,
                                     55,-56,22,67,31,81,100,-39,64,-62,-7,45,-82,-24,51,-33,53,11,20,-74,-83,47,
                                     9,39,42,63,-97,94}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-90,68,91,-92,-6,88,99,10,39,-69,-61,-4,71,-5,90,-51,21,-53,-21,-86,41,-9,
                                                                                                                                         42,-23,-4,12,94,-59,55,18,70,-88,-86,-17,-97,-33,87,80,91,-80,-79,-79,-78,
                                                                                                                                         -99,57,67,-52,-46,61,-10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {39, 32, 40, 31, 19, 27, 47, 46, 0, 34, 43, 3, 9, 13, 28, 1, 5, 2, 6, 14, 48, 42, 41, 49, 20, 38, 26, 37, 12, 11, 17, 10, 33, 25, 8, 30, 36, 44, 29, 23, 15, 18, 7, 22, 45, 16, 4, 35, 24, 21 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, findPath(Arg0, Arg1)); }

// END CUT HERE

};


// BEGIN CUT HERE

int main() {
  NoRightTurnDiv2 ___test;
  ___test.run_test(-1);
}

// END CUT HERE
