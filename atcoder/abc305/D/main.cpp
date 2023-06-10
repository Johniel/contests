// github.com/Johniel/contests
// atcoder/abc305/D/main.cpp

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
  T operator () (size_t end) const {
    return (*this)(0, end);
  }
  int lower_bound(T x) const {
    return std::lower_bound(sum.begin(), sum.end(), x) - sum.begin();
  }
  int upper_bound(T x) const {
    return std::upper_bound(sum.begin(), sum.end(), x) - sum.begin();
  }
};

int main(int argc, char *argv[])
{
  int n;
  while (cin >> n) {
    vec<lli> a(n);
    cin >> a;

    vec<pair<lli, lli>> v;
    vec<lli> u;
    for (int i = 1; i + 1 < a.size(); i += 2) {
      v.push_back(make_pair(a[i], a[i + 1]));
      u.push_back(a[i + 1] - a[i]);
    }
    PrefixSum<lli> sum(u);
    // cout << v << endl;
    // cout << u << endl;

    int q;
    cin >> q;
    while (q--) {
      lli x, y;
      cin >> x >> y;

      auto itr1 = lower_bound(v.begin(), v.end(), make_pair(x + 1, 0LL));
      if (itr1 != v.begin()) {
        --itr1;
      }
      auto itr2 = lower_bound(v.begin(), v.end(), make_pair(y + 1, 0LL));
      if (itr2 != v.begin()) {
        --itr2;
      }

      int i = itr1 - v.begin();
      int j = itr2 - v.begin();

      // cout << make_pair(i, j) << endl;

      lli a = 0;
      if (x <= v[i].second) {
        a = max(0LL, x - v[i].first);
      } else {
        ++i;
      }
      lli b = 0;
      if (v[j].first <= y) {
        b = max(0LL, v[j].second - y);
      } else {
        --j;
      }
      lli c = sum(i, j + 1);

      // cout << make_pair(i, j) << ' ' << a << ' ' << b << ' ' << c << endl;

      cout << c - a - b << endl;
    }
  }
  return 0;
}
