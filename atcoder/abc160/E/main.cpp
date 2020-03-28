// atcoder/abc160/E/main.cpp
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

struct PrefixSum {
  vector<long long int> sum;
  PrefixSum(vector<long long int> v) {
    sum.push_back(0);
    for (int i = 0; i < v.size(); ++i) {
      sum.push_back(sum.back() + v[i]);
    }
  }
  long long int operator () (size_t begin, size_t end) const {
    assert(begin <= end);
    return sum[end] - sum[begin];
  }
};

int main(int argc, char *argv[])
{
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.setf(std::ios_base::fixed);
  std::cout.precision(15);

  int x, y, a, b, c;
  while (cin >> x >> y >> a >> b >> c) {
    vec<lli> p(a);
    vec<lli> q(b);
    vec<lli> r(c);
    cin >> p >> q >> r;

    sort(p.begin(), p.end());
    sort(q.begin(), q.end());
    sort(r.begin(), r.end());

    auto fn = [&] (lli mn) {
      int cnt = 0;

      int A = p.end() - lower_bound(p.begin(), p.end(), mn);
      int B = q.end() - lower_bound(q.begin(), q.end(), mn);
      int C = r.end() - lower_bound(r.begin(), r.end(), mn);

      C -= max(0, x - A);
      C -= max(0, y - B);
      return 0 <= C;
    };

    lli small = 0;
    lli large = 1LL << 60;
    while (small + 1 < large) {
      lli mid = (small + large) / 2;
      if (fn(mid)) small = mid;
      else large = mid;
    }

    reverse(p.begin(), p.end());
    reverse(q.begin(), q.end());
    reverse(r.begin(), r.end());

    int k = x + y;
    priority_queue<int> z;
    each (i, p) {
      if (small <= i && x) {
        --x;
        z.push(i);
        // cout << "p: " << i << endl;
      }
    }
    each (i, q) {
      if (small <= i && y) {
        z.push(i);
        --y;
        // cout << "q: " << i << endl;
      }
    }
    each (i, r) {
      if (small <= i) {
        z.push(i);
        // cout << "r: " << i << endl;
      }
    }

    lli sum = 0;
    while (z.size() && k--) {
      // cout << "+" << z.top() << endl;
      sum += z.top();
      z.pop();
    }
    cout << sum << endl;
  }

  return 0;
}
