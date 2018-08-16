# codeforces/307/B

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
  string a, b, c;
  while (cin >> a >> b >> c) {
    map<char, int> A, B, C;
    for (char d = 'a'; d <= 'z'; ++d) {
      A[d] = count(a.begin(), a.end(), d);
      B[d] = count(b.begin(), b.end(), d);
      C[d] = count(c.begin(), c.end(), d);
    }
    const map<char, int> A_ = A;
    const map<char, int> B_ = B;
    const map<char, int> C_ = C;
    int mx = 0;
    pair<int, int> p;
    for (int i = 0; b.size() * i <= a.size(); ++i) {
      A = A_;
      B = B_;
      C = C_;
      const int inf = 1 << 28;
      int j = inf;
      for (char d = 'a'; d <= 'z'; ++d) {
        A[d] -= B[d] * i;
        if (A[d] < 0) { j = -1; break; }        
        if (C[d]) j = min(j, A[d] / C[d]);
      }
      if (j < 0) continue;
      if (j == inf) j = 0;
      if (i + j > mx) {
        mx = i + j;
        p = make_pair(i, j);
      }
    }
    A = A_;
    B = B_;
    C = C_;

    if (mx) {
      for (int i = 0; i < p.first; ++i) {
        cout << b;
      }
      for (int i = 0; i < p.second; ++i) {
        cout << c;
      }
      for (char d = 'a'; d <= 'z'; ++d) {
        A[d] -= (B[d] * p.first) + (C[d] * p.second);
        cout << string(A[d], d);
      }
      cout << endl;
    } else {
      cout << a << endl;
    }
  }
  return 0;
}
```
