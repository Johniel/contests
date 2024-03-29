// atcoder/arc120/C/main.cpp
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
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n;
  while (cin >> n) {
    vec<int> a(n), b(n);
    cin >> a >> b;
    vec<pair<int, int>> x, y;
    for (int i = 0; i < a.size(); ++i) {
      x.push_back(make_pair(a[i] + i, i));
    }
    for (int i = 0; i < b.size(); ++i) {
      y.push_back(make_pair(b[i] + i, i));
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    bool f = true;
    for (int i = 0; i < n; ++i) {
      f = f && (x[i].first == y[i].first);
    }
    if (!f) {
      cout << -1 << endl;
      continue;
    }
    vec<int> v(n);
    for (int i = 0; i < n; ++i) {
      v[y[i].second] = x[i].second;
    }
    BIT<lli> bit(n);
    lli z = 0;
    for (int i = 0; i < n; ++i) {
      z += i - bit(v[i]);
      bit.add(v[i], 1);
    }
    cout << z << endl;
  }

  return 0;
}
