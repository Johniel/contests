// atcoder/abc088/D/main.cpp
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
    vector<int> a(n);
    vector<int> b(n);
    cin >> a >> b;

    int z = 0;
    for (int k = 1 << 29; k; k /= 2) {
      each (i, a) i %= (k << 1);
      each (i, b) i %= (k << 1);
      sort(a.begin(), a.end());
      sort(b.begin(), b.end());
      int cnt = 0;
      each (i, a) {
        if (k & i) {
          cnt += lower_bound(b.begin(), b.end(), (k << 1) - i) - b.begin();
          cnt += b.end() - lower_bound(b.begin(), b.end(), (k << 1) + k - i);
        } else {
          cnt += lower_bound(b.begin(), b.end(), (k << 1) - i) - lower_bound(b.begin(), b.end(), k - i);
        }
      }
      if (cnt % 2) z |= k;
    }
    cout << z << endl;
  }

  return 0;
}
