# codeforces/392div2/B

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
    string t = "RBYG";
    sort(t.begin(), t.end());
    do {
      bool f = true;
      map<char, int> cnt;
      for (int i = 0, j = 0; i < s.size(); ++i, ++j) {
        int k = j % t.size();
        f = f && (s[i] == '!' || s[i] == t[k]);
        if (s[i] == '!') ++cnt[t[k]];
      }
      if (f) {
        cout << cnt['R'] << ' ' << cnt['B'] << ' ' << cnt['Y'] << ' ' << cnt['G'] << endl;
        break;
      }
    } while (next_permutation(t.begin(), t.end()));
  }
  
  return 0;
}
```
