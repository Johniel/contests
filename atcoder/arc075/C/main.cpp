#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

template<typename P, typename Q>
ostream& operator << (ostream& os, pair<P, Q> p)
{
  os << "(" << p.first << "," << p.second << ")";
  return os;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    vector<int> v(n);
    each (i, v) cin >> i;

    const int N = 100 * 100 + 1;
    bool dp[N];
    fill(dp, dp + N, false);
    dp[0] = true;

    each (i, v) {
      for (int j = N - 1; 0 <= j; --j) {
        if (dp[j]) {
          dp[j + i] = true;
        }
      }
    }
    
    lli mx = 0;
    for (int i = 0; i < N; ++i) {
      if (i % 10 && dp[i]) mx = i;
    }
    cout << mx << endl;
  }
  
  return 0;
}
