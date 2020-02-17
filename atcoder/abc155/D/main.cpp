// atcoder/abc155/D/main.cpp
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
template<typename P, typename Q> inline pair<Q, P> reverse(pair<P, Q> p) { return make_pair(p.second, p.first); }

using lli = long long int;
using ull = unsigned long long;
using point = complex<double>;
using str = string;
template<typename T> using vec = vector<T>;

constexpr lli mod = 1e9 + 7;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  lli k;
  while (cin >> n >> k) {
    vector<lli> a(n);
    cin >> a;
    sort(a.begin(), a.end());

    const lli z = count(a.begin(), a.end(), 0);
    vector<lli> p, m;
    each (i, a) {
      if (i < 0) m.push_back(i);
      if (0 < i) p.push_back(i);
    }

    auto fn = [&] (lli x) {
      lli sum = 0;
      const lli ms = m.size();
      const lli ps = p.size();

      if (0 <= x) {
        sum += (ms * ps);
        sum += z * ps;
        sum += z * ms;
        sum += (z - 1) * z / 2;
      }

      if (x < 0) {
        each (i, p) {
          lli y = x / i;
          if (x % i == 0) ++y;
          auto itr = lower_bound(m.begin(), m.end(), y);
          sum += (itr - m.begin());
        }
      }

      if (0 < x) {
        for (int i = 0; i + 1 < p.size(); ++i) {
          lli y = x / p[i];
          auto itr = upper_bound(p.begin() + i + 1, p.end(), y);
          sum += itr - (p.begin() + i + 1);
        }
        for (int i = 0; i + 1 < m.size(); ++i) {
          lli y = x / m[i];
          auto itr = lower_bound(m.begin() + i + 1, m.end(), y);
          sum += m.end() - itr;
        }
      }

      return sum;
    };

    const lli inf = 1e18 + 2;

    lli small = -inf;
    lli large = +inf;
    while (small + 1 < large) {
      lli mid = (small + large) / 2;
      if (fn(mid) < k) small = mid;
      else large = mid;
    }

    cout << large << endl;
  }

  return 0;
}
