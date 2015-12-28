#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

class GoodCompanyDivTwo {
public:
  int countGood(vector <int> superior, vector <int> workType)
  {
    int ret = 0;
    const int N = superior.size();
    for (int i = 0; i < N; ++i) {
      set<int> vis;
      int cnt = 1;
      vis.insert(workType[i]);
      for (int j = 0; j < N; ++j) {
        if (superior[j] == i) {
          vis.insert(workType[j]);
          ++cnt;
        }
      }
      ret += (vis.size() == cnt);
    }
    return ret;
  }


};




// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
