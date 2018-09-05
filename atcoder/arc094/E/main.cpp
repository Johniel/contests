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
  while (cin >> n) {
    vector<lli> a(n);
    vector<lli> b(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i] >> b[i];
    }

    if (a == b) {
      cout << 0 << endl;
      continue;
    }
    
    lli mn = 1LL << 60;
    lli sum = accumulate(a.begin(), a.end(), 0LL);
    for (int i = 0; i < n; ++i) {
      if (a[i] > b[i]) {
        mn = min(mn, b[i]);
      }
    }
    cout << sum - mn << endl;
  }

  return 0;
}
