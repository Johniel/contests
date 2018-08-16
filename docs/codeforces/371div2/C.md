# codeforces/371div2/C

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

inline void add(map<string, int>& cnt, char buff[])
{
  string s(buff);
  reverse(s.begin(), s.end());
  while (s.size() < 18) s += "0";
  string t;
  for (int i = 0; i < s.size(); ++i) {
    t += (s[i] - '0') % 2 + '0';
  }
  ++cnt[t];
  return ;
}

inline void sub(map<string, int>& cnt, char buff[])
{
  string s(buff);
  reverse(s.begin(), s.end());
  while (s.size() < 18) s += "0";
  string t;
  for (int i = 0; i < s.size(); ++i) {
    t += (s[i] - '0') % 2 + '0';
  }
  --cnt[t];
  return ;
}

inline void query(map<string, int>& cnt, char buff[])
{
  string s(buff);
  reverse(s.begin(), s.end());
  while (s.size() < 18) s += '0';
  if (cnt.count(s)) printf("%d\n", cnt[s]);
  else puts("0");
  return ;
}

int main(int argc, char *argv[])
{
  int n;
  while (scanf("%d\n", &n) == 1) {
    char c;
    char s[20];
    map<string, int> cnt;
    while (n--) {
      scanf("%c %s\n", &c, s);
      if (c == '+') add(cnt, s);
      if (c == '-') sub(cnt, s);
      if (c == '?') query(cnt, s);
    }
  }
  return 0;
}
```
