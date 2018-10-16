# ABC106 D
ある都市から別都市へのパスの本数に関する累積和をN個作ると1クエリをO(N)でさばけるようになる。

累積和を２次元に拡張すればクエリをO(1)で処理することもできる。

## Codes
main.cpp
{% raw %}{{
```cpp
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
ostream& operator << (ostream& os, vector<T> v)
{
  os << "(";
  each (i, v) os << i << ",";
  os << ")";
  return os;
}

struct Acc {
  vector<lli> sum;
  Acc(vector<lli> v) {
    sum.push_back(0);
    each (i, v) {
      sum.push_back(sum.back() + i);
    }
  }
  lli query(lli begin, lli end) {
    return sum[end] - sum[begin];
  }
};

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m, q;
  while (cin >> n >> m >> q) {
    vector<lli> g[n];
    fill(g, g + n, vector<lli>(n, 0));

    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      ++g[a][b];
    }

    vector<Acc> v;
    for (int i = 0; i < n; ++i) {
      v.push_back(Acc(g[i]));
    }

    while (q--) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      lli sum = 0;
      for (int i = a; i <= b; ++i) {
        sum += v[i].query(a, b + 1);
      }
      cout << sum << endl;
    }
  }
  
  return 0;
}
}}{% endraw %}
```
main2.cpp
{% raw %}{{
```cpp
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
ostream& operator << (ostream& os, vector<T> v)
{
  os << "(";
  each (i, v) os << i << ",";
  os << ")";
  return os;
}

struct Acc2D {
  vector<vector<lli>> sum;
  Acc2D(vector<vector<lli>> v) {
    const int N = v.size() + 1;
    sum.resize(N);
    fill(sum.begin(), sum.end(), vector<lli>(N, 0));
    for (int i = 0; i < v.size(); ++i) {
      for (int j = 0; j < v.size(); ++j) {
        sum[i + 1][j + 1] = v[i][j];
      }
    }
    for (int i = 1; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        sum[i][j] += sum[i - 1][j];
      }
    }
    for (int i = 0; i < N; ++i) {
      for (int j = 1; j < N; ++j) {
        sum[i][j] += sum[i][j - 1];
      }
    }
  }
  lli query(int ai, int aj, int bi, int bj) {
    return sum[bi][bj] + sum[ai][aj] - sum[ai][bj] - sum[bi][aj];
  }
};

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m, q;
  while (cin >> n >> m >> q) {
    vector<vector<lli>> g(n);
    fill(g.begin(), g.end(), vector<lli>(n, 0));

    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      ++g[a][b];
    }

    Acc2D acc(g);
    while (q--) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      cout << acc.query(a, a, b + 1, b + 1) << endl;
    }
  }
  
  return 0;
}
}}{% endraw %}
```
---
+ [toppage](https://johniel.github.io/contests/)
+ [index](https://johniel.github.io/contests/docs/atcoder)
+ [repository](https://github.com/Johniel/contests/tree/master/atcoder/abc106/D)
{% endraw %}
