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
    if (a % 2 || b % 2 || c % 2) {
      cout << 0 << endl;
      continue;
    }
    set<tuple<int, int, int>> vis;
    int cnt = 0;
    while (true) {
      tuple<int, int, int> t = make_tuple(a, b, c);
      // cout << a << ' ' << b << ' ' << c << endl;
      if (vis.count(t)) {
        cnt = -1;
        break;
      }
      vis.insert(t);
      int A = (b / 2) + (c / 2);
      int B = (a / 2) + (c / 2);
      int C = (a / 2) + (b / 2);
      a = A;
      b = B;
      c = C;
      ++cnt;
      if (a % 2 || b % 2 || c % 2) break;
    }
    cout << cnt << endl;
  }
  
  return 0;
}
