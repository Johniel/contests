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

const lli inf = 1LL << 60;

template<typename T>
struct RMQ {
  int n;
  vector<T> dat;

  RMQ(int n_) {
    n = 1;
    while (n < n_) n *= 2;
    dat.resize(2 * n - 1, inf);
  }

  void update(int k, T a) {
    k += n - 1;
    dat[k] = a;
    while (k > 0) {
      k = (k - 1) / 2;
      dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);
    }
  }

  T query(size_t a, size_t b) {
    return query(a, b, 0, 0, n);
  }

  T query(size_t a, size_t b, size_t k, size_t l, size_t r) {
    if (r <= a || b <= l) return inf;
    if (a <= l && r <= b) return dat.at(k);

    T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
    T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);

    return min(vl, vr);
  }
};

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    vector<lli> a(n);
    cin >> a;
    
    map<lli, int> idx;
    for (int i = 0; i < a.size(); ++i) {
      idx[a[i]] = i;
    }

    RMQ<lli> rmq(n);
    for (int i = 0; i < a.size(); ++i) {
      rmq.update(i, a[i]);
    }
    
    lli sum = 0;

    function<void(int, int)> rec = [&] (int begin, int end) {
      unless (begin < end) {
        return ;
      }
      lli x = rmq.query(begin, end);
      int i = idx[x];
      sum += x * (i - begin + 1) * (end - i);
      rec(begin, i);
      rec(i + 1, end);
      return ;
    };
    rec(0, n);

    cout << sum << endl;
  }

  return 0;
}
