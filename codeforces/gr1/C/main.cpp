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

bool is_prime(int n)
{
  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0) return false;
  }
  return true;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int q;
  while (cin >> q) {
    vector<int> v(q);
    cin >> v;

    each (a, v) {
      int mx = 0;
      for (int i = 0; i < 30; ++i) {
        setmax(mx, a & (1 << i));
      }
      int b = ((mx << 1) - 1) ^ a;
      // cout <<" >> "  << mx << ' ' << b << endl;
      if (b) {
        cout << __gcd(a ^ b, a & b) << endl;
      } else {
        int c = 0;
        for (int i = 2; i * i <= a; ++i) {
          if (a % i == 0) {
            setmax(c, a / i);
          }
        }
        cout << (c ? c : 1) << endl;
      }
    }

    // each (a, v) {
    //   for (int b = 1; b < a; ++b) {
    //     cout << make_pair(a, b) << ": " << __gcd(a ^ b, a & b) << endl;
    //   }
    //   cout << endl;
    // }
  }

  return 0;
}
