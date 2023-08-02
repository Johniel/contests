// github.com/Johniel/contests
// atcoder/arc130/B/main.cpp

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
  int h, w, c, q;
  while (cin >> h >> w >> c >> q) {
    const int N = 3 * 1e5 + 3;
    static int t[N];
    static int idx[N];
    static int color[N];

    map<int, int> hcolor, wcolor;
    map<int, int> updatedAtH;
    map<int, int> updatedAtW;
    for (int i = 0; i < q; ++i) {
      cin >> t[i] >> idx[i] >> color[i];
      --idx[i];
      --color[i];
      if (t[i] == 1) {
        wcolor[idx[i]] = color[i];
        updatedAtW[idx[i]] = i;
      }
      if (t[i] == 2) {
        hcolor[idx[i]] = color[i];
        updatedAtH[idx[i]] = i;
      }
    }

    vec<int> hord, word;
    each (i, updatedAtH) hord.push_back(i.second);
    each (i, updatedAtW) word.push_back(i.second);
    sort(hord.begin(), hord.end());
    sort(word.begin(), word.end());

    vec<lli> sum(c, 0);

    for (int ord = 0; ord < q; ++ord) {
      if (t[ord] != 1) continue;
      const int c = color[ord];
      if (updatedAtW[idx[ord]] != ord) continue;
      lli z = w;
      z -= hord.end() - lower_bound(hord.begin(), hord.end(), ord);
      sum[c] += z;
    }

    for (int ord = 0; ord < q; ++ord) {
      if (t[ord] != 2) continue;
      const int c = color[ord];
      if (updatedAtH[idx[ord]] != ord) continue;
      lli z = h;
      z -= word.end() - lower_bound(word.begin(), word.end(), ord);
      sum[c] += z;
    }

    each (i, sum) cout << i << ' '; cout << endl;
    // break;
  }
  return 0;
}
