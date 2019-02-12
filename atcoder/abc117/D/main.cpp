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

  int n;
  lli k;
  while (cin >> n >> k) {
    vector<lli> a(n);
    cin >> a;

    if (k == 0) {
      cout << accumulate(a.begin(), a.end(), 0LL) << endl;
      continue;
    }
    
    map<int, int> cnt;
    each (i, a) {
      for (int j = 0; j < 63; ++j) {
        if (i & (1LL << j)) ++cnt[j];
      }
    }

    const int N = 62;
    lli dp[N][2];
    fill(&dp[0][0], &dp[N - 1][2 - 1] + 1, -(1LL << N));
    dp[0][false] = 0;
    const int M = N - 2;
    for (int i = 0; i <= M; ++i) {
      lli x = 1LL << (M - i);
      lli w = cnt[M - i];
      setmax(dp[i + 1][0], dp[i][0] + x * w);
      if (k < x) continue;
      for (int j = 0; j < 2; ++j) {
        if (j) {
          setmax(dp[i + 1][j], dp[i][j] + x * max(w, n - w));
        } else {
          if (k & x) {
            // 0
            setmax(dp[i + 1][1], dp[i][0] + x * w);
            // 1
            setmax(dp[i + 1][0], dp[i][0] + x * (n - w));
          } else {
            // 0
            setmax(dp[i + 1][0], dp[i][0] + x * w);
            // 1
          }
        }
      }
    }

    cout << *max_element(&dp[0][0], &dp[N - 1][2 - 1] + 1) << endl;
  }

  return 0;
}
