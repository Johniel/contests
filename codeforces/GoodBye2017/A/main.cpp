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

  string s;
  while (cin >> s) {

    set<char> v = {'a', 'e', 'i', 'o', 'u'};
    int cnt = 0;
    each (c, s) {
      if ('a' <= c && c <= 'z') {
        cnt += v.count(c);
      } else {
        cnt += ((c - '0') % 2 == 1);
      }
    }
    cout << cnt << endl;
  }
  
  return 0;
}
