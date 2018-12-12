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

  const lli mod = 1e9 + 7;

  int n, m;
  while (cin >> n >> m) {
    vector<lli> a(n);
    vector<lli> b(m);
    cin >> a >> b;

    lli sum = 0;

    lli x = 0;
    for (int i = 0; i + 1 < n; ++i) {
      x += (a[i + 1] * (i + 1) * (n - i - 1)) % mod;
      x = (mod + x - a[i] * (i + 1) * (n - i - 1)) % mod;
    }

    lli y = 0;
    for (int j = 0; j + 1 < m; ++j) {
      y += (b[j + 1] * (j + 1) * (m - j - 1)) % mod;
      y = (mod + y - b[j] * (j + 1) * (m - j - 1)) % mod;
    }

    cout << (x * y) % mod << endl;
    continue;
    
    for (int i = 0; i + 1 < n; ++i) {
      for (int j = 0; j + 1 < m; ++j) {
        lli x = a[i + 1] - a[i];
        lli y = b[j + 1] - b[j];
 
        lli z = (x * y) % mod;
        z *= (i + 1) * (n - i - 1) * (j + 1) * (m - j - 1);
        
        (sum += z % mod) %= mod;
      }
    }
    
    // lli p = (a.back() - a.front()) % mod;
    // lli q = (b.back() - b.front()) % mod;
    
    // lli r = (p * q) % mod;

    // r *= (n - 1) * (m - 1);
    // r %= mod;
    // cout << r << endl;
  }

  return 0;
}
