# codeforces/457div2/B

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
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  lli n, k;
  while (cin >> n >> k) {
    const int N = 70;
    map<int, int> cnt;
    for (int i = 0; i < 60; ++i) {
      cnt[i] = 0;
      if (n & (1LL << i)) {
        cnt[i] = 1;
      }
    }
    int sum = 0;
    each (i, cnt) sum += i.second;
    for (int i = N - 1; -N < i; --i) {
      if (k < sum + cnt[i]) break;
      sum += cnt[i];
      cnt[i - 1] += cnt[i] + cnt[i];
      cnt[i] = 0;
    }
    vector<int> v;
    for (int i = -N; i < N; ++i) {
      for (int j = 0; j < cnt[i]; ++j) {
        v.push_back(i);
      }
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    while (v.size() < k) {
      int x = v.back();
      v.pop_back();
      v.push_back(x - 1);
      v.push_back(x - 1);
    }
    if (v.size() == k) {
      cout << "Yes" << endl;
      each (i, v) cout << i << ' ';
      cout << endl;
    } else {
      cout << "No" << endl;
    }
  }
  
  return 0;
}
```
