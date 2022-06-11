// atcoder/abc255/D/main.cpp
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
    vec<lli> x(q);
    cin >> x;

    vec<pair<lli, pair<int, int>>> v;
    const int A = 0;
    const int X = 1;
    for (int i = 0; i < a.size(); ++i) {
      v.push_back({a[i], {A, i}});
    }
    for (int i = 0; i < x.size(); ++i) {
      v.push_back({x[i], {X, i}});
    }
    sort(v.begin(), v.end());

    lli z[q];
    fill(z, z + q, 0);

    for (int _ = 0; _ < 2; ++_) {
      lli cnt = 0;
      lli sum = 0;
      lli prev = -1;
      each (i, v) {
        const lli pos = i.first;
        const int type = i.second.first;
        const int idx = i.second.second;
        if (pos == -1) prev = pos;
        if (type == A) {
          sum += abs(pos - prev) * cnt;
          ++cnt;
        }
        if (type == X) {
          sum += abs(pos - prev) * cnt;
          z[idx] += sum;
        }
        prev = pos;
      }
      reverse(v.begin(), v.end());
    }

    for (int i = 0; i < q; ++i) {
      cout << z[i] << endl;
    }
  }

  return 0;
}
