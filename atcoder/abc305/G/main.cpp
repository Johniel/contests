// github.com/Johniel/contests
// atcoder/abc305/G/main.cpp

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

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 998244353;

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

void show(math::Matrix x)
{
  for (int i = 0; i < x.val.size(); ++i) {
    for (int j = 0; j < x.val[i].size(); ++j) {
      cout << x.val[i][j] << ' ';
    }
    cout << endl;
  }
  return ;
}

int main(int argc, char *argv[])
{
  lli n, m;
  while (cin >> n >> m) {
    vec<str> v(m);
    cin >> v;

    auto is_taboo = [&] (int x, int width) {
      str s;
      for (int i = 0; i < width; ++i) {
        s += 'a' + (x % 2);
        x /= 2;
      }
      reverse(s.begin(), s.end());
      each (t, v) {
        if (s.find(t) != string::npos) return true;
      }
      return false;
    };

    const int L = 5;
    if (n < L) {
      int z = 0;
      for (int i = 0; i < (1 << n); ++i) {
        z += !is_taboo(i, n);
      }
      cout << z << endl;
      continue;
    }

    const int M = (1 << L);
    math::Matrix b(1, M);
    for (int i = 0; i < M; ++i) {
      unless (is_taboo(i, L)) b.at(0, i) = 1;
    }

    math::Matrix a(M, M);
    for (int i = 0; i < M; ++i) {
      int j = i * 2 + 1;
      int k = i * 2 + 0;
      a.val[i][j & (M - 1)] += !is_taboo(j, L+1);
      a.val[i][k & (M - 1)] += !is_taboo(k, L+1);
    }

    math::Matrix c = b * math::Matrix::pow(a, n - L);

    lli z = 0;
    for (int i = 0; i < M; ++i) {
      (z += c.val[0][i]) %= mod;
    }
    cout << z << endl;
  }
  return 0;
}
