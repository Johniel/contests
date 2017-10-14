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

  int a, b, c;
  while (cin >> a >> b >> c) {
    map<int, int> cnt;
    ++cnt[a];
    ++cnt[b];
    ++cnt[c];
    each (i, cnt) if (i.second == 1) cout << i.first << endl;
  }
  
  return 0;
}
