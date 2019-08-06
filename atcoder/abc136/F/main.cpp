// atcoder/abc136/F/main.cpp
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

template<lli MOD>
struct Fp {
    lli val;
    constexpr Fp(lli v = 0) noexcept : val(v % MOD) {
        if (val < 0) v += MOD;
    }
    constexpr int getmod() { return MOD; }
    constexpr Fp operator - () const noexcept {
        return val ? MOD - val : 0;
    }
    constexpr Fp operator + (const Fp& r) const noexcept { return Fp(*this) += r; }
    constexpr Fp operator - (const Fp& r) const noexcept { return Fp(*this) -= r; }
    constexpr Fp operator * (const Fp& r) const noexcept { return Fp(*this) *= r; }
    constexpr Fp operator / (const Fp& r) const noexcept { return Fp(*this) /= r; }
    constexpr Fp& operator += (const Fp& r) noexcept {
        val += r.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }
    constexpr Fp& operator -= (const Fp& r) noexcept {
        val -= r.val;
        if (val < 0) val += MOD;
        return *this;
    }
    constexpr Fp& operator *= (const Fp& r) noexcept {
        val = val * r.val % MOD;
        return *this;
    }
    constexpr Fp& operator /= (const Fp& r) noexcept {
        lli a = r.val, b = MOD, u = 1, v = 0;
        while (b) {
            lli t = a / b;
            a -= t * b; swap(a, b);
            u -= t * v; swap(u, v);
        }
        val = val * u % MOD;
        if (val < 0) val += MOD;
        return *this;
    }
    constexpr bool operator == (const Fp& r) const noexcept {
        return this->val == r.val;
    }
    constexpr bool operator != (const Fp& r) const noexcept {
        return this->val != r.val;
    }
    friend constexpr ostream& operator << (ostream &os, const Fp<MOD>& x) noexcept {
        return os << x.val;
    }
    friend constexpr istream& operator >> (istream &is, Fp<MOD>& x) noexcept {
        return is >> x.val;
    }
    friend constexpr Fp<MOD> modpow(const Fp<MOD> &a, lli n) noexcept {
        if (n == 0) return 1;
        auto t = modpow(a, n / 2);
        t = t * t;
        if (n & 1) t = t * a;
        return t;
    }
};

template<typename V>
class BIT {
public:
  vector<V> bit;
  int n;
  BIT (int n_)
  {
    n = n_;
    bit.resize(n + 1);
  }
  V sum(int i)
  {
    ++i; // 1-origin
    V s = 0;
    while (i > 0) {
      s += bit[i];
      i -= i & -i;
    }
    return s;
  }
  void add(int i, V x)
  {
    ++i; // 1-origin
    while (i <= n)
    {
      bit[i] += x;
      i += i & -i;
    }
    return ;
  }
  void set(int i, V x)
  {
    return add(i, x - bit[i]);
  }
  V query(int begin, int end)
  {
    return sum(end) - sum(begin - 1);
  }
};

constexpr lli mod = 998244353;
using mint = Fp<mod>;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    vector<pair<int, int>> v(n);
    cin >> v;

    vector<int> x;
    vector<int> y;
    each (i, v) {
      x.push_back(i.first);
      y.push_back(i.second);
    }
    sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());
    sort(y.begin(), y.end());
    y.erase(unique(y.begin(), y.end()), y.end());
    map<int, int> m1;
    map<int, int> m2;
    for (int i = 0; i < x.size(); ++i) {
      m1[x[i]] = i;
    }
    for (int i = 0; i < y.size(); ++i) {
      m2[y[i]] = i;
    }
    each (i, v) i = make_pair(m1[i.first], m2[i.second]);
    sort(v.begin(), v.end());

    const int N = 2 * 1e5 + 5;

    static int a[N];
    static int b[N];
    static int c[N];
    static int d[N];

    {
      BIT<int> bit(n + 2);
      for (int i = 0; i < v.size(); ++i) {
        a[i] = bit.query(0, v[i].second);
        b[i] = bit.query(v[i].second + 1, n + 1);
        bit.add(v[i].second, 1);
      }
    }

    {
      BIT<int> bit(n + 2);
      for (int i = 0; i < v.size(); ++i) {
        int j = n - i - 1;
        c[j] = bit.query(0, v[j].second);
        d[j] = bit.query(v[j].second + 1, n + 1);
        bit.add(v[j].second, 1);
      }
    }

    mint sum(0);
    static mint p[N];
    p[0] = 1;
    for (int i = 1; i < N; ++i) {
      p[i] = p[i - 1] * 2;
    }
    for (int i = 0; i < v.size(); ++i) {
      sum += 1;
      sum += (p[a[i]] - 1);
      sum += (p[b[i]] - 1);
      sum += (p[c[i]] - 1);
      sum += (p[d[i]] - 1);

      sum += (p[a[i]] - 1) * (p[b[i]] - 1);
      sum += (p[c[i]] - 1) * (p[d[i]] - 1);

      sum += (p[a[i]] - 1) * (p[c[i]] - 1);
      sum += (p[b[i]] - 1) * (p[d[i]] - 1);

      sum += (p[a[i]] - 1) * (p[d[i]] - 1) * 2;
      sum += (p[b[i]] - 1) * (p[c[i]] - 1) * 2;

      sum += (p[a[i]] - 1) * (p[d[i]] - 1) * (p[b[i]] - 1) * 2;
      sum += (p[a[i]] - 1) * (p[d[i]] - 1) * (p[c[i]] - 1) * 2;
      sum += (p[b[i]] - 1) * (p[c[i]] - 1) * (p[a[i]] - 1) * 2;
      sum += (p[b[i]] - 1) * (p[c[i]] - 1) * (p[d[i]] - 1) * 2;

      sum += (p[b[i]] - 1) * (p[c[i]] - 1) * (p[a[i]] - 1) * (p[d[i]] - 1) * 2;
    }
    cout << sum << endl;
  }

  return 0;
}
