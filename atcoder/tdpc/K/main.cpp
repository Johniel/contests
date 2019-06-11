// atcoder/tdpc/K/main.cpp
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
vector<T> LIS(const T num[], const int size)
{
  const int inf = 1 << 28;
  T dp[size];
  int idx[size];
  int len = -inf;
  fill(dp, dp + size, inf);
  for (int i = 0; i < size; ++i) {
    idx[i] = lower_bound(dp, dp + size, num[i]) - dp;
    dp[idx[i]] = num[i];
  }
  len = *max_element(idx, idx + size);
  vector<T> result(len + 1);
  for (int i = 0; i < size; ++i) {
    if (idx[size - 1 - i] == len) {
      result[len--] = num[size - 1 - i];
    }
  }
  return result;
}

static const int N = 100000 + 5;
int num[N];

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    vector<pair<int, int>> v(n);
    cin >> v;
    sort(v.begin(), v.end(), [] (auto i, auto j) {
      if (i.first - i.second != j.first - j.second) return i.first - i.second < j.first - j.second;
      return i.first + i.second < j.first + j.second;
    });

    for (int i = 0; i < n; ++i) {
      num[i] = -(v[i].first + v[i].second);
    }

    vector<int> u = LIS<int>(num, n);
    cout << u.size() << endl;
  }

  return 0;
}
