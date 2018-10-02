#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

template <typename P, typename Q>
ostream& operator<<(ostream& os, pair<P, Q> p)
{
  os << "(" << p.first << "," << p.second << ")";
  return os;
}

template <typename T>
ostream& operator<<(ostream& os, vector<T> v)
{
  os << "(";
  each (i, v)
    os << i << ",";
  os << ")";
  return os;
}

int main(int argc, char* argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s;
  while (cin >> s) {
    int a = count(s.begin(), s.end(), '0');
    int b = count(s.begin(), s.end(), '1');
    if (s.size() == a || s.size() == b) {
      cout << s.size() << endl;
      continue;
    }

    int mn = 1 << 29;
    for (int i = 0; i + 1 < s.size(); ++i) {
      if (s[i] != s[i + 1]) {
        int x = max<int>(i + 1, (int)s.size() - i - 1);
        mn = min(mn, x);
      }
    }
    cout << mn << endl;
  }

  return 0;
}
