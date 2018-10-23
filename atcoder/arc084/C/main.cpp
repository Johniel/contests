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
    vector<int> c(n);
    cin >> a >> b >> c;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    vector<lli> cnt(n + 1, 0);
    for (int i = 0; i < n; ++i) {
      cnt[i] = n - (upper_bound(c.begin(), c.end(), b[i]) - c.begin());
    }

    for (int i = n - 2; 0 <= i; --i) {
      cnt[i] += cnt[i + 1];
    }

    lli sum = 0;
    for (int i = 0; i < n; ++i) {
      int j = upper_bound(b.begin(), b.end(), a[i]) - b.begin();
      sum += cnt[j];
    }
    cout << sum << endl;
  }

  return 0;
}
