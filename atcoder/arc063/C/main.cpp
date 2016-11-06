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
  string s;
  while (cin >> s) {
    int cnt = 0;
    for (int i = 0; i + 1 < s.size(); ++i) {
      cnt += (s[i] != s[i + 1]);
    }
    cout << cnt << endl;
  }
  
  return 0;
}
