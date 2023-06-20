// github.com/Johniel/contests
// codeforces/881div3/F/main.cpp

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

const int N = 2 * 1e5 + 3;
int parent[N];
lli w[N];

lli mxc[N];
lli mxf[N];

lli mnc[N];
lli mnf[N];

int main(int argc, char *argv[])
{
  int _;
  while (cin >> _) {
    while (_--) {
      int q;
      cin >> q;
      fill(parent, parent + q, -1);
      fill(w, w + q, -1);
      w[0] = 1;

      mxc[0] = 1;
      mxf[0] = 1;

      mnc[0] = 0;
      mnf[0] = 0;

      parent[0] = 1;
      int cnt = 1;
      while (q--) {
        char op;
        cin >> op;
        if (op == '?') {
          int a, b, k;
          cin >> a >> b >> k;
          --a;
          --b;
          // cout << make_pair(a+1,b+1) << make_pair(mxc[b], mxf[b]) << make_pair(mnc[b], mnf[b]) << endl;
          if (k == 0) cout << "YES" << endl;
          if (0 < k) cout << (k <= max(mxc[b], mxf[b]) ? "YES" : "NO") << endl;
          if (k < 0) cout << (min(mnc[b], mnf[b]) <= k ? "YES" : "NO") << endl;
        }
        if (op == '+') {
          int x;
          lli weight;
          cin >> x >> weight;
          --x;
          int y = cnt++;
          w[y] = w[x] + weight;

          mxf[y] = max({mxf[x], mxc[x], mxc[x] + weight});
          mxc[y] = max(mxc[x] + weight, weight);

          mnf[y] = min({mnf[x], mnc[x], mnc[x] + weight});
          mnc[y] = min(mnc[x] + weight, weight);

          parent[y] = x;
        }
      }
    }
// cout << endl;
  }
  return 0;
}
