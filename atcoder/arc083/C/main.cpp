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
 
  int A, B, C, D, E, F;
  while (cin >> A >> B >> C >> D >> E >> F) {
    const int N = 7000;
    bool sugar[N];
    bool water[N];
 
    fill(sugar, sugar + N, false);
    fill(water, water + N, false);
    sugar[0] = water[0] = true;
 
    for (int i = 0; i <= F; ++i) {
      if (sugar[i]) {
        sugar[i + C] = true;
        sugar[i + D] = true;
      }
      if (water[i]) {
        water[i + A * 100] = true;
        water[i + B * 100] = true;
      }
    }
 
    double mx = 0;
    int p = 100 * A;
    int q = 0;
    for (int w = 1; w <= F; ++w) {
      unless (water[w]) continue;
      for (int s = 0; s <= F && s <= (w / 100.0) * E; ++s) {
        unless (sugar[s]) continue;
        if (w + s <= F) {
          double d = 100.0 * s / (w + s);
          if (mx < d) {
            mx = d;
            p = w + s;
            q = s;
          }
        }
      }
    }
    cout << p << ' ' << q << endl;
  }
  
  return 0;
}

