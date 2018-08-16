# codeforces/310/B

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
  int n, m;
  while (cin >> n >> m) {
    vector<pair<lli, lli>> v(n);
    for (int i = 0; i < n; ++i) {
      cin >> v[i].first >> v[i].second;
    }
    priority_queue<tuple<lli, lli, int>,
                   vector<tuple<lli, lli, int>>,
                   greater<tuple<lli, lli, int>>> p;
    for (int i = 0; i + 1 < n; ++i) {
      p.push(make_tuple(v[i + 1].first - v[i].second,
                        v[i + 1].second - v[i].first,
                        i + 1));
    }
    priority_queue<pair<lli, int>,
                   vector<pair<lli, int>>,
                   greater<pair<lli, int>>> q;
    for (int i = 0; i < m; ++i) {
      lli n;
      cin >> n;
      q.push(make_pair(n, i + 1));
    }
    int match[n + 1];
    while (p.size()) {
      cout << q.top() << endl;
      cout << "(" << get<0>(p.top()) << ' ' << get<1>(p.top())  << ' ' << get<2>(p.top()) << ")" << endl;
      cout << endl;
      if (get<0>(p.top()) <= q.top().first && q.top().first <= get<1>(p.top())) {
        match[get<2>(p.top())] = q.top().second;
        p.pop();
        q.pop();
      } else {
        break;
      }
    }
    cout << (p.empty() ? "Yes" : "No") << endl;
    if (p.empty()) {
      for (int i = 1; i < n; ++i) {
        if (i - 1) cout << ' ';
        cout << match[i] ;
      }
      cout << endl;
    }
  }
  return 0;
}
```
