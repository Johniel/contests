// codeforces/587div3/D/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

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

  int n;
  while (cin >> n) {
    vector<lli> a(n);
    cin >> a;

    sort(a.begin(), a.end());
    lli x = a[1] - a[0];
    for (int i = 1; i + 1 < a.size(); ++i) {
      x = __gcd(x, a[i + 1] - a[i]);
    }

    lli y = x;
    // lli y = 1;
    // for (lli i = 2; i*i <= x; ++i) {
    //   if (x % i == 0) {
    //     y *= i;
    //     while (x % i == 0) x /= i;
    //   }
    // }
    // if (x != 1) y *= x;

    lli z = a.back() * n - accumulate(a.begin(), a.end(), 0LL);
    if (z < 0) {
      z += (abs(z) / y + bool(abs(z) % y)) * y;
    }
    cout << z / y << ' ' << y << endl;
  }


  return 0;
}
