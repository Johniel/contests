#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; each (i, v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { each (i, v) is >> i; return is; }

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    const int N = 100000 + 5;
    int dp[N];
    fill(dp, dp + N, 1 << 29);
    dp[0] = 0;

    vector<int> v({1});
    int x = 6;
    int y = 9;
    while (min(x, y) <= N) {
      v.push_back(x);
      v.push_back(y);
      x *= 6;
      y *= 9;
    }

    for (int i = 0; i < N; ++i) {
      each (j, v) {
        if (i + j < N) {
          dp[i + j] = min(dp[i + j], dp[i] + 1);
        }
      }
    }

    cout << dp[n] << endl;
  }
  
  return 0;
}
