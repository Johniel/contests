// github.com/Johniel/contests
// atcoder/abc312/C/main.cpp

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
  int n, m;
  while (cin >> n >> m) {
    vec<lli> a(n), b(m);
    cin >> a >> b;

    vec<pair<lli, bool>> v;
    for (int i = 0; i < a.size(); ++i) v.push_back(make_pair(a[i], true));
    for (int i = 0; i < b.size(); ++i) v.push_back(make_pair(b[i], false));
    for (int i = 0; i < b.size(); ++i) v.push_back(make_pair(b[i] + 1, false));

    sort(v.begin(), v.end());
    sort(b.begin(), b.end());

    int sell = 0;
    for (int i = 0; i < v.size(); ++i) {
      sell += v[i].second;
      int buy = b.end() - lower_bound(b.begin(), b.end(), v[i].first);
      // cout << v[i] << ' ' << sell << ' ' << buy << endl;
      if (sell >= buy) {
        cout << v[i].first << endl;
        break;
      }
    }
  }
  return 0;
}
