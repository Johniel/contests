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
  const int N = 10000 + 100;
  char buff[N];
  while (scanf("%s\n", buff) == 1) {
    const int n = strlen(buff);
    bool dp[N];
    fill(dp, dp + N, false);
    dp[n] = true;
    for (int i = N - 1; 3 <= i; --i) {
      dp[i - 2] |= dp[i];
      dp[i - 3] |= dp[i];
    }
    fill(dp, dp + 5, false);
    set<string> suff;
    for (int i = 0; i < n; ++i) {
      if (dp[i] && dp[i + 2]) suff.insert(string("") + buff[i] + buff[i + 1]);
      if (dp[i] && dp[i + 3]) suff.insert(string("") + buff[i] + buff[i + 1] + buff[i + 2]);
    }
    printf("%d\n", (int)suff.size());
    cout << n << endl;
    // each (i, suff) puts(i.c_str());
  }
  return 0;
}
