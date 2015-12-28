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

string common_prefix(string a, string b)
{
  string c;
  for (int i = 0; i < min(a.size(), b.size()); ++i) {
    if (a[i] == b[i]) c += a[i];
  }
  return c;
}

int main(int argc, char *argv[])
{
  int n;
  while (cin >> n) {
    vector<string> v;
    for (int i = 0; i < n; ++i) {
      int m;
      cin >> m;
      string s;
      while (m) {
        s += '0' + (m % 2);
        m /= 2;
      }
      reverse(s.begin(), s.end());
      v.push_back(s);
    }
    string s = v[0];
    for (int i = 1; i < v.size(); ++i) {
      s = common_prefix(s, v[i]);
    }
    
  }
  return 0;
}
