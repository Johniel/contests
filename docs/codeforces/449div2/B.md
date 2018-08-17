# codeforces/449div2/B

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

  char buff[100];
  vector<lli> v;
  for (int i = 1; ; ++i) {
    sprintf(buff, "%d", i);
    string s(buff);
    string t = s;
    reverse(t.begin(), t.end());
    s += t;
    if (s.size() % 2) continue;
    v.push_back(stoll(s));
    if (v.size() == 1e5) break;
  }
  sort(v.begin(), v.end());

  lli k, mod;
  while (cin >> k >> mod) {
    lli sum = 0;
    for (int i = 0; i < k; ++i) {
      sum += v[i];
      sum %= mod;
    }
    cout << sum << endl;
  }

  return 0;
}
```
