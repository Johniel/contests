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
    bool f = true;
    f = f && (s[0] == 'A');

    int cnt = 0;
    for (int i = 2; i < int(s.size())- 1; ++i) {
      cnt += (s[i] == 'C');
    }
    f = f && (cnt == 1);

    each (c, s) {
      if (c == 'A' || c == 'C') continue;
      f = f && ('a' <= c && c <= 'z');
    }
    
    cout << (f ? "AC" : "WA") << endl;
  }
  
  return 0;
}
