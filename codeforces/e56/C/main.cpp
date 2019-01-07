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
    vector<lli> a(n, 0);
    for (int i = 0; i < n / 2; ++i) {
      cin >> a[i];
    }
    reverse(a.begin(), a.end());

    for (int i = 1; i < n / 2; ++i) {
      int j = n - 1 - i;
      auto tmp = a[j];
      setmin(a[j], a[j + 1]);
      a[i] = tmp - a[j];

      tmp = a[i];
      setmax(a[i], a[i - 1]);
      a[j] -= abs(tmp - a[i]);
    }
    each (i, a) cout << i << ' ' << flush; cout << endl;
  }
  
  return 0;
}
