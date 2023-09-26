// github.com/Johniel/contests
// codeforces/900div2/D/main.cpp

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
  int _;
  cin >> _;

  str s;
  int n, k;
  while (cin >> n >> k >> s) {
    vec<int> begin(k), end(k);
    int q;
    cin >> begin >> end >> q;
    vec<int> qs(q);
    cin >> qs;
    each (i, begin) --i;
    each (i, qs) --i;

    vec<pair<int, int>> v;
    for (int i = 0; i < k; ++i) {
      v.push_back(make_pair(begin[i], end[i]));
    }
    sort(v.begin(), v.end());

    vec<int> u[k];
    vec<pair<int, int>> idx;
    for (int i = 0; i < k; ++i) {
      idx.push_back(make_pair(begin[i], i));
    }
    sort(idx.begin(), idx.end());
    each (x, qs) {
      auto itr = lower_bound(idx.begin(), idx.end(), make_pair(x, (1 << 29)));
      if (itr == idx.begin()) continue;
      --itr;
      u[itr->second].push_back(x);
    }

    for (int i = 0; i < k; ++i) {
      vec<int> acc(end[i] - begin[i] + 1, 0);
      vec<pair<int, int>> w;
      each (x, u[i]) {
        int a = min(x, begin[i] + (end[i] - 1) - x);
        int b = max(x, begin[i] + (end[i] - 1) - x);
        if (a != b) w.push_back(make_pair(a, b));
      }
      if (w.empty()) continue;
      each (j, w) {
        acc.at(j.first - begin[i]) ^= 1;
      }
      for (int i = 0; i + 1 < acc.size(); ++i) {
        acc[i + 1] ^= acc[i];
      }
      // cout << make_pair(begin[i], end[i]) << ' ' << acc << endl;
      for (int j = begin[i]; j < begin[i] + (end[i] - begin[i]) / 2; ++j) {
        int r = end[i] - (j - begin[i]) - 1;
        if (acc.at(j - begin[i])) {
          swap(s[j], s[r]);
        }
      }
    }

    cout << s << endl;
    // cout << endl;
    // break;
  }

  return 0;
}
