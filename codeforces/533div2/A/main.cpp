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
    vector<int> a(n);
    cin >> a;

    int x;
    lli mn = 1LL << 60;
    for (int t = 1; t <= 101; ++t) {
      lli sum = 0;
      each (i, a) {
        lli y = 1LL << 60;;
        for (int j = t - 1; j <= t + 1; ++j) {
          setmin<lli>(y, abs(i - j));
        }
        sum += y;
      }
      if (sum < mn) {
        x = t;
        mn = sum;
      }
    }
    cout << x << ' ' << mn << endl;
  }
  
  return 0;
}
