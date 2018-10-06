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
    int x[n];
    int y[n];
    int h[n];
    for (int i = 0; i < n; ++i) {
      cin >> x[i] >> y[i] >> h[i];
    }
    for (int cx = 0; cx <= 100; ++cx) {
      for (int cy = 0; cy <= 100; ++cy) {
        int H = 0;
        for (int i = 0; i < n; ++i) {
          if (h[i] == 0) continue;
          H = h[i] + abs(x[i] - cx) + abs(y[i] - cy);
          break;
        }
        if (H == 0) continue;
        bool f = true;
        for (int i = 0; i < n; ++i) {
          int z = max(H - abs(x[i] - cx) - abs(y[i] - cy), 0);
          f = f && (h[i] == z);
        }
        if (f) {
          cout << cx << ' ' << cy << ' ' << H << endl;
          cx = cy = 1000;
        }
      }
    }
  }
  
  return 0;
}
