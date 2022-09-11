// github.com/Johniel/contests
// abc268/D/main.cpp

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
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;
// constexpr lli mod = 998244353;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n, m;
  while (cin >> n >> m) {
    vec<str> a(n), b(m);
    cin >> a >> b;
    sort(b.begin(), b.end());
    sort(a.begin(), a.end());

    int z = 0;
    each (i, a) z += i.size();
    // z += n - 1;
    z = 16 - z;
    // cout << "z: " << z << endl;

    str x = "-1";
    do {
      vec<str> v;
      for (int idx = 0; idx < a.size(); ++idx) {
        const str& i = a[idx];
        if (idx == 0) {
          v.push_back(i);
        } else {
          vec<str> u;
          each (j, v) {
            for (int k = 1; j.size() + k + i.size() + (n - idx - 1) <= 16 && k <= z; ++k) {
              u.push_back(j + str(k, '_') + i);
            }
          }
          v = u;
        }
      }

      each (i, v) {
        unless (3 <= i.size() && i.size() <= 16) continue;
        if (binary_search(b.begin(), b.end(), i)) continue;
        x = i;
      }
      if (x != "-1") break;
    } while (next_permutation(a.begin(), a.end()));
    cout << x << endl;
  }

  return 0;
}
