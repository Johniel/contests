# ARC098C
リーダーの位置を決め打ちして、その左右にあるEとWの個数を累積和で数える。

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

struct Acc {
  vector<int> sum;
  Acc(vector<int> v) {
    sum.push_back(0);
    each (i, v) {
      sum.push_back(sum.back() + i);
    }
  }
  int query(int begin, int end) {
    return sum[end] - sum[begin];
  }
};

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  string s;
  while (cin >> n >> s) {
    vector<int> ve;
    vector<int> vw;
    each (c, s) {
      ve.push_back(c == 'E');
      vw.push_back(c == 'W');
    }
    
    Acc e(ve);
    Acc w(vw);

    int mn = 1 << 29;
    for (int i = 0; i < s.size(); ++i) {
      mn = min(mn, w.query(0, i) + e.query(i + 1, s.size()));
    }
    cout << mn << endl;
  }
  
  return 0;
}
```
