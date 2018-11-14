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
struct Acc {
  vector<T> sum;
  Acc(vector<T> v) {
    sum.push_back(0);
    each (i, v) {
      sum.push_back(sum.back() + i);
    }
  }
  T query(int begin, int end) {
    return sum[end] - sum[begin];
  }
};

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  const lli mod = 1e9 + 7;
  const int N = 100000 + 5;
  lli x[N];
  x[0] = 0;
  x[1] = 1;
  for (int i = 2; i < N; ++i) {
    x[i] = x[i - 1] * 2 + 1;
    x[i] %= mod;
  }

  int n, q;
  string s;
  while (cin >> n >> q >> s) {
    vector<int> v;
    each (c, s) v.push_back(c - '0');
    Acc<int> acc(v);
    while (q--) {
      int a, b;
      cin >> a >> b;
      --a;
      int one = acc.query(a, b);
      int zero = b - a - one;
      int len = one + zero;
      cout << (x[len] - x[zero] + mod) % mod << endl;
      // cout << (1 << len) - (1 << zero) << endl;
    }
  }

  return 0;
}
