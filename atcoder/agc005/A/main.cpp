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
    stack<char> t;
    each (c, s) {
      if (t.size() && t.top() == 'S' && c == 'T') t.pop();
      else t.push(c);
    }
    cout << t.size() << endl;
  }
  return 0;
}
