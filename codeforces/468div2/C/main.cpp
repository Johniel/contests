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

  int n;
  while (cin >> n) {
    vector<lli> x(n);
    each (i, x) cin >> i;

    sort(x.begin(), x.end());
    
    const lli mn = *min_element(x.begin(), x.end());
    const lli mx = *max_element(x.begin(), x.end());

    if (mn == mx) {
      cout << n << endl;
      each (i, x) cout << i << ' ';
      cout << endl;
    }
    if (mn + 1 == mx) {
      cout << n << endl;
      each (i, x) cout << i << ' ';
      cout << endl;      
    }
    if (mn + 2 == mx) {
      const lli mid = mn + 1;
      int a = count(x.begin(), x.end(), mn);
      int b = count(x.begin(), x.end(), mid);
      int c = count(x.begin(), x.end(), mx);
      const int A = a;
      const int B = b;
      const int C = c;
      
      int p = a;
      int q = b;
      int r = c;

      lli best = n;
      while (2 <= b) {
        b -= 2;
        ++a;
        ++c;
        lli score = min(A, a) + min(B, b) + min(C, c);
        if (best > score) {
          best = score;
          p = a;
          q = b;
          r = c;
        }
      }
      while (a && c) {
        --a;
        --c;
        b += 2;
        lli score = min(A, a) + min(B, b) + min(C, c);
        if (best > score) {
          best = score;
          p = a;
          q = b;
          r = c;
        }
      }      

      cout << best << endl;
      for (int i = 0; i < p; ++i) cout << mn << ' ';
      for (int i = 0; i < q; ++i) cout << mid << ' ';
      for (int i = 0; i < r; ++i) cout << mx << ' ';
      cout << endl;
    }
  }
  
  return 0;
}
