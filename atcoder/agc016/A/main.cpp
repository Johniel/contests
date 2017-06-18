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

int f(string s, char c)
{
  if (count(s.begin(), s.end(), c) == 0)  return 1 << 29;
  int cnt = 0;
  while (count(s.begin(), s.end(), c) != s.size()) {
    string t(s.size() - 1, '@');
    for (int i = 0; i < t.size(); ++i) {
      t[i] = s[i];
      if (s[i + 1] == c) t[i] = c;
    }
    s = t;
    ++cnt;
  }
  return cnt;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s;
  while (cin >> s) {
    int mn = 1 << 29;
    for (char c = 'a'; c <= 'z'; ++c) {
      mn = min(mn, f(s, c));
    }
    cout << mn << endl;
  }
  
  return 0;
}
