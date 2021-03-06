// atcoder/abc118/D/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

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

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  while (cin >> n >> m) {
    vector<int> a(m);
    cin >> a;
    map<int, int> x;
    x[1] = 2;
    x[2] = 5;
    x[3] = 5;
    x[4] = 4;
    x[5] = 5;
    x[6] = 6;
    x[7] = 3;
    x[8] = 7;
    x[9] = 6;

    const int N = 1e4 + 5;
    pair<int, int> dp[N];
    fill(dp, dp + N, make_pair(-2, -2));
    dp[n] = make_pair(0, -1);
    for (int i = n; 0 <= i; --i) {
      unless (0 <= dp[i].first) continue;
      each (j, a) {
        int rem = i - x[j];
        if (0 <= rem) {
          setmax(dp[rem], make_pair(dp[i].first + 1, j));
        }
      }
    }

    int idx = 0;
    vector<int> v;
    while (0 <= dp[idx].second) {
      v.push_back(dp[idx].second);
      idx += x[dp[idx].second];
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    each (i, v) cout << i;
    cout << endl;
  }

  return 0;
}
