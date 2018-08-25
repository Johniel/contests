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

  lli n, k;
  while (cin >> n >> k) {
    vector<lli> x(n);
    each (i, x) cin >> i;

    lli mn = 1LL << 60;
    for (int i = 0; i + k - 1 < x.size(); ++i) {
      const lli a = x[i];
      const lli b = x[i + k - 1];
      if (a <= 0 && 0 <= b) {
        // a<---0
        // a--------->b
        mn = min(mn, abs(a) + abs(a) + abs(b));
        //     0-->b
        //a<-------b
        mn = min(mn, abs(b) + abs(b) + abs(a));
      } else {
        if (0 <= a) {
          // 0-->a--->b
          mn = min(mn, abs(b));
        }
        if (b <= 0) {
          // a<---b<---0
          mn = min(mn, abs(a));
        }
      }
    }
    cout << mn << endl;
  }
  
  return 0;
}
