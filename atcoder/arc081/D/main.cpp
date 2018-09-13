#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;

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
    const int R = 0;
    const int G = 1;
    const int B = 2;
    vector<int> color({R, G, B});

    const int X = 8;
    const int Y = 9;

    string patt[2];
    cin >> patt[0] >> patt[1] ;

    const lli mod = 1000000007;

    const int N = 52 + 5;
    map<pair<int, int>, lli> dp[N];
    dp[0][make_pair(X, X)] = 1;

    for (int i = 0; i < n; ++i) {
      each (j, dp[i]) {
        const pair<int, int> p = j.first;
        if (patt[0][i] == patt[1][i]) {
          each (c, color) {
            unless (p.first == c || p.second == c) {
              // cout << i << "(|):" << p << "->" << make_pair(c, c) << endl;
              (dp[i + 1][make_pair(c, c)] += j.second) %= mod;
            }
          }
        } else {
          each (c, color) {
            each (d, color) {
              if (c == d) continue;
              unless (p.first == c || p.second == d) {
                // cout << i << "(=):" << p << "->" << make_pair(c, d) << endl;
                (dp[i + 2][make_pair(c, d)] += j.second) %= mod;
              }
            }
          }
        }
      }
    }

    lli sum = 0;
    each (i, dp[n]) {
      (sum += i.second) %= mod;
    }
    cout << sum << endl;
  }

  return 0;
}
