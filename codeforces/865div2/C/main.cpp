// github.com/Johniel/contests
// codeforces/865div2/C/main.cpp

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

int main(int argc, char *argv[])
{
  int _;
  cin >> _;

  int n;
  while (cin >> n) {
    vec<lli> a(n);
    cin >> a;
    vec<lli> v;
    for (int i = 0; i + 1 < a.size(); ++i) {
      v.push_back(a[i + 1] - a[i]);
    }
    // cout << v << endl;
    for (int i = 0; i + 1 < v.size(); ++i) {
      if (v[i] <= 0) {
        // v[i + 1] += abs(v[i]);
        if (i + 2 < v.size()) {
          v[i + 2] -= abs(v[i]);
        }
        v[i] = 0;
      }
    }
    // cout << v << endl;
    for (int i = v.size() - 1; 0 < i; --i) {
      if (v[i] <= 0) {
        // v[i - 1] -= abs(v[i]);
        if (0 <= i - 2) {
          v[i - 2] -= abs(v[i]);
        }
        v[i] = 0;
      }
    }
    // cout << v << endl;
    lli mn = *min_element(v.begin(), v.end());
    cout << (0 <= mn ? "YES" : "NO") << endl;
  }
  return 0;
}
