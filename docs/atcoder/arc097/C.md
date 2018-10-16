# ARC097 C
答えがKより長くなることはない。長さK以下の部分文字列を列挙してソートしてK番目の文字列を出力する。


## Codes
main.cpp
{% raw %}{{
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
  int k;
  while (cin >> s >> k) {
    vector<string> v;
    for (int i = 0; i < s.size(); ++i) {
      string t;
      for (int j = 0; j < 5 && i + j < s.size(); ++j) {
        t += s[i + j];
        v.push_back(t);
      }
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    cout << v[k - 1] << endl;
  }

  return 0;
}
}}{% endraw %}
```
---
+ [toppage](https://johniel.github.io/contests/)
+ [index](https://johniel.github.io/contests/docs/atcoder)
+ [repository](https://github.com/Johniel/contests/tree/master/atcoder/arc097/C)
