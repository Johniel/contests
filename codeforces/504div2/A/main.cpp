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

template<typename T>
ostream& operator << (ostream& os, vector<T> v)
{
  os << "(";
  each (i, v) os << i << ",";
  os << ")";
  return os;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s, t;
  int n, m;
  while (cin >> n >> m >> s >> t) {
    string u;
    each (c, s) {
      if (c == '*') u += string(max(0, (int)t.size() - (int)(s.size() - 1)), '?');
      else u += c;
    }
    bool f = (t.size() == u.size());
    for (int i = 0; i < min(t.size(), u.size()); ++i) {
      f = f && (u[i] == '?' || u[i] == t[i]);
    }
    cout << (f ? "YES" : "NO") << endl;
  }
  
  return 0;
}
