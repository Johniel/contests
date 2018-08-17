# [B. Petya and Exam](http://codeforces.com/contest/832/problem/B)

`*` を含まない場合のループがパターン長だけ確認する実装になっていてTLEした。

クエリとパターンが同じ長さかは確認したものの、注意深さが欠けていた。

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

  string s, t;
  while (cin >> s >> t) {
    set<int> good(s.begin(), s.end());
    const bool f = count(t.begin(), t.end(), '*');
    int q;
    cin >> q;
    while (q--) {
      cin >> s;
      if (!f) {
        bool f = (s.size() == t.size());
        for (int i = 0; f && i < t.size(); ++i) {
          if (t[i] == '?') f = f && good.count(s[i]);
          else f = f && (s[i] == t[i]);
        }
        cout << (f ? "YES" : "NO") << endl;
      } else {
        bool f = true;
        for (int i = 0; i < s.size() && t[i] != '*'; ++i) {
          if (t[i] == '?') f = f && good.count(s[i]);
          else f = f && (s[i] == t[i]);
          s[i] = '@';
        }
        const int s_size = s.size();
        const int t_size = t.size();
        for (int i = 0; 0 <= min<int>(t_size, s_size) - i && t[t_size - i] != '*'; ++i) {
          if (t[t_size - i] == '?') f = f && good.count(s[s_size - i]);
          else f = f && (s[s_size - i] == t[t_size - i]);
          s[s_size - i] = '@';
        }

        f = f && (t_size == count(s.begin(), s.end(), '@') + 1);
        each (c, s) f = f && (good.count(c) == 0);
        cout << (f ? "YES" : "NO") << endl;
      }
    }
    cout << endl;
  }

  return 0;
}
```
