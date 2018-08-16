# codeforces/329div2/B

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

const int N = 100000 + 10;

int main(int argc, char *argv[])
{
  int n;
  while (scanf("%d", &n) == 1) {
    lli x1, x2;
    scanf("%lld%lld", &x1, &x2);
    static lli k[N], b[N];    
    
    vector<pair<lli, lli>> v;
    for (int i = 0; i < n; ++i) {
      scanf("%lld%lld", k + i, b + i);
      v.push_back(make_pair(k[i], b[i]));
    }
    
    auto fn1 = [&] (pair<lli, lli> p) { return p.first * x1 + p.second; };
    auto fn2 = [&] (pair<lli, lli> p) { return p.first * x2 + p.second; };    

    sort(v.begin(),
         v.end(),
         [&] (pair<lli, lli> s, pair<lli, lli> t)
         {
           if (fn1(s) != fn1(t)) return fn1(s) < fn1(t);
           return fn2(s) > fn2(t);
         });

    
    int next[N];
    next[n - 1] = n - 1;
    for (int i = n - 2; 0 <= i; --i) {
      if (fn1(v[i]) != fn1(v[i + 1])) {
        next[i] = i + 1;
      } else {
        next[i] = next[i + 1];
      }
    }
    
    lli mn[N];
    for (int i = 0; i < v.size(); ++i) {
      mn[i] = fn2(v[i]);
    }
    for (int i = n - 2; 0 <= i; --i) {
      mn[i] = min(mn[i], mn[i + 1]);
    }

    // each (i, v) cout << i << endl;
    // for (int i = 0; i < n; ++i) cout << next[i] << ' '; cout << endl;
    // for (int i = 0; i < n; ++i) cout << mn[i] << ' '; cout << endl;
    
    bool f = false;
    for (int i = 0; i < n; ++i) {
      if (mn[next[i]] < fn2(v[i]) && fn1(v[i]) != fn1(v[next[i]])) f = true;
    }
    puts(f ? "YES" : "NO");
  }
  return 0;
}
```
