// github.com/Johniel/contests
// codeforces/903div3/G/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define each_with_index(i, e, c) for (const auto i: views::iota(0, (int)c.size())) if (auto& e = c.at(i); true)
#define each_pair(p, c) for (const auto _i: views::iota(0, (int)c.size())) if (std::pair<const int, decltype((c.at(_i)))> p = {_i, c[_i]}; true)
#define unless(cond) if (!(cond))
// #define endl "\n"

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; for (auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, set<T> s) { os << "#{"; for (auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "{"; for (auto& i: m) os << i << ","; os << "}"; return os; }
template<typename E, size_t N> istream& operator >> (istream& is, array<E, N>& a) { for (auto& i: a) is >> i; return is; }
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[" << N << "]{"; for (auto& i: a) os << i << ","; os << "}"; return os; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

__attribute__((constructor)) static void ___initio(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
// constexpr lli mod = 1e9 + 7;
constexpr lli mod = 998244353;

// from: https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a
template<int MOD> struct Fp {
  long long val;
  constexpr Fp(long long v = 0) noexcept : val(v % MOD) {
    if (val < 0) val += MOD;
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
    long long a = r.val, b = MOD, u = 1, v = 0;
    while (b) {
      long long t = a / b;
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
  friend constexpr Fp<MOD> modpow(const Fp<MOD> &a, long long n) noexcept {
    if (n == 0) return 1;
    auto t = modpow(a, n / 2);
    t = t * t;
    if (n & 1) t = t * a;
    return t;
  }
};
template<int MOD> istream& operator >> (istream& is, Fp<MOD>& m) { is >> m.val; m.val %= MOD; return is; }
template<int MOD> ostream& operator << (ostream& os, const Fp<MOD>& m) { os << m.val; return os; }

template<typename T = long long int>
struct BIT {
  vector<T> v;
  int n;

  BIT(int n_ = 0) {
    n = n_;
    v.resize(n + 1, 0);
  }

  T operator () (int i) const {
    T s = 0;
    while (i > 0) {
      s += v.at(i);
      i -= i & -i;
    }
    return s;
  }

  T operator () (int begin, int end) const {
    assert(begin <= end);
    return (*this)(end) - (*this)(begin);
  }

  T operator [] (int idx) const {
    return (*this)(idx + 1) - (*this)(idx);
  }

  void add(int i, T x) {
    ++i;
    while (i <= n) {
      v.at(i) += x;
      i += i & -i;
    }
    return ;
  }

  static bool verify(void) {
    vector<int> v;
    v.push_back(1 << 0);
    v.push_back(1 << 2);
    v.push_back(1 << 1);
    v.push_back(1 << 4);
    v.push_back(1 << 3);
    v.push_back(1 << 6);
    v.push_back(1 << 5);

    BIT<int> bit(v.size());
    for (int i = 0; i < v.size(); ++i) {
      bit.add(i, v[i]);
    }

    if (bit(1, 3) != v[1] + v[2]) return false;

    int sum = 0;
    for (int i = 0; i < v.size(); ++i) {
      if (sum != bit(i)) return false;
      sum += v[i];
    }
    if (sum != bit(v.size())) return false;

    for (int i = 0; i < v.size(); ++i) {
      int sum = 0;
      for (int j = i; j < v.size(); ++j) {
        if (sum != bit(i, j)) return false;
        sum += v[j];
      }
      if (sum != bit(i, v.size())) return false;
    }

    return true;
  }
};

int main(int argc, char *argv[])
{
  { int _; cin >> _; }
  int n, q;
  str s;
  while (cin >> n >> q >> s) {
    BIT<Fp<26>> bit(n+1);
    for (int i = 0; i < s.size(); ++i) {
      int x = s[i] - 'a';
      bit.add(i, x);
      bit.add(i + 1, -x);
    }

    set<int> idx2;
    for (int i = 0; i + 1 < s.size(); ++i) {
      if (s[i] == s[i + 1]) idx2.insert(i);
    }
    set<int> idx3;
    for (int i = 0; i + 2 < s.size(); ++i) {
      if (s[i] == s[i + 2]) idx3.insert(i);
    }


    while (q--) {
      int op;
      cin >> op;

      // for (int i = 0; i < n; ++i) cout << (char)(bit(i+1).val + 'a'); cout << endl;
      // cout << idx2 << endl;
      // cout << idx3 << endl;

      if (op == 1) {
        int begin, end, x;
        cin >> begin >> end >> x;
        --begin;
        bit.add(begin, x);
        bit.add(end, -x);

        for (int i = max(0, begin - 1); i < begin + 2 && i + 2 <= s.size(); ++i) {
          idx2.erase(i);
          if (bit(i + 1) == bit(i + 2)) idx2.insert(i);
        }
        for (int i = max(0, end - 1); i < end + 2 && i + 2 <= s.size(); ++i) {
          idx2.erase(i);
          if (bit(i + 1) == bit(i + 2)) idx2.insert(i);
        }

        for (int i = max(0, begin - 2); i < begin + 2 && i + 3 <= s.size(); ++i) {
          idx3.erase(i);
          if (bit(i + 1) == bit(i + 3)) idx3.insert(i);
        }
        for (int i = max(0, end - 2); i < end + 2 && i + 3 <= s.size(); ++i) {
          idx3.erase(i);
          if (bit(i + 1) == bit(i + 3)) idx3.insert(i);
        }

      }
      if (op == 2) {
        int begin, end;
        cin >> begin >> end;
        --begin;
        bool f = false;

        auto itr2 = idx2.lower_bound(begin);
        if (itr2 != idx2.end() && *itr2 <= end - 2) f = true;

        auto itr3 = idx3.lower_bound(begin);
        if (itr3 != idx3.end() && *itr3 <= end - 3) f = true;

        cout << (!f ? "YES" : "NO") << endl;
      }
    }
    // break;
  }
  return 0;
}
