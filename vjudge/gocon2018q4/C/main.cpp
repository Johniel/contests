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

  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;

    map<int, int> cnt_odd;
    map<int, int> cnt_even;

    lli even = 0;
    lli odd = 0;
    each (i, a) {
      if (i % 2) ++odd;
      else ++even;
    }
    
    lli sum = odd * (odd - 1) / 2 + even * (even - 1) / 2;
    each (i, a) {
      const int zero = i ^ 0;
      const int one = i ^ 1;
      const int two = i ^ 2;
      const int three = i ^ 3;

      if (i % 2) {
        sum -= cnt_odd[zero] + cnt_odd[one] + cnt_odd[two] + cnt_odd[three];
        ++cnt_odd[i];
      } else {
        sum -= cnt_even[zero] + cnt_even[one] + cnt_even[two] + cnt_even[three];
        ++cnt_even[i];
      }
    }

    cout << sum << endl;
  }
  
  return 0;
}
