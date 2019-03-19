// codeforces/547div3/E/main.cpp
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

  lli h;
  lli n;
  while (cin >> h >> n) {
    vector<lli> v(n);
    cin >> v;

    lli sum = accumulate(v.begin(), v.end(), 0LL);
    if (0 <= sum) {
      int y = -1;
      for (int i = 0; i < v.size(); ++i) {
        h += v[i];
        if (h <= 0) {
          y = i + 1;
          break;
        }
      }
      cout << y << endl;
      continue;
    }

    lli neg = 0;
    each (i, v) {
      if (i < 0) neg += abs(i);
    }

    sum = abs(sum);
    neg = abs(neg);

    lli x = max(0LL, (h - neg) / sum);
    h -= x * sum;
    x *= n;
    while (0 < h) {
      each (i, v) {
        h += i;
        ++x;
        unless (0 < h) break;
      }
    }
    cout << x << endl;
  }

  return 0;
}
