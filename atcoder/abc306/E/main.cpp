// github.com/Johniel/contests
// atcoder/abc306/E/main.cpp

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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template<typename T>
class ordered_set : public tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> {};
// find_by_order(k),order_of_key(k)

int main(int argc, char *argv[])
{
  int n, k, q;
  while (cin >> n >> k >> q) {
    vec<lli> a(n, 0);
    ordered_set<pair<lli, int>> s;
    for (int i = 0; i < a.size(); ++i) {
      s.insert(make_pair(a[i], i));
    }
    lli z = 0;
    while (q--) {
      int i;
      lli x;
      cin >> i >> x;
      --i;

      // for (int i = 0; i < a.size(); ++i) cout << *(s.find_by_order(i)); cout << endl;

      const pair<lli, int> prev = make_pair(-a[i], i);
      // cout << "ord:" << prev << ' ' << s.order_of_key(prev) << endl;
      if (s.order_of_key(prev) < k) {
        z -= a[i];
        // cout << "rm" << a[i] << ", " << z << endl;
        s.erase(prev);
        z += abs(s.find_by_order(k - 1)->first);
      } else {
        s.erase(prev);
      }
      a[i] = x;
      const pair<lli, int> curr = make_pair(-a[i], i);
      s.insert(curr);
      if (s.order_of_key(curr) < k) {
        s.erase(curr);
        z -= abs(s.find_by_order(k - 1)->first);
        s.insert(curr);
        z += a[i];
      }
      cout << abs(z) << endl;
    }
  }
  return 0;
}
