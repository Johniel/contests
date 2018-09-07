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

  int n;
  int k;
  string s;
  while (cin >> n >> k >> s) {
    assert(s.size() == n);
    map<char, int> cnt;
    each (c, s) ++cnt[c];
    int mn = 1 << 29;
    for (char c = 'A'; c < 'A' + k; ++c) {
      mn = min(mn, cnt[c]);
    }
    cout << mn * k << endl;
  }
  
  return 0;
}
