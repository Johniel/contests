// atcoder/abc157/E/main2.cpp
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

constexpr lli mod = 1e9 + 7;

template<typename T = long long int>
struct BIT {
  vector<T> v;
  int n;

  BIT(int n_ = 0) {
    n = n_;
    v.resize(n + 1, 0);
  }

  T sum(int i) const {
    T s = 0;
    while (i > 0) {
      s += v[i];
      i -= i & -i;
    }
    return s;

  }

  T sum(int begin, int end) const {
    return sum(end) - sum(begin);
  }

  void add(int i, T x) {
    ++i;
    while (i <= n) {
      v[i] += x;
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

    int sum = 0;
    for (int i = 0; i < v.size(); ++i) {
      if (sum != bit.sum(i)) return false;
      sum += v[i];
    }
    if (sum != bit.sum(v.size())) return false;

    for (int i = 0; i < v.size(); ++i) {
      int sum = 0;
      for (int j = i; j < v.size(); ++j) {
        if (sum != bit.sum(i, j)) return false;
        sum += v[j];
      }
      if (sum != bit.sum(i, v.size())) return false;
    }

    return true;
  }
};

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  assert(BIT<>::verify());

  int n, q;
  str s;
  while (cin >> n >> s >> q) {
    const int N = 500000 + 5;
    map<char, BIT<int>> bits;
    for (char c = 'a'; c <= 'z'; ++c) {
      bits[c] = BIT<int>(N);
    }

    for (int i = 0; i < s.size(); ++i) {
      bits[s[i]].add(i, 1);
    }

    while (q--) {
      int t;
      cin >> t;
      if (t == 1) {
        int i;
        char c;
        cin >> i >> c;
        --i;
        bits[s[i]].add(i, -1);
        bits[c].add(i, +1);
        s[i] = c;
      }
      if (t == 2) {
        int begin, end;
        cin >> begin >> end;
        --begin;
        int x = 0;
        for (char c = 'a'; c <= 'z'; ++c) {
          x += !!bits[c].sum(begin, end);
        }
        cout << x << endl;
      }
    }
  }

  return 0;
}
