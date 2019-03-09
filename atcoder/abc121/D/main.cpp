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

bool f(ull n, int i)
{
  if (i == 0) {
    return ((n / 2) + (n % 2)) % 2;
  }

  ull x = ull(1) << (i + 1);
  ull y = ull(1) << i;
  return (n % x) >= y && ((n % x) - y) % 2 == 0;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  ull a, b;
  while (cin >> a >> b) {
    ull c = 0;
    for (int i = 0; i < 63; ++i) {
      c |= (ull(1) << i) * (f(a - 1, i) != f(b, i));
    }
    cout << c << endl;
  }

  return 0;
}
