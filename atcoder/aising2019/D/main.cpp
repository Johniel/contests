// atcoder/aising2019/D/main.cpp
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
  while (cin >> n >> q) {
    vec<lli> a(n);
    cin >> a;
    vec<int> v(q);
    cin >> v;
    sort(a.begin(), a.end());

    vec<lli> _x;
    vec<lli> _y;
    for (int i = 0; i < a.size(); ++i) {
      if (i%2) {
        _x.push_back(0);
        _y.push_back(a[i]);
      } else {
        _x.push_back(a[i]);
        _y.push_back(0);
      }
    }

    auto fn = [&] (const int k, const int x) {
      const int i = a.size() - k - 1;
      const int d = abs(x - a[k]);
      int p = lower_bound(a.begin(), a.end(), x - d) - a.begin();
      if (p == n) p = 0;
      int q = lower_bound(a.begin(), a.end(), x + d + 1) - a.begin();
      --q;
      int j = abs(q - p);
      if (abs(a[p] - x) == abs(a[q] - x) && p != q && a[k] < x) --j;
      return make_pair(j, i);
    };
    PrefixSum<lli> x(_x), y(_y), z(a);
    each (p, v) {
      int small = 0;
      int large = a.size();
      while (small + 1 < large) {
        int mid = (small + large) / 2;
        auto q = fn(mid, p);
        if (q.first <= q.second) small = mid;
        else large = mid;
      }
      auto q = fn(small, p);
      if (q.first >= q.second) {
        int k = n - min(n, q.second + q.second);
        cout << z(small, n) + (k % 2 ? x(0, k - 1) : y(0, k - 1)) << endl;
      } else {
        int k = n - min(n, q.second + q.second);
        cout << z(small+1, n) + (k % 2 ? x(0, k) : y(0, k)) << endl;
      }
    }
  }

  return 0;
}
