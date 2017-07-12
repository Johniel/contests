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

  lli n, a, b;
  while (cin >> n >> a >> b) {
    lli c = 0;
    lli cnt = 0;
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      if (x == 1) {
        if (a) --a;
        else if (b) { --b; ++c; }
        else if(c) --c;
        else cnt += 1;
      }
      if (x == 2) {
        if (b) --b;
        else cnt += 2;
      }
    }
    cout << cnt << endl;
  }
  
  return 0;
}
