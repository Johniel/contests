// atcoder/abc136/E/main.cpp
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

  lli n, k;
  while (cin >> n >> k) {
    vector<lli> a(n);
    cin >> a;

    const lli sum = accumulate(a.begin(), a.end(), 0LL);
    vector<lli> v;
    for (lli i = 1; i * i <= sum; ++i) {
      if (sum % i == 0) {
        v.push_back(i);
        v.push_back(sum / i);
      }
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    auto fn = [&] (lli x) {
      vector<pair<lli, lli>> v;
      each (i, a) {
        v.push_back(make_pair(i % x, x - (i % x)));
      }
      sort(v.begin(), v.end(), [] (auto i, auto j) { return i.second - i.first > j.second - j.first; });
      lli p = 0;
      each (i, v) p += i.second;
      lli q = 0;
      each (i, v) {
        p -= i.second;
        q += i.first;
        if (p == q && p <= k) return true;
      }
      return false;
    };

    lli x = -1;
    each (i, v) {
      if (fn(i)) x = i;
    }
    cout << x << endl;
  }

  return 0;
}
