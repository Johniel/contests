#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

class ChooseTheBestOne {
public:
  int countNumber(int N)
  {
    vector<int> v;
    for (int i = 0; i < N; ++i) {
      v.push_back(i + 1);
    }
    int idx = 0;
    for (lli turn = 1; 1 < v.size(); ++turn) {
      idx = (idx + (turn * turn * turn) - 1) % v.size();
      v.erase(v.begin() + idx);
    }
    return v[0];
  }


};




// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
