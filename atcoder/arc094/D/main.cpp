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

lli trinaly_search(lli small, lli large, function<lli(lli)>fn)
{
  for (int i = 0; i < 100; ++i) {
    lli left = (large - small) / 3 + small;
    lli right = (large - small) * 2 / 3 + small;
    if (fn(right) < fn(left)) large = right;
    else small = left;
  }

  lli mx = small;
  for (lli i = small; i <= large; ++i) {
    if (fn(mx) < fn(i)) mx = i;
  }
  return mx;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int q;
  while (cin >> q) {
    while (q--) {
      lli a, b;
      unless (cin >> a >> b) return 0;
      lli small = 0;
      lli large = 1e11 + 1;
      while (small + 1 < large) {
        lli mid = (small + large) / 2;

        auto fn = [&] (lli c) {
          lli x = c;
          lli y = mid + 1 - c;
          if (a <= x) ++x;
          if (b <= y) ++y;
          return x * y;
        };

        if (fn(trinaly_search(0, mid, fn)) < a * b) small = mid;
        else large = mid;
      }
      cout << small << endl;
    }
  }

  return 0;
}
