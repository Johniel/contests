# codeforces/443div2/C

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

  int n;
  while (cin >> n) {
    vector<pair<char, int>> v(n);
    each (i, v) cin >> i.first >> i.second;

    const int N = 10;
    int x[N];
    const int _0 = 0;
    const int _1 = 1;
    const int K = 2;
    const int R = 3;
    fill(x, x + N, K);

    each (i, v) {
      if (i.first == '|') {
        for (int j = 0; j < N; ++j) {
          if (i.second & (1 << j)) {
            x[j] = _1;
          }
        }
      }
      if (i.first == '&') {
        for (int j = 0; j < N; ++j) {
          unless (i.second & (1 << j)) {
            x[j] = _0;
          }
        }
      }
      if (i.first == '^') {
        for (int j = 0; (1 << j) <= i.second; ++j) {
          if (i.second & (1 << j)) {
            if (0) ;
            else if (x[j] == K) x[j] = R;
            else if (x[j] == R) x[j] = K;
            else if (x[j] == _0) x[j] = _1;
            else if (x[j] == _1) x[j] = _0;
          }
        }
      }
    }

    // for (int i = 0; i < N; ++i) {
    //   if (x[i] == _0) cout << 0 ;
    //   if (x[i] == _1) cout << 1 ;
    //   if (x[i] == K) cout << 'K' ;
    //   if (x[i] == R) cout << 'R' ;
    // }
    // cout << endl;
    
    vector<pair<char, int>> u;
    { // and
      int a = 1024 - 1;
      for (int i = 0; i < N; ++i) {
        if (x[i] == _0) {
          a -= (1 << i);
        }
      }
      u.push_back(make_pair('&', a));
    }
    { // or
      int a = 0;
      for (int i = 0; i < N; ++i) {
        if (x[i] == _1) {
          a |= (1 << i);
        }
      }
      u.push_back(make_pair('|', a));
    }
    { // reverse
      int a = 0;
      for (int i = 0; i < N; ++i) {
        if (x[i] == R) {
          a |= (1 << i);
        }
      }
      u.push_back(make_pair('^', a));
    }

    cout << u.size() << endl;
    each (i, u) cout << i.first << ' ' << i.second << endl;
    
  }
  
  return 0;
}
```
