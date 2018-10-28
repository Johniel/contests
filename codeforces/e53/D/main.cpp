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

template<typename T>
class BIT {
public:
  BIT(int n_)
  {
    n = n_;
    bit.resize(n + 1, 0);
  }
  void add(int i, T x)
  {
    assert(0 <= i);
    return _add(i + 1, x);
  }
  T sum(int i)
  {
    T s = 0;
    while (i > 0) {
      s += bit[i];
      i -= i & -i;
    }
    return s;
  }
private:
  vector<T> bit;
  int n;
  void _add(int i, T x)
  {
    while (i <= n) {
      bit[i] += x;
      i += i & -i;
    }
    return ;
  }
};

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  lli t;
  while (cin >> n >> t) {
    vector<lli> a(n);
    cin >> a;

    BIT<lli> bit(n);
    for (int i = 0; i < n; ++i) {
      bit.add(i, a[i]);
    }

    lli x = 0;
    for (int i = 0; i < n; ++i) {
      lli y = bit.sum(n);
      if (y <= t) {
        x += (t / y) * (n - i);
        t %= y;
      }
      
      int small = 0;
      int large = n;
      while (small + 1 < large) {
        int mid = (small + large) / 2;
        if (bit.sum(mid) <= t) small = mid;
        else large = mid;
      }

      bit.add(small, -1 * a[small]);
    }

    cout << x << endl;
  }
  
  return 0;
}
