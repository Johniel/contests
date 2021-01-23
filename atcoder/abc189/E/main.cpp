// atcoder/abc189/E/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; for (auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, set<T> s) { os << "#{"; for (auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "{"; for (auto& i: m) os << i << ","; os << "}"; return os; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

using lli = long long int;
using ull = unsigned long long;
using point = complex<double>;
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;

const int S = 3;
struct M {
  lli val[S][S];
  M() {
    for (int i = 0; i < S; ++i) {
      for (int j = 0; j < S; ++j) {
        val[i][j] = 0;
      }
    }
  }
};

M operator * (M a, M b) {
  M c;
  for (int k = 0; k < S; ++k) {
    for (int i = 0; i < S; ++i) {
      for (int j = 0; j < S; ++j) {
        c.val[i][j] += a.val[i][k] * b.val[k][j];
      }
    }
  }
  return c;
}

M e(void)
{
  M m;
  for (int i = 0; i < S; ++i) {
    m.val[i][i] = 1;
  }
  return m;
}


int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n;
  while (cin >> n) {
    vec<pair<lli, lli>> v(n);
    cin >> v;

    int m;
    cin >> m;
    vec<pair<int, int>> op(m);
    for (int i = 0; i < m; ++i) {
      cin >> op[i].first;
      if (op[i].first == 3 || op[i].first == 4) cin >> op[i].second;
    }

    int q;
    cin >> q;
    vec<pair<int, int>> r(q);
    cin >> r;
    each (i, r) {
      // --i.first;
      --i.second;
    }

    vec<M> mat;
    mat.push_back(e());
    each (i, op) {
      int z = i.first;
      int p = i.second;
      if (z == 1) {
        M x;
        x.val[0][0] = 0;
        x.val[0][1] = 1;
        x.val[1][0] = -1;
        x.val[1][1] = 0;
        x.val[2][2] = 1;
        // mat.push_back(mat.back() * x);
        mat.push_back(x * mat.back());
      }
      if (z == 2) {
        M x;
        x.val[0][0] = 0;
        x.val[0][1] = -1;
        x.val[1][0] = 1;
        x.val[1][1] = 0;
        x.val[2][2] = 1;
        // mat.push_back(mat.back() * x);
        mat.push_back(x * mat.back());
      }
      if (z == 3) {
        M x;
        x.val[0][0] = 1;
        x.val[1][1] = 1;
        x.val[2][2] = 1;
        x.val[0][2] = -p;
        M y;
        y.val[0][0] = -1;
        y.val[1][1] = 1;
        y.val[2][2] = 1;
        M z;
        z.val[0][0] = 1;
        z.val[1][1] = 1;
        z.val[2][2] = 1;
        z.val[0][2] = +p;

        M tmp = x * y * z;
        // mat.push_back(mat.back() * x * y * z);
        mat.push_back(z * y * x * mat.back());
      }
      if (z == 4) {
        M x;
        x.val[0][0] = 1;
        x.val[1][1] = 1;
        x.val[2][2] = 1;
        x.val[1][2] = -p;
        M y;
        y.val[0][0] = 1;
        y.val[1][1] = -1;
        y.val[2][2] = 1;
        M z;
        z.val[0][0] = 1;
        z.val[1][1] = 1;
        z.val[2][2] = 1;
        z.val[1][2] = +p;
        // mat.push_back(mat.back() * x * y * z);
        mat.push_back(z * y * x * mat.back());
      }
    }

    each (i, r) {
      lli x = v[i.second].first;
      lli y = v[i.second].second;

      lli a = x * mat[i.first].val[0][0] + y * mat[i.first].val[0][1] + mat[i.first].val[0][2];
      lli b = x * mat[i.first].val[1][0] + y * mat[i.first].val[1][1] + mat[i.first].val[1][2];
      cout << a << ' ' << b << endl;
    }
  }

  return 0;
}
