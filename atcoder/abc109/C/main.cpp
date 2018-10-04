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

  int n, x;
  while (cin >> n >> x) {
    vector<int> v(n);
    each (i, v)
      cin >> i;
    sort(v.begin(), v.end());
    if (n == 1) {
      cout << abs(v[0] - x) << endl;
      continue;
    }
    int a = v[1] - v[0];
    for (int i = 1; i < v.size(); ++i) {
      a = __gcd(a, v[i] - v[0]);
    }
    int mx = 0;
    each (i, v) {
      mx = max(mx, __gcd(a, abs(x - i)));
    }
    cout << mx << endl;
  }

  return 0;
}
