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
  int N, M, L;
  int P, Q, R;
  while (cin >> N >> M >> L >> P >> Q >> R) {
    vector<int> len;
    len.push_back(P);
    len.push_back(Q);
    len.push_back(R);

    int mx = 0;
    sort(len.begin(), len.end());
    do {
      int a = N / len[0];
      int b = M / len[1];
      int c = L / len[2];
      mx = max(mx, a * b * c);
    } while (next_permutation(len.begin(), len.end()));
    cout << mx << endl;
  }
  return 0;
}
