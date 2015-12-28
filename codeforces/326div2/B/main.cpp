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
  const int P = 1000010;
  bool p[P];
  fill(p, p + P, true);
  p[0] = p[1] = false;
  for (int i = 2; i * i < P; ++i) {
    for (int j = 2; i * j <  P; ++j) {
      p[i * j] = false;
    }
  }

  vector<int> v;
  for (int i = 0; i < P; ++i) {
    if (p[i]) v.push_back(i);
  }

  lli n;
  while (cin >> n) {
    map<lli, int> cnt;
    lli m = n;
    each (i, v) {
      if (m % i == 0) {
        while (m % i == 0) {
          ++cnt[i];
          m /= i;
        }
      }
    }
    if (m != 1) ++cnt[m];
    lli x = 1;
    each (i, cnt) {
      x *= i.first;
    }
    cout << x << endl;
  }
  return 0;
}
