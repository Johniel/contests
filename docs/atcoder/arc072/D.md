# atcoder/arc072/D

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

void trial(void)
{
  const int LOSE = 0;
  const int WIN = 1;
  const int YET = 2;
  
  const int N = 40;
  int memo[N][N];
  function<int(int, int)> rec = [&] (int x, int y)
  {
    int& ret = memo[x][y];
    if (ret != YET) return ret;
    int best = LOSE;
    for (int i = 1; 2 * i <= x; ++i) {
      best = max(best, rec(x - 2 * i, y + i) ^ 1);
    }
    for (int i = 1; 2 * i <= y; ++i) {
      best = max(best, rec(x + i, y - 2 * i) ^ 1);
    }
    return ret = best;
  };

  for (int x = 0; x < N / 2; ++x) {
    for (int y = 0; y < N / 2; ++y) {
      fill(&memo[0][0], &memo[N - 1][N - 1] + 1, YET);
      // cout << make_pair(x, y) << ", " << rec(x, y) << endl;
      cout << rec(x, y) << " ";
    }
    cout << endl;
  }

  return ;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  // trial(); return 0;
  
  lli x, y;
  while (cin >> x >> y) {
    cout << (abs(x - y) <= 1 ? "Brown" : "Alice") << endl;
  }
  return 0;
}
```
