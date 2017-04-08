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

  int tc;
  cin >> tc;
  while (tc--) {
    string s;
    int n;
    cin >> s >> n;

    int cnt = 0;
    for (int i = 0; i + n - 1 < s.size(); ++i) {
      if (s[i] == '-') {
        ++cnt;
        for (int j = 0; j < n; ++j) {
          s[i + j] = (s[i + j] == '-') ? '+' : '-';
        }
      }
    }

    static int tc = 0;
    cout << "Case #" << ++tc << ": " << flush;
    if (count(s.begin(), s.end(), '-') == 0) cout << cnt << endl;
    else cout << "IMPOSSIBLE" << endl;
  }
  
  return 0;
}
