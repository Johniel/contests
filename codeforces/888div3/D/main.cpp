// github.com/Johniel/contests
// codeforces/888div3/D/main.cpp

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
    vec<lli> b(n - 1);
    cin >> b;
    vec<int> a;
    a.push_back(b[0]);
    for (int i = 0; i + 1 < b.size(); ++i) {
      a.push_back(b[i + 1] - b[i]);
    }
    map<lli, int> r;
    for (int i = 1; i <= n; ++i) ++r[i];
    map<lli, int> m;
    each (i, a) {
      ++m[i];
      --r[i];
      if (r[i] == 0) r.erase(i);
    }

    // cout << b << endl;

    bool f = false;
    {
      bool g = (m.size() == n - 1);
      each (i, a) g = g && (1 <= i && i <= n) && (m[i] == 1);
      if (g) {
        f = true;
        // cout << a << endl;
      }
    }

    for (int i = 0; i < a.size(); ++i) {
      --m[a[i]];
      if (m[a[i]] == 0) m.erase(a[i]);
      ++r[a[i]];
      if (r[a[i]] == 0) r.erase(a[i]);

      if (r.size() == 2) {
        lli x = r.begin()->first;
        lli y = r.rbegin()->first;

        lli prev = (i ? b[i - 1] : 0);

        // if (vec<lli>({1, 3, 6}) == b) {
        //   cout << a << endl;
        //   cout << m << endl;
        //   cout << r << endl;
        //   cout << make_pair(x, y) << ' ' << prev << "+" << x << "+" << y << "==" << b[i] << endl;
        // }

        if (1 <= x && x <= n &&
            1 <= y && y <= n &&
            x != y &&
            prev + x + y == b[i] &&
            m.count(x) == 0 && m.count(y) == 0 &&
            m.size() + r.size() == n &&
            (m.empty() || m.rbegin()->first <= n)) {
          f = true;
        }
      }

      --r[a[i]];
      if (r[a[i]] == 0) r.erase(a[i]);
      ++m[a[i]];
    }
    cout << (f ? "YES" : "NO") << endl;
  }
  return 0;
}
