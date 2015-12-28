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
  int n;
  while (cin >> n) {
    vector<pair<int, int>> a, b;
    for (int i = 0; i < n; ++i) {
      int x, y;
      cin >> x >> y;
      if (x > 0) a.push_back(make_pair(x, y));
      else b.push_back(make_pair(x, y));
    }
    const int mn = min(a.size(), b.size());
    a.push_back(make_pair(1 << 29, 0));
    b.push_back(make_pair(-(1 << 29), 0));
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    reverse(b.begin(), b.end());
    int sum = 0;
    for (int i = 0; i < mn; ++i) {
      //      cout << a[i] << ' ' << b[i] << endl;
      sum += a[i].second + b[i].second;
    }
    sum += max(a[mn].second, b[mn].second);
    cout << sum << endl;
  }
  return 0;
}
