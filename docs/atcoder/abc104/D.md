# atcoder/abc104/D

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

struct acc {
  vector<lli> sum;
  acc(vector<lli> v) {
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

  const lli mod = 1e9 + 7;
  const string t = "ABC_";
  string s;
  while (cin >> s) {
    vector<lli> a(s.size(), 0);
    vector<lli> c(s.size(), 0);
    vector<lli> h(s.size(), 0);
    for (int i = 0; i < s.size(); ++i) {
      a[i] += (s[i] == 'A');
      c[i] += (s[i] == 'C');
      h[i] += (s[i] == '?');
    }

    map<int, lli> p3;
    lli prev = 1;
    for (int i = 0; i < 1e5; ++i) {
      p3[i] = prev;
      (prev *= 3) %= mod;
    }
    p3[-1] = 0;
    
    acc acc_a(a);
    acc acc_c(c);
    acc acc_h(h);

    lli sum = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == 'B' || s[i] == '?') {
        lli A = acc_a.query(0, i);
        lli AH = acc_h.query(0, i);

        lli C = acc_c.query(i + 1, s.size());
        lli CH = acc_h.query(i + 1, s.size());
        
        // ?B?
        {
          lli x = AH * CH;
          lli y = p3[AH - 1] * p3[CH - 1];
          x %= mod;
          y %= mod;
          (sum += (x * y) % mod) %= mod;
        }
        // AB?
        {
          lli x = A * CH;
          lli y = p3[AH] * p3[CH - 1];
          x %= mod;
          y %= mod;
          (sum += (x * y) % mod) %= mod;
        }
        // ?BC
        {
          lli x = AH * C;
          lli y = p3[AH - 1] * p3[CH];
          x %= mod;
          y %= mod;
          (sum += (x * y) % mod) %= mod;
        }
        // ABC
        {
          lli x = A * C;
          lli y = p3[AH] * p3[CH];
          x %= mod;
          y %= mod;
          (sum += (x * y) % mod) %= mod;
        }
      }
    }
    cout << sum << endl;
  }
  
  return 0;
}
```
