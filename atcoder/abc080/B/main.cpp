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
    lli n = stoll(s);
    lli sum = 0;
    each (c, s) {
      sum += c - '0';
    }
    cout << (n % sum == 0 ? "Yes" : "No") << endl;
  }
  
  return 0;
}
