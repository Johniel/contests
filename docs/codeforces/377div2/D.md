# codeforces/377div2/D

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
const int M = N;
int a[N];
int day[M];

bool f(int limit, const int n, const int m)
{
  // cout << "============================== " << limit << endl;
  map<int, int> last;
  for (int i = 0; i < limit; ++i) {
    if (day[i]) last[day[i]] = i;
  }

  vector<pair<int, int>> v;
  each (i, last) v.push_back(make_pair(i.second, i.first));
  sort(v.begin(), v.end());
  queue<int> q;
  each (i, v) q.push(i.second);

  set<int> passed;
  int pre[n];
  fill(pre, pre + n, 0);
  for (int i = 0; i < limit; ++i) {
    const int j = day[i];
    if (j && last[j] == i) {
      if (pre[j] == a[j]) {
        passed.insert(j);
      }
      else return false;
    } else {
      while (q.size() && pre[q.front()] >= a[q.front()]) q.pop();
      if (q.size()) {
        ++pre[q.front()];
      }
    }
  }
  
  return passed.size() == m;
}

int main(int argc, char *argv[])
{
  std::ios::sync_with_stdio(false);
  int n, m;
  while (cin >> n >> m) {
    for (int i = 0; i < n; ++i) {
      cin >> day[i];
    }
    for (int i = 0; i < m; ++i) {
      cin >> a[i + 1];
    }
    int small = 0;
    int large = n;
    while (small + 1 < large) {
      int mid = (small + large) / 2;
      if (f(mid, n, m)) large = mid;
      else small = mid;
    }
    if (f(small, n, m)) cout << small << endl;
    else if (f(large, n, m)) cout << large << endl;
    else cout << -1 << endl;
    // break;
  }
  return 0;
}
```
