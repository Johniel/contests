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
  int n, d;
  while (scanf("%d%d", &n, &d) == 2) {
    char buff[110];
    vector<int> v;
    for (int i = 0; i < d; ++i) {
      scanf("%s", buff);
      string s(buff);
      if (count(s.begin(), s.end(), '1') != s.size()) {
        v.push_back(i);
      }
    }
    int cnt = (bool)v.size();
    int mx = cnt;
    for (int i = 0; i + 1 < v.size(); ++i) {
      if (v[i] + 1 == v[i + 1]) {
        ++cnt;
      } else {
        cnt = 1;
      }
      mx = max(mx, cnt);
    }
    mx = max(mx, cnt);
    printf("%d\n", mx);
  }
  return 0;
}
