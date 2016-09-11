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
    lli sum = 0;
    for (int bit = 0; bit < (1 << (s.size() - 1)); ++bit) {
      vector<string> v;
      string t;
      for (int i = 0; i < s.size(); ++i) {
        t += s[i];
        if (bit & (1 << i)) {
          v.push_back(t);
          t = "";
        }
      }
      v.push_back(t);
      // each (s, v) cout << s << ","; cout << endl;
      each (s, v) sum += atol(s.c_str());
    }
    cout << sum << endl;
  }
  return 0;
}
