// codeforces/697div3/D/main.cpp
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

  int _;
  cin >> _;

  int n;
  lli m;
  while (cin >> n >> m) {
    vec<lli> a(n);
    vec<int> b(n);
    cin >> a >> b;

    vec<lli> v, u;
    for (int i = 0; i < n; ++i) {
      if (b[i] == 2) v.push_back(a[i]);
      else u.push_back(a[i]);
    }

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    sort(u.begin(), u.end());
    reverse(u.begin(), u.end());

    vec<lli> sum;
    sum.push_back(0);
    each (i, u) sum.push_back(sum.back() + i);
    const int inf = 1 << 29;
    auto fn = [&] (lli x) {
      int small = 0, large = u.size();
      while (small + 1 < large) {
        int mid = (small + large) / 2;
        if (m <= sum.at(mid) + x) large = mid;
        else small = mid;
      }
      if (m <= sum.at(small) + x) return small;
      else if (m <= sum.at(large) + x) return large;
      return inf;
    };

    int mn = fn(0);
    lli x = 0;
    for (int i = 0; i < v.size(); ++i) {
      x += v[i];
      setmin(mn, (i + 1) * 2 + fn(x));
    }
    cout << (mn == inf ? -1 : mn) << endl;
  }

  return 0;
}
