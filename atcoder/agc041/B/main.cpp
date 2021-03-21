// atcoder/agc041/B/main.cpp
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

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  lli n, m, v, p;
  while (cin >> n >> m >> v >> p) {
    --p;
    vec<lli> a(n);
    cin >> a;
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());

    auto fn = [&] (int nth) {
      vec<lli> b = a;
      int voted = 0;
      for (int i = nth; i < b.size() && voted < v; ++i) {
        ++voted;
        b[i] += m;
      }
      for (int i = 0; i < p && voted < v; ++i) {
        ++voted;
        b[i] += m;
      }
      lli x = 0;
      for (int i = p; i < nth; ++i) {
        if (b[nth] < b[i]) return false;
        x += b[nth] - b[i];
      }
      unless (b[p] <= b[nth]) return false;
      return  m * (v - voted) <= x;
    };

    int small = p;
    int large = a.size();
    while (small + 1 < large) {
      int mid = (small + large) / 2;
      if (fn(mid)) small = mid;
      else large = mid;
    }
    cout << small+1 << endl;
  }

  return 0;
}
