// github.com/Johniel/contests
// atcoder/abc293/E/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
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
template<typename T> using heap = priority_queue<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
lli mod;
// constexpr lli mod = 998244353;

namespace math {
  struct Matrix {
    vec<vec<lli>> val;
    Matrix(int n) {
      assert(0 < n);
      val.resize(n, vec<lli>(n, 0));
    }
    Matrix(int h, int w) {
      assert(0 < h && 0 < w);
      val.resize(h, vec<lli>(w, 0));
    }
    Matrix(vec<vec<lli>> v) : val(v) {}
    size_t h(void) const { return val.size(); }
    size_t w(void) const { return val[0].size(); }
    lli& at(int i, int j) { return val.at(i).at(j); }

    static Matrix E(int n) ;
    static Matrix pow(Matrix a, lli p) ;
  };
  Matrix operator * (Matrix a, Matrix b) {
    assert(a.w() == b.h());
    Matrix c(a.h(), b.w());
    for (int k = 0; k < b.h(); ++k) {
      for (int i = 0; i < c.h(); ++i) {
        for (int j = 0; j < c.w(); ++j) {
          (c.at(i, j) += a.at(i, k) * b.at(k, j) % mod) %= mod;
        }
      }
    }
    return c;
  }
  Matrix Matrix::E(const int n) {
    Matrix e(n, n);
    for (int i = 0; i < n; ++i) {
      e.at(i, i) = 1;
    }
    return e;
  }
  Matrix Matrix::pow(Matrix a, lli p) {
    if (p == 0) return Matrix::E(a.h());
    if (p == 1) return a;
    Matrix b = Matrix::pow(a, p / 2);
    b = b * b;
    if (p % 2) b = b * a;
    return b;
  }
};

int main(int argc, char *argv[])
{
  lli a, x;
  while (cin >> a >> x >> mod) {
    // An+1 = x * An + 1 := [An+1 \\ 1] := [x && 1 \\ 0 && 1] * [An \\ 1]; ABC293E
    vec<vec<lli>> v({{a % mod, 1}, {0, 1}});
    math::Matrix m(v);
    m = math::Matrix::pow(m, x);
    cout << m.at(0, 1) % mod << endl;
  }
  return 0;
}
