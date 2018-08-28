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

template<typename T>
class BIT {
public:
  BIT(int n_)
  {
    n = n_;
    bit.resize(n + 1, 0);
  }
  T sum(int i)
  {
    assert(0 <= i);
    return _sum(i + 1);
  }
  void add(int i, T x)
  {
    assert(0 <= i);
    return _add(i + 1, x);
  }
private:
  vector<T> bit;
  int n;
  T _sum(int i)
  {
    T s = 0;
    while (i > 0) {
      s += bit[i];
      i -= i & -i;
    }
    return s;
  }
  void _add(int i, T x)
  {
    while (i <= n) {
      bit[i] += x;
      i += i & -i;
    }
    return ;
  }
};

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    vector<pair<char, int>> v(n * 2);
    each (i, v) {
      cin >> i.first >> i.second;
      --i.second;
    }

    vector<int> w(n);
    vector<int> b(n);
    for (int i = 0; i < v.size(); ++i) {
      if (v[i].first == 'B') b[v[i].second] = i;
      else w[v[i].second] = i;
    }

    const int inf = 1 << 27;
    const int N = 2000 + 5;
    static int dp[N][N];
    fill(&dp[0][0], &dp[N - 1][N - 1] + 1, inf);
    dp[0][0] = 0;

    BIT<int> bit(2 * n + 5);
    for (int i = 0; i < v.size(); ++i) {
      bit.add(i, 1);
    }

    for (int i = 0; i <= n; ++i) {
      BIT<int> tmp = bit;
      for (int j = 0; j <= n; ++j) {
        const int k = i + j;
        if (i < n) dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + (w[i] ? bit.sum(w[i] - 1) : 0));
        if (j < n) dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + (b[j] ? bit.sum(b[j] - 1) : 0));
        if (j < n) bit.add(b[j], -1);
      }
      bit = tmp;
      if (i < n) bit.add(w[i], -1);
    }

    cout << min(dp[n - 1][n], dp[n][n - 1]) << endl;
  }

  return 0;
}
