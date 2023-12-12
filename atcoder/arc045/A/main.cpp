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
  vector<string> v;
  while (cin >> s) {
    if (s == "Left") v.push_back("<");
    if (s == "Right") v.push_back(">");
    if (s == "AtCoder") v.push_back("A");
  }

  for (int i = 0; i < v.size(); ++i) {
    if (i) cout << ' ' ;
    cout << v[i];
  }
  cout << endl;

  return 0;
}
