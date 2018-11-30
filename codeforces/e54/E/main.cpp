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
  while (cin >> n) {
    vector<int> g[n];

    for (int i = 0; i < n - 1; ++i) {
      int x, y;
      cin >> x >> y;
      --x;
      --y;
      g[x].push_back(y);
      g[y].push_back(x);
    }

    vector<pair<int, int>> q[n];

    int m;
    cin >> m;
    while (m--) {
      int v, d, x;
      cin >> v >> d >> x;
      --v;
      q[v].push_back(make_pair(d, x));
    }

    lli sum[n];
    fill(sum, sum + n, 0);

    BIT<lli> bit(n);
    function<void(int, int, int)> rec = [&] (int curr, int prev, int depth) {
       each (i, q[curr]) {
         bit.add(depth, i.second);
         bit.add(depth + i.first + 1, -i.second);
       }
       sum[curr] += bit.sum(depth + 1);
       each (next, g[curr]) {
         if (next != prev) {
           rec(next, curr, depth + 1);
         }
       }
       each (i, q[curr]) {
         bit.add(depth, -i.second);
         bit.add(depth + i.first + 1, i.second);
       }
       return ;
    };
    rec(0, -1, 0);
    for (int i = 0; i < n; ++i) {
      if (i) cout << ' ';
      cout << sum[i];
    }
    cout << endl;
  }

  return 0;
}
