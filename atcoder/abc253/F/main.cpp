// atcoder/abc253/F/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

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
// constexpr lli mod = 998244353;

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

  void add(int i, T x) {
    ++i;
    while (i <= n) {
      v.at(i) += x;
      i += i & -i;
    }
    return ;
  }
};

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int h, w, q;
  while (cin >> h >> w >> q) {
    vec<vec<int>> v;
    for (int k = 0; k < q; ++k) {
      int op;
      cin >> op;
      if (op == 1) {
        int i, j, x;
        cin >> i >> j >> x;
        --i;
        --j;
        v.push_back({op, i, j, x});
      } else if (op == 2) {
        int i, x;
        cin >> i >> x;
        --i;
        v.push_back({op, i, x});
      } else if (op == 3) {
        int i, j;
        cin >> i >> j;
        --i;
        --j;
        v.push_back({op, i, j});
      }
    }

    const int N = 2 * 1e5 + 3;

    static int prev[N];
    fill(prev, prev, 0);
    map<int, vec<pair<int, int>>> m;
    for (int k = 0; k < v.size(); ++k) {
      int op = v[k][0];
      if (op == 2) {
        int i, x;
        i = v[k][1];
        x = v[k][2];
        prev[i] = k;
      }
      if (op == 3) {
        int i, j;
        i = v[k][1];
        j = v[k][2];
        m[prev[i]].push_back(make_pair(i, j));
      }
    }

    BIT<lli> sum(N);
    map<pair<int, pair<int, int>>, lli> y;
    vec<int> z(N, 0);
    fill(prev, prev, 0);
    for (int k = 0; k < v.size(); ++k) {
      if (m.count(k)) {
        each (j, m[k]) y[make_pair(k, j)] = sum(j.second + 1);
      }
      int op = v[k][0];
      if (op == 1) {
        int i, j, x;
        i = v[k][1];
        j = v[k][2];
        x = v[k][3];
        sum.add(i,     +x);
        sum.add(j + 1, -x);
      }
      if (op == 2) {
        int i, x;
        i = v[k][1];
        x = v[k][2];
        z[i] = x;
        prev[i] = k;
      }
      if (op == 3) {
        int i, j;
        i = v[k][1];
        j = v[k][2];
        cout << (sum(0, j + 1) - y[make_pair(prev[i], make_pair(i, j))]) + z[i] << endl;
      }
    }
  }

  return 0;
}
