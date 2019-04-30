# EDPC: N

区間を考える。その区間で最後に合体させる位置を選択する。合計値の計算は累積和で持つと `O(N^3)` になる。

```
// dp[i番目][j番目] := iからjまで全てを合体させる場合の最適値
// sum(x,y)を、x番目からy番目までのスライムの大きさの総和とすると、
dp[i][j] = min(dp[i][k] + dp[k][j] + sum(i,k) + sum(k,j))
```

## Codes
main.cpp
{% raw %}
```cpp
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

struct Acc {
  vector<lli> sum;
  Acc() {}
  void init(vector<lli> v) {
    sum.clear();
    sum.push_back(0);
    each (i, v) {
      sum.push_back(sum.back() + i);
    }
    return ;
  }
  lli query(lli begin, lli end) {
    return sum[end] - sum[begin];
  }
};
Acc acc;

vector<lli> a;
const int N = 4000 + 5;
lli memo[N][N];
lli rec(int begin, int end)
{
  lli& ret = memo[begin][end];
  if (ret != -1) return ret;
  if (begin + 1 == end) return 0;

  lli mn = 1LL << 60;
  for (int i = begin + 1; i < end; ++i) {
    setmin(mn, rec(begin, i) + rec(i, end) + acc.query(begin, i) + acc.query(i, end));
  }

  return ret = mn;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    a.resize(n);
    cin >> a;
    acc.init(a);

    fill(&memo[0][0], &memo[N - 1][N - 1] + 1, -1);
    cout << rec(0, n) << endl;
  }

  return 0;
}
```
{% endraw %}
---
+ [toppage](https://johniel.github.io/contests/)
+ [index](https://johniel.github.io/contests/docs/atcoder)
+ [repository](https://github.com/Johniel/contests/tree/master/atcoder/edpc/N)
