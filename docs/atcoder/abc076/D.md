# atcoder/abc076/D

## Codes
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

int main(int argc, char *argv[])
{
  int n;
  while (cin >> n) {
    int t[n];
    int v[n];
    for (int i = 0; i < n; ++i) {
      cin >> t[i];
    }
    for (int i = 0; i < n; ++i) {
      cin >> v[i];
    }

    vector<pair<int, int>> range;
    int acc = 0;
    for (int i = 0; i < n; ++i) {
      range.push_back(make_pair(acc, acc + t[i]));
      acc += t[i];
    }
    
    const int N = (200 * 100 + 5) * 2;
    const double inf = 1e100;
    double x[N];
    fill(x, x + N, inf);
    for (int i = 0; i < n; ++i) {
      for (int j = range[i].first * 2; j <= range[i].second * 2; ++j) {
        x[j] = min<double>(x[j], v[i]);
      }
    }
    const int k = range.back().second * 2 + 1;
    assert(k < N);
    x[0] = 0;
    x[k - 1] = 0;
      
    for (int i = 0; i + 1 < N; ++i) {
      if (x[i] == N) {
        if (x[i - 1] == x[i + 1]) x[i] = x[i + 1];
        else x[i] = min(x[i - 1] + 0.5, x[i + 1] + 0.5);
      }
    }
    
    for (int i = 1; i - 1 < k; ++i) {
      x[i] = min({x[i - 1] + 0.5, x[i], x[i + 1] + 0.5});
    }
    for (int i = k - 2; 0 < i; --i) {
      x[i] = min({x[i - 1] + 0.5, x[i], x[i + 1] + 0.5});
    }
   
    double sum = 0;
    for (int i = 1; i < k; ++i) {
      if (x[i - 1] == x[i]) {
        sum += x[i - 1] * 0.5;
      } else {
        if (x[i - 1] < x[i]) {
          sum += (x[i - 1] * 0.5) + (0.5 * 0.5 * 0.5);
        } else {
          sum += (x[i - 1] * 0.5) - (0.5 * 0.5 * 0.5);
        }
      }
    }
    printf("%.10lf\n", sum);
  }

  return 0;
}
```
