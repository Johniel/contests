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

  int n, m;
  while (cin >> n >> m) {
    vector<int> p(n);
    each (i, p) cin >> i;
    while (m--) {
      int begin, end, x;
      cin >> begin >> end >> x;
      --begin;
      --end;
      --x;
      int cnt = 0;
      for (int i = begin; i <= end; ++i) {
        if (p[i] < p[x]) ++cnt;
      }
      // cout << begin << ' ' << end << ' ' << x << ' ' << cnt << endl;
      cout << (begin + cnt == x ? "Yes" : "No") << endl;
    }
  }
  
  
  return 0;
}
