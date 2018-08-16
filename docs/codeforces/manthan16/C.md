# codeforces/manthan16/C

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

const int N = 10000 + 10;

const ull P = 37;

ull rhash(string s)
{
  lli h = 0;
  each (c, s) h = (h * P) + (tolower(c) - 'a' + 1);
  return h;
}

string S;
vector<string> v;
vector<ull> vh;
vector<int> path;

ull H[N][1000 +10];
int memo[N];
int rec(int curr)
{
  if (S.size() <= curr) return curr == S.size();
  int& ret = memo[curr];
  if (ret != -1) return ret;

  for (int i = 0; i < v.size(); ++i) {
    if (vh[i] == H[curr][v[i].size()]) {
      if (rec(curr + v[i].size())) {
        path.push_back(i);
        return ret = 1;
      }
    }
  }

  return ret = 0;
}

int main(int argc, char *argv[])
{
  int n, m;
  char buff[10000 + 10];
  while (scanf("%d\n", &n) == 1) {
    v.clear();
    vh.clear();
    path.clear();
    fill(memo, memo + N, -1);
    
    scanf("%s\n", buff);
    S = string(buff);

    scanf("%d\n", &m);
    for (int i = 0; i < m; ++i) {
      scanf("%s\n", buff);
      v.push_back(string(buff));
    }

    reverse(S.begin(), S.end());
    for (int i = 0; i < S.size(); ++i) {
      lli h = 0;
      for (int j = 0; j < 1000 && i + j < S.size(); ++j) {
        h = (h * P) + (tolower(S[i + j]) - 'a' + 1);
        H[i][j + 1] = h;
      }
    }

    for (int i = 0; i < v.size(); ++i) {
      vh.push_back(rhash(v[i]));
    }

    rec(0);
    for (int i = 0; i < path.size(); ++i) {
      if (i) printf(" ");
      printf("%s", v[path[i]].c_str());
    }
    puts("");
  }
  return 0;
}
```
