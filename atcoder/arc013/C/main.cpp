#include <algorithm>
#include <complex>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()
#define each(i, c) FOR(i, c)

#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

int main(int argc, char *argv[])
{
  int N;
  while (cin >> N) {
    vector<int> v;

    for (int i = 0; i < N; ++i) {
      int a, b, c;
      int M;
      cin >> a >> b >> c >> M;
      vector<int> d, e, f;
      for (int j = 0; j < M; ++j) {
        int x, y, z;
        cin >> x >> y >> z;
        d.push_back(x);
        e.push_back(y);
        f.push_back(z);
      }
      v.push_back(*min_element(d.begin(), d.end()));
      v.push_back(*min_element(e.begin(), e.end()));
      v.push_back(*min_element(f.begin(), f.end()));
      v.push_back(a - *max_element(d.begin(), d.end()) - 1);
      v.push_back(b - *max_element(e.begin(), e.end()) - 1);
      v.push_back(c - *max_element(f.begin(), f.end()) - 1);
    }
    int nim = 0;
    for (int i = 0; i < v.size(); ++i) {
      if (v[i]) nim ^= v[i];
    }
    cout << (nim ? "WIN" : "LOSE") << endl;
  }
  return 0;
}
