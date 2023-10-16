// github.com/Johniel/contests
// atcoder/abc324/E/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define each_with_index(i, e, c) for (const auto i: views::iota(0, (int)c.size())) if (auto& e = c.at(i); true)
#define each_pair(p, c) for (const auto _i: views::iota(0, (int)c.size())) if (std::pair<const int, decltype((c.at(_i)))> p = {_i, c[_i]}; true)
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
// constexpr lli mod = 1e9 + 7;
constexpr lli mod = 998244353;

int main(int argc, char *argv[])
{
  int n;
  str t;
  while (cin >> n >> t) {
    vec<str> v(n);
    cin >> v;

    vec<int> pref(n, -1);
    vec<int> suff(n, -1);

    for (int _ = 0; _ < 2; ++_) {
      each_with_index (i, s, v) {
        map<char, int> next[s.size() + 1];
        for (int i = (int)s.size() - 1; 0 <= i; --i) {
          next[i] = next[i + 1];
          next[i][s[i]] = i;
        }

        int j = 0;
        int k = 0;
        while (k < t.size()) {
          // cout << make_pair(k, t[k]) << ' ' << next[j] << endl;
          unless (next[j].count(t[k])) { break; }
          j = next[j][t[k]] + 1;
          ++k;
        }
        // cout << make_pair(j, k) << endl;
        if (_) pref[i] = k;
        else suff[i] = t.size() - k;
      }
      reverse(t.begin(), t.end());
      each (i, v) reverse(i.begin(), i.end());
      // cout << endl;
    }


    // cout << pref << endl; cout << suff << endl;

    vec<int> u;
    each (i, suff) u.push_back(i);
    sort(u.begin(), u.end());
    lli z = 0;
    each (i, pref) {
      z += lower_bound(u.begin(), u.end(), i + 1) - u.begin();
    }
    cout << z << endl;
    // break;
  }
  return 0;
}
