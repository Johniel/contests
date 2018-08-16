# atcoder/arc085/D

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

const int N = 2000 + 10;
int n;

vector<lli> a1;
lli memo1[N];

lli rec2(int other) ;

lli rec1(int other)
{
  if (other == a1.size() - 1) {
    return +(1LL << 60);
  }

  lli& ret = memo1[other];
  if (ret != -1) return ret;

  lli best = labs(a1[other] - a1.back());
  for (int i = other + 1; i < a1.size(); ++i) {
    best = max(best, rec2(i));
  }

  return ret = best;
}

vector<lli> a2;
lli memo2[N];

lli rec2(int other)
{
  if (other == a2.size() - 1) {
    return -(1LL << 60);
  }

  lli& ret = memo2[other];
  if (ret != -1) return ret;

  lli best = labs(a2[other] - a2.back());
  for (int i = other + 1; i < a1.size(); ++i) {
    best = min(best, rec1(i));
  }

  return ret = best;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  lli z, w;
  while (cin >> n >> z >> w) {
    fill(memo1, memo1 + N, -1);
    fill(memo2, memo2 + N, -1);
    a1.resize(n + 1);
    a2.resize(n + 1);
    a1[0] = w;
    a2[0] = z;
    for (int i = 0; i < n; ++i) {
      int a;
      cin >> a;
      a1[i + 1] = a2[i + 1] = a;
    }
    cout << rec1(0) << endl;
  }

  return 0;
}
```
