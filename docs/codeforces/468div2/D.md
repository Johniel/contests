# codeforces/468div2/D

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
vector<int> g[N];
map<int, int> cnt;

void rec(int curr, int depth)
{
  ++cnt[depth];
  each (next, g[curr]) {
    rec(next, depth + 1);
  }
  return ;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    fill(g, g + N, vector<int>());

    for (int i = 1; i < n; ++i) {
      int x;
      cin >> x;
      --x;
      g[x].push_back(i);
    }

    cnt.clear();
    rec(0, 0);
    int sum = 0;
    each (i, cnt) sum += i.second % 2;
    cout << sum << endl;
  }
  
  return 0;
}
```
