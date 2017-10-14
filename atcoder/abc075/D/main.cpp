#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<lli> point;

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

  int n, k;
  while (cin >> n >> k) {
    vector<point> v;
    for (int i = 0; i < n; ++i) {
      int x, y;
      cin >> x >> y;
      v.push_back(point(x, y));
    }

    sort(v.begin(), v.end(), [] (point a, point b) { return a.imag() < b.imag(); });
    // cout << endl; each (i, v) cout << i << endl; 

    // +--d---+
    // |      |
    // a      b
    // |      |
    // +----c-+
    ull mn = 1ULL << 63;
    for (int a = 0; a < n; ++a) {
      for (int b = 0; b < n; ++b) {
        if (a == b) continue;
        for (int c = 0; c < n; ++c) {
          unless (v[a].real() <= v[c].real() && v[c].real() <= v[b].real()) continue;
          unless (min(v[a].imag(), v[b].imag()) >= v[c].imag()) continue;
          int cnt = 0;
          for (int d = c; d < n; ++d) {
            unless (v[a].real() <= v[d].real() && v[d].real() <= v[b].real()) continue;
            ++cnt;
            if (k <= cnt) {
              ull s = labs(v[a].real() - v[b].real());
              ull t = labs(v[c].imag() - v[d].imag());
              // cout << v[a] << " - " << v[b] << endl;
              // cout << v[c] << " - " << v[d] << endl;
              // cout << s * t << endl;
              mn = min(mn, s * t);
            }
          }
        }
      }
    }
    cout << mn << endl;
  }
  
  return 0;
}
