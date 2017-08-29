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

  lli q, h, s, d, n;
  while (cin >> q >> h >> s >> d >> n) {
    // q 0.25
    // h 0.5
    // s 1
    // d 2

    // q 1
    // h 2
    // s 4
    // d 8

    const lli inf = 1LL << 60;
    const int N = 10;
    lli dp[N];
    fill(dp, dp + N, inf);
    dp[0] = 0;

    vector<pair<int, int>> v;
    v.push_back(make_pair(1, q));
    v.push_back(make_pair(2, h));
    v.push_back(make_pair(4, s));
    v.push_back(make_pair(8, d));
    for (int i = 0; i < N; ++i) {
      each (j, v) {
        if (i + j.first < N) {
          dp[i + j.first] = min(dp[i + j.first], dp[i] + j.second);
        }
      }
    }

    lli sum = (n / 2) * dp[8];
    if (n % 2) sum += dp[4];
    cout << sum << endl;
  }
  
  return 0;
}
