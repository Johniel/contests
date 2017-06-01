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

  int l[4], s[4], r[4], p[4];
  while (cin
         >> l[0] >> s[0] >> r[0] >> p[0]
         >> l[1] >> s[1] >> r[1] >> p[1]
         >> l[2] >> s[2] >> r[2] >> p[2]
         >> l[3] >> s[3] >> r[3] >> p[3]
    ) {

    bool f = false;

    // s
    for (int i = 0; i < 4; ++i) {
      int j = (i + 2) % 4;
      if (s[i] && p[j]) f = true;
      if (s[i] && p[i]) f = true;
    }

    // l
    for (int i = 0; i < 4; ++i) {
      int j = (i + 3) % 4;
      if (l[i] && p[j]) f = true;
      if (l[i] && p[i]) f = true;
    }

    // r
    for (int i = 0; i < 4; ++i) {
      int j = (i + 1) % 4;
      if (r[i] && p[j]) f = true;
      if (r[i] && p[i]) f = true;
    }


    
    cout << (f ? "YES" : "NO") << endl;
  }

  return 0;
}
