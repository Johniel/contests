// atcoder/abc258/E/main.cpp
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
template<typename E, size_t N> istream& operator >> (istream& is, array<E, N>& a) { for (auto& i: a) is >> i; return is; }
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[]{"; for (auto& i: a) os << i << ","; os << "}"; return os; }

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

template<typename T>
struct PrefixSum {
  vector<T> sum;
  PrefixSum(vector<T> v) {
    sum.push_back(0);
    for (int i = 0; i < v.size(); ++i) {
      sum.push_back(sum.back() + v[i]);
    }
  }
  T operator () (size_t begin, size_t end) const {
    assert(begin <= end);
    return sum[end] - sum[begin];
  }
};

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n, q;
  lli x;
  while (cin >> n >> q >> x) {
    vec<lli> w(n);
    cin >> w;

    PrefixSum<lli> sum(w);
    auto fn = [&] (int i, lli x) {
      lli z = 0;
      {
        lli y = x / n;
        z += sum(0, n) * y;
      }
      {
        lli y = x % n;
        int mn = min<int>(i + y, n);
        z += sum(i, mn);
        z += sum(0, max<int>(0, y - (mn - i)));
      }
      return z;
    };

    vec<lli> a, b;
    for (int i = 0; i < w.size(); ++i) {
      lli small = 1;
      lli large = 1e9 + 2;
      while (small + 1 < large) {
        lli mid = (small + large) / 2;
        if (x < fn(i, mid)) large = mid;
        else small = mid;
      }
      lli z;
      if (x <= fn(i, small)) z = small;
      else z = large;
      a.push_back(z);
      b.push_back((i + z) % n);
    }

    vec<int> idx;
    set<int> vis;
    map<int, int> ord;
    int k = 0;
    for (int i = 0; ; ) {
      idx.push_back(i);
      vis.insert(i);
      int tmp = ord.size();
      ord[idx.back()] = tmp;
      k = b[i];
      if (vis.count(b[i])) break;
      i = b[i];
    }
    vec<int> cycle;
    for (int i = ord[k]; i < idx.size(); ++i) {
      cycle.push_back(idx[i]);
    }

    while (q--) {
      lli j;
      cin >> j;
      --j;
      if (j < ord[k]) {
        cout << a.at(idx[j]) << endl;
      } else {
        j -= ord[k];
        cout << a.at(cycle[j % cycle.size()]) << endl;
      }
    }
  }

  return 0;
}
