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

  string s;
  while (cin >> s) {
    string t = s + s + s;
    int mx = 0;

    int cnt = 0;
    for (int i = 0; i + 1 < t.size(); ++i) {
      if (t[i] != t[i + 1]) {
        ++cnt;
      } else {
        cnt = 1;
      }
      mx = max(mx, cnt);
    }

    cout << min<int>(mx, s.size()) << endl;
  }

  return 0;
}
