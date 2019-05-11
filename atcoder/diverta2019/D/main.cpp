// atcoder/diverta2019/D/main.cpp
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

  lli n;
  while (cin >> n) {
    set<lli> v;
    auto fn = [&] (lli x) {
      lli m = (n / x) - 1;
      if (m == 0 || n % m == 0) return 0LL;
      return n / m == n % m ? m : 0;
    };

    lli sum = 0;
    for (lli i = 1; i * i <= n; ++i) {
      if (n % i) continue;
      lli x = i;
      lli y = n / i;
      sum += (x != y ? fn(x) + fn(y) : fn(x));
    }
    cout << sum << endl;
  }

  return 0;
}
