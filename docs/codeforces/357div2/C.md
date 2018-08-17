# codeforces/357div2/C

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

void dump(priority_queue<int, vector<int>, less<int>> q)
{
  while (q.size()) {
    printf("%d, ", q.top());
    q.pop();
  }
  puts("");
  return;
}

int main(int argc, char *argv[])
{
  int n;
  while (scanf("%d", &n) == 1) {
    char buff[100];
    int m;
    priority_queue<int, vector<int>, greater<int>> q;
    vector<pair<char, int>> v;

    for (int i = 0; i < n; ++i) {
      scanf("%s", buff);
      if (buff[0] == 'i') {
        scanf("%d", &m);
        q.push(m);
        v.push_back(make_pair('i', m));
      }
      if (buff[0] == 'r') {
        if (q.size()) q.pop();
        else v.push_back(make_pair('i', -1000000000));
        v.push_back(make_pair('r', -1));
      }
      if (buff[0] == 'g') {
        scanf("%d", &m);
        while (q.size() && m > q.top()) {
          q.pop();
          v.push_back(make_pair('r', -1));
        }
        if (q.empty() || q.top() != m) {
          q.push(m);
          v.push_back(make_pair('i', m));
        }
        v.push_back(make_pair('g', m));
      }
    }

    printf("%d\n", (int)v.size());
    each (i, v) {
      if (i.first == 'i') printf("insert %d\n", i.second);
      if (i.first == 'r') printf("removeMin\n");
      if (i.first == 'g') printf("getMin %d\n", i.second);
    }
  }
  return 0;
}
```
