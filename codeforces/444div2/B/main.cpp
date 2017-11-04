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

set<int> s[3];

int fn(int n)
{
    int x = 0;
    for (int i = 1; i < 10; ++i) {
      bool ok = false;
      for (int j = 0; j < 3; ++j) {
        ok = ok || s[j].count(i);
      }
      if (!ok) return x;
      x = i;
    }

    for (int i = 10; i < 100; ++i) {
      bool ok = false;
      int p = i / 10;
      int q = i % 10;
      for (int a = 0; a < 3; ++a) {
        for (int b = 0; b < 3; ++b) {
          ok = ok || (a != b && s[a].count(p) && s[b].count(q));
        }
      }
      if (!ok) return x;
      x = i;
    }

    for (int i = 100; i < 1000; ++i) {
      bool ok = false;

      char buff[10];
      sprintf(buff, "%d", i);
      int p = buff[0] - '0';
      int q = buff[1] - '0';
      int r = buff[2] - '0';

      for (int a = 0; a < 3; ++a) {
        for (int b = 0; b < 3; ++b) {
          for (int c = 0; c < 3; ++c) {
            if (a == b) continue;
            if (b == c) continue;
            if (a == c) continue;
            ok = ok || (s[a].count(p) && s[b].count(q) && s[c].count(r));
          }
        }
      }
      if (!ok) return x;
      x = i;
    }

    return 999;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    s[0].clear();
    s[1].clear();
    s[2].clear();
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < 6; ++j) {
        int a;
        cin >> a;
        s[i].insert(a);
      }
    }
    cout << fn(n) << endl;
  }
  
  return 0;
}
