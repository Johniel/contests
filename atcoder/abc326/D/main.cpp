// github.com/Johniel/contests
// atcoder/abc326/D/main.cpp

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
  str h, w;
  while (cin >> n >> h >> w) {
    const int H = 5 + 1;
    const int W = 5 + 1;

    const int A = 1;
    const int B = 2;
    const int C = 4;
    const int S = (1 << 15);

    static bool dp[H][S];
    fill(&dp[0][0], &dp[H - 1][S - 1] + 1, false);
    dp[0][0] = true;
    static pair<int, str> path[H][S];

    for (int i = 0; i < n; ++i) {
      for (int bit = 0; bit < S; ++bit) {
        unless (dp[i][bit]) continue;
        str s("ABC");
        while (s.size() < n) s += '.';
        sort(s.begin(), s.end());
        vec<int> v;
        int b = bit;
        for (int k = 0; k < n; ++k) {
          v.push_back(b % 8);
          b /= 8;
        }
        assert(v.size() == s.size());
        do {
          bool f = true;
          int nb = bit;
          char first = '.';
          for (int j = 0; j < s.size(); ++j) {
            if (s[j] != '.' && first == '.') first = s[j];
            if (s[j] == 'A' && (v[j] & A)) f = false;
            if (s[j] == 'B' && (v[j] & B)) f = false;
            if (s[j] == 'C' && (v[j] & C)) f = false;
            if (s[j] == 'A') nb += (1 << (j * 3)) * A;
            if (s[j] == 'B') nb += (1 << (j * 3)) * B;
            if (s[j] == 'C') nb += (1 << (j * 3)) * C;
            if (v[j] == 0 && s[j] != '.') f = f && (w[j] == s[j]);
          }
          f = f && (first == h[i]);
          if (f) {
            dp[i + 1][nb] = true;
            path[i + 1][nb] = make_pair(bit, s);
          }
        } while (next_permutation(s.begin(), s.end()));
      }
    }
    vec<str> v;
    for (int bit = 0; bit < S; ++bit) {
      if (dp[n][bit]) {
        int b = bit;
        int i = n;
        while (i) {
          v.push_back(path[i][b].second);
          b = path[i][b].first;
          --i;
        }
        reverse(v.begin(), v.end());
        break;
      }
    }

    if (v.empty()) cout << "No" << endl;
    else {
      cout << "Yes" << endl;
      each (i, v) cout << i << endl;
    }
  }
  return 0;
}
