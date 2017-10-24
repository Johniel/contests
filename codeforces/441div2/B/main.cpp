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

  lli n, k, m;
  while (cin >> n >> k >> m) {
    vector<int> v(n);
    each (i, v) cin >> i;
    map<int, int> cnt;
    each (i, v) ++cnt[i % m];

    int x = -1;
    each (i, cnt) {
      if (k <= i.second) x = i.first;
    }

    if (x == -1) cout << "No" << endl;
    else {
      cout << "Yes" << endl;
      for (int i = 0; i < v.size() && k; ++i) {
        if (v[i] % m == x) {
          cout << v[i] << ' ';
          --k;
        }
      }
      cout << endl;
    }
  }

  return 0;
}
