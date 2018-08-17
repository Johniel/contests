# codeforces/455div2/D

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

  string s;
  while (cin >> s) {
    vector<pair<char, int>> v;
    each (c, s) {
      if (v.empty()) {
        v.push_back(make_pair(c, 1));
      } else {
        if (v.back().first == c) ++v.back().second;
        else v.push_back(make_pair(c, 1));
      }
    }

    int cnt = 0;
    while (1 < v.size()) {
      const vector<pair<char, int>> V = v;
      vector<pair<char, int>> u;
      for (int i = 0; i < v.size(); ++i) {
        if (i) --v[i].second;
        if (i + 1 < v.size()) --v[i].second;
      }
      each (i, v) {
        if (i.second <= 0) continue;
        if (u.empty()) u.push_back(i);
        else {
          if (u.back().first == i.first) u.back().second += i.second;
          else u.push_back(i);
        }
      }
      if (u == V) break;
      ++cnt;
      v = u;
    }
    cout << cnt << endl;
  }
  
  return 0;
}
```
