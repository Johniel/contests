// codeforces/547div3/F1/main.cpp
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

  int n;
  while (cin >> n) {
    vector<lli> v(n);
    cin >> v;

    map<int, vector<pair<int, int>>> m;
    for (int i = 0; i < v.size(); ++i) {
      int sum = 0;
      for (int j = i; j < v.size(); ++j) {
        sum += v[j];
        m[sum].push_back({i, j});
      }
    }

    each (i, m) {
      sort(i.second.begin(), i.second.end());
    }

    const int N = 50 * 50 + 5;
    int dp[N];
    int prev[N];
    vector<pair<int, int>> u;
    each (_, m) {
      auto& x = _.second;
      fill(dp, dp + N, 1);
      fill(prev, prev + N, -1);
      for (int i = 0; i < x.size(); ++i) {
        for (int j = i + 1; j < x.size(); ++j) {
          if (x[i].second < x[j].first) {
            if (dp[j] < dp[i] + 1) {
              dp[j] = dp[i] + 1;
              prev[j] = i;
            }
          }
        }
      }
      auto itr = max_element(begin(dp), end(dp));
      if (u.size() < *itr) {
        int curr = itr - dp;
        u.clear();
        while (curr != -1) {
          u.push_back(x[curr]);
          curr = prev[curr];
          assert(u.size() <= n);
        }
      }
    }

    cout << u.size() << endl;
    each (i, u) cout << i.first + 1 << ' ' << i.second + 1 << endl;
  }

  return 0;
}
