// atcoder/abl/E/main.cpp
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
constexpr lli mod = 998244353;

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
      (s += v.at(i)) %= mod;
      i -= i & -i;
    }
    return s;

  }

  T operator () (int begin, int end) const {
    return ((*this)(end) - (*this)(begin) + mod) % mod;
  }

  void add(int i, T x) {
    ++i;
    while (i <= n) {
      (v.at(i) += x) %= mod;
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

  int n, q;
  while (cin >> n >> q) {
    const int N = 200000 + 5;
    BIT<lli> bit(N);
    {
      vec<lli> v;
      lli w = 1;
      for (int i = 0; i < n; ++i) {
        v.push_back(w);
        (w *= 10) %= mod;
      }
      reverse(v.begin(), v.end());
      for (int i = 0; i < v.size(); ++i) {
        bit.add(i, v[i]);
      }
      // cout << v << endl;
    }

    const int inf = 1 << 29;

    lli sum = bit(0, N);

    set<vec<lli>> s;
    s.insert({0, n - 1, 1});

    while (q--) {
      lli begin, end, w;
      cin >> begin >> end >> w;
      --begin;
      --end;
      vec<vec<lli>> rm;
      vec<vec<lli>> add;
      auto itr = s.lower_bound({begin + 1, 0, 0});
      --itr;
      while (itr != s.end()) {
        if (itr->at(1) < begin) break;
        if (end < itr->at(0)) break;
        rm.push_back(*itr);

        if (itr->at(0) <= begin && end <= itr->at(1)) {
          if (itr->at(0) != begin) {
            add.push_back({itr->at(0), begin - 1, itr->at(2)});
          }
          if (itr->at(1) != end) {
            add.push_back({end + 1, itr->at(1), itr->at(2)});
          }
        }
        else if (begin <= itr->at(0) && itr->at(1) <= end) {
        } else {
          if (itr->at(0) < begin) {
            add.push_back({itr->at(0), begin - 1, itr->at(2)});
          }
          if (end < itr->at(1)) {
            add.push_back({end + 1, itr->at(1), itr->at(2)});
          }
        }
        ++itr;
      }
      add.push_back({begin, end, w});

      each (i, rm) {
        lli x = (bit(i[0], i[1] + 1) * i[2]) % mod;
        sum = (sum - x + mod) % mod;
        s.erase(i);
      }
      each (i, add) {
        lli x = (bit(i[0], i[1] + 1) * i[2]) % mod;
        sum = (sum + x) % mod;
        s.insert(i);
      }
      cout << sum << endl;
    }
  }

  return 0;
}
