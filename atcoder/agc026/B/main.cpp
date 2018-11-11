#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; each (i, v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { each (i, v) is >> i; return is; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  while (cin >> t) {
    while (t--) {
      lli A, B, C, D;
      cin >> A >> B >> C >> D;

      if (0) ;
      else if (A < B) cout << "No" << endl;
      else if (D < B) cout << "No" << endl;
      else if (B <= C) cout << "Yes" << endl;
      else {
        lli g = __gcd(B, D);
        lli mx = (A % g) + (B - g);
        cout << (C < mx ? "No" : "Yes") << endl;
      }
    }
  }
  
  return 0;
}
