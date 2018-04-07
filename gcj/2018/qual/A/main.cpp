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

int fn(string s)
{
  int sum = 0;
  lli w = 1;
  each (c, s) {
    if (c == 'C') w *= 2;
    else sum += w;
  }
  return sum;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int d;
    string s;
    cin >> d >> s;
    int cnt = 0;
    while (d < fn(s)) {
      bool changed = false;
      for (int i = s.size() - 2; 0 <= i; --i) {
        if (s[i] == 'C' && s[i + 1] == 'S') {
          swap(s[i], s[i + 1]);
          changed = true;
          break;
        }
      }
      unless (changed) break;
      cnt += changed;
    }
    static int tc = 0;
    cout << "Case #" << ++tc << ": " << flush;
    if (fn(s) <= d) cout << cnt << endl;
    else cout << "IMPOSSIBLE" << endl;
  }
  
  return 0;
}
