// github.com/Johniel/contests
// codeforces/867div3/D/main.cpp

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
  if (0) {
    for (int n = 1; n <= 8; ++n) {
      vec<int> a(n);
      iota(a.begin(), a.end(), 1);
      sort(a.begin(), a.end());
      do {
        vec<int> b;
        int x = 0;
        each (i, a) {
          b.push_back((x += i) % n + 1);
        }
        if (a.size() == set<int>(b.begin(), b.end()).size()) {
          cout << n << ' ' << a << ' ' << b << endl;
        }
      } while (next_permutation(a.begin(), a.end()));
    }
    // return 0;
  }


  int _;
  cin >> _;

  lli n;
  while (cin >> n) {
    if (n == 1) {
      cout << 1 << endl;
      continue;
    }
    if (n % 2) {
      cout << -1 << endl;
      continue;
    }
    vec<int> v(n, -1);
    int x = n;
    int y = 1;
    int t = 1;
    int i = 0;
    int j = v.size() - 1;
    while (i < j) {
      if (t % 2) {
        v[i++] = x;
        --x;
        v[j--] = x;
        --x;
      } else {
        v[i++] = y;
        ++y;
        v[j--] = y;
        ++y;
      }
      ++t;
    }
    each (i, v) cout << i << ' '; cout << endl;
  }
  return 0;
}

// 10 (10,9,2,7,4,5,6,3,8,1,) (1,10,2,9,3,8,4,7,5,6,)
// 8 (8,7,2,5,4,3,6,1,) (1,8,2,7,3,6,4,5,)
// 6 (6,5,2,3,4,1,) (1,6,2,5,3,4,)
