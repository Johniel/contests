// github.com/Johniel/contests
// codeforces/881div3/E/main.cpp

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
  int _;
  while (cin >> _) {
    while (_--) {
      int n, m;
      cin >> n >> m;
      vec<pair<int, int>> v(m);
      cin >> v;
      each (i, v) --i.first;
      int q;
      cin >> q;
      vec<int> a(q);
      cin >> a;
      each (i, a) --i;

      auto fn = [&] (int x) {
        BIT<int> bit(n);
        for (int i = 0; i < x; ++i) {
          bit.add(a[i], 1);
        }
        each (i, v) {
          int _1 = bit(i.first, i.second);
          int _0 = i.second - i.first - _1;
          if (_0 < _1) return true;
        }
        return false;
      };

      int small = 0;
      int large = a.size();
      while (small + 1 < large) {
        int mid = (small + large) / 2;
        if (fn(mid)) large = mid;
        else small = mid;
      }
      if (0) ;
      else if (fn(small)) cout << small << endl;
      else if (fn(large)) cout << large << endl;
      else cout << -1 << endl;
    }
  }
  return 0;
}
