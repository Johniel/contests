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

  int n, m;
  while (cin >> n >> m) {

    vector<int> v[m];
    for (int i = 0; i < m; ++i) {
      int k;
      cin >> k;
      v[i].resize(k);
      each (j, v[i]) cin >> j;
    }

    for (int i = 0; i < m; ++i) {
      sort(v[i].begin(), v[i].end());
      v[i].erase(unique(v[i].begin(), v[i].end()), v[i].end());
    }

    bool f = false;
    for (int i = 0; i < m; ++i) {
      map<int, int> cnt;
      int mx = 0;
      each (j, v[i]) mx = max(mx, ++cnt[abs(j)]);
      f = f || (mx == 1);
    }

    cout << (f ? "YES" : "NO") << endl;
  }
  return 0;
}
