#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

map<vector<int>, int> memo;
int rec(vector<int> v)
{
  if (memo.count(v)) {
    return memo[v];
  }
  if (count(v.begin(), v.end(), 0) == v.size()) {
    return 0;
  }

  int mx = -(1 << 29);
  const int N = v.size();
  for (int i = 0; i < N; ++i) {
    if (v[i]) {
      vector<int> u = v;
      u[max(i - 1, 0)] *= 2;
      u[min(i + 1, N - 1)] *= 2;
      u[i] = 0;
      mx = max(mx, v[i] - rec(u));
    }
  }

  return memo[v] = mx;
}

class EllysCandyGame {
public:
  string getWinner(vector <int> sweets)
  {
    memo.clear();
    int n = rec(sweets);
    if (0 < n) return "Elly";
    if (0 > n) return "Kris";
    return "Draw";
  }


};





// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
