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

  int n;
  while (cin >> n) {
    string s;
    cin >> s;
    string t = s;
    reverse(t.begin(), t.end());

    map<pair<string, string>, lli> cnt1, cnt2;
    for (int bit = 0; bit < (1 << n); ++bit) {
      {
        string a, b;
        for (int i = 0; i < n; ++i) {
          if (bit & (1 << i)) {
            a += s[i];
          } else {
            b += s[i];
          }
        }
        reverse(b.begin(), b.end());
        ++cnt1[make_pair(a, b)];
      }
      {
        string a, b;
        for (int i = 0; i < n; ++i) {
          if (bit & (1 << i)) {
            a += s[n + i];
          } else {
            b += s[n + i];
          }
        }
        reverse(a.begin(), a.end());
        ++cnt2[make_pair(a, b)];
      }
    }
    lli sum = 0;
    each (i, cnt1) {
      sum += i.second * cnt2[i.first];
    }
    cout << sum << endl;
  }
  
  return 0;
}
