#include <algorithm>
#include <complex>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <vector>

#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()
#define each(i, c) FOR(i, c)

#define VAR(a) cout << #a << " : " << a << endl;
#define LOG()  cout << __LINE__ << ", " << __func__ << endl;

typedef long long int lli;

using namespace std;

int main(int argc, char *argv[])
{
  int n;
  while (cin >> n) {
    vector<string> v;
    while (n--) {
      string s;
      cin >> s;
      reverse(s.begin(), s.end());
      v.push_back(s);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < (int)v.size(); ++i) {
      reverse(v[i].begin(), v[i].end());
    }
    for (int i = 0; i < (int)v.size(); ++i) {
      cout << v[i] << endl;
    }
  }
  return 0;
}
