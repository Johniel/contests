#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

class CatchTheBeatEasy {
public:
  string ableToCatchAll(vector <int> x, vector <int> y)
  {
    const int N = x.size();
    vector<pair<int, int>> v;
    for (int i = 0; i < N; ++i) {
      v.push_back(make_pair(x[i], y[i]));
    }
    sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b){
        if (a.second != b.second) return a.second < b.second;
        return a.first < b.first;
      });
    v.insert(v.begin(), make_pair(0, 0));
    bool flg = true;
    for (int i = 0; i < N; ++i) {
      int diff = abs(v[i].second - v[i + 1].second);
      if (diff < abs(v[i].first - v[i + 1].first)) {
        flg = false;
      }
    }
    return flg ? "Able to catch" : "Not able to catch";
  }


};




// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
