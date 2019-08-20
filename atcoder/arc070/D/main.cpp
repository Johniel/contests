// atcoder/arc070/D/main.cpp
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

template<typename T>
struct PrefixSum {
  vector<T> sum;
  PrefixSum(vector<T> v) {
    sum.push_back(0);
    each (i, v) {
      sum.push_back(sum.back() + i);
    }
  }
  T query(size_t begin, size_t end) {
    return sum[end] - sum[begin];
  }
};

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  lli k;
  while (cin >> n >> k) {
    vector<lli> a(n);
    cin >> a;
    vector<lli> b = a;
    reverse(b.begin(), b.end());

    const int N = 5000 + 5;
    const int K = 5000 + 5;
    static bool dp1[N][K];
    static bool dp2[N][K];

    fill(&dp1[0][0], &dp1[N - 1][K - 1] + 1, false);
    fill(&dp2[0][0], &dp2[N - 1][K - 1] + 1, false);
    dp1[0][0] = dp2[0][0] = true;

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < K; ++j) {
        dp1[i + 1][j] |= dp1[i][j];
        dp2[i + 1][j] |= dp2[i][j];
        if (j + a[i] < K) dp1[i + 1][j + a[i]] |= dp1[i][j];
        if (j + b[i] < K) dp2[i + 1][j + b[i]] |= dp2[i][j];
      }
    }

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      if (k <= a[i]) {
        ++cnt;
        continue;
      }
      vector<lli> v1, v2;
      for (int j = 0; j < K; ++j) {
        v1.push_back(dp1[i][j]);
        v2.push_back(dp2[n - i - 1][j]);
      }
      PrefixSum<lli> ps1(v1);
      PrefixSum<lli> ps2(v2);
      bool f = false;
      for (int j = 0; j <= k - 1; ++j) {
        const int p = max<int>(0, k - a[i] - j);
        f = f || (dp1[i][j]         && ps2.query(p, k - j));
        f = f || (dp2[n - i - 1][j] && ps1.query(p, k - j));
      }
      cnt += f;
    }
    cout << n - cnt << endl;
  }

  return 0;
}
