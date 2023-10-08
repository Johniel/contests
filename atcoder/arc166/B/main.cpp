// github.com/Johniel/contests
// atcoder/arc166/B/main.cpp

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

using int128 = __int128;

std::ostream &operator<<(std::ostream &dest, __int128_t value) {
  std::ostream::sentry s(dest);
  if (s) {
    __uint128_t tmp = value < 0 ? -value : value;
    char buffer[128];
    char *d = std::end(buffer);
    do {
      --d;
      *d = "0123456789"[tmp % 10];
      tmp /= 10;
    } while (tmp != 0);
    if (value < 0) {
      --d;
      *d = '-';
    }
    int len = std::end(buffer) - d;
    if (dest.rdbuf()->sputn(d, len) != len) {
      dest.setstate(std::ios_base::badbit);
    }
  }
  return dest;
}

__int128 parse(string &s) {
  __int128 ret = 0;
  for (int i = 0; i < s.length(); i++)
    if ('0' <= s[i] && s[i] <= '9')
      ret = 10 * ret + s[i] - '0';
  return ret;
}

int128 gcd(int128 a, int128 b)
{
  if (a < b) swap(a, b);
  return b ? gcd(b, a % b) : a;
}

int128 lcm(int128 a, int128 b)
{
  return a * b / gcd(a, b);
}
int128 fn(int128 x, int128 y)
{
  if (x % y == 0) return 0;
  return (x / y + 1) * y - x;
}

int main(int argc, char *argv[])
{
  int n;
  int _a, _b, _c;
  while (cin >> n >> _a >> _b >> _c) {
    int128 a = _a;
    int128 b = _b;
    int128 c = _c;
    vec<lli> v_(n);
    cin >> v_;

    vec<int128> v;
    each (i, v_) v.push_back(i);

    int128 triple = int128(1LL << 61) * int128(1LL << 61);
    int128 lcm_abc = lcm(lcm(a, b), c);
    each (i, v) setmin(triple, fn(i, lcm_abc));
    int128 mn = triple;

    vec<pair<int128, int>> a1;
    vec<pair<int128, int>> b1;
    vec<pair<int128, int>> c1;
    {
      for (int i = 0; i < v.size(); ++i) {
        a1.push_back(make_pair(fn(v[i], a), i));
        b1.push_back(make_pair(fn(v[i], b), i));
        c1.push_back(make_pair(fn(v[i], c), i));
      }
      sort(a1.begin(), a1.end());
      sort(b1.begin(), b1.end());
      sort(c1.begin(), c1.end());
      while (4 < a1.size()) a1.pop_back();
      while (4 < b1.size()) b1.pop_back();
      while (4 < c1.size()) c1.pop_back();

      for (int i = 0; i < a1.size(); ++i) {
        for (int j = 0; j < b1.size(); ++j) {
          for (int k = 0; k < c1.size(); ++k) {
            set<int> vis;
            vis.insert(a1[i].second);
            vis.insert(b1[j].second);
            vis.insert(c1[k].second);
            if (vis.size() == 3) setmin(mn, a1[i].first + b1[j].first + c1[k].first);
          }
        }
      }
    }
    {
      vec<pair<int128, int>> ab;
      vec<pair<int128, int>> bc;
      vec<pair<int128, int>> ac;

      int128 lcm_ab = lcm(a, b);
      int128 lcm_ac = lcm(a, c);
      int128 lcm_bc = lcm(c, b);

      for (int i = 0; i < v.size(); ++i) {
        ab.push_back(make_pair(fn(v[i], lcm_ab), i));
        ac.push_back(make_pair(fn(v[i], lcm_ac), i));
        bc.push_back(make_pair(fn(v[i], lcm_bc), i));
      }
      sort(ab.begin(), ab.end());
      sort(ac.begin(), ac.end());
      sort(bc.begin(), bc.end());
      while (4 < ab.size()) ab.pop_back();
      while (4 < ac.size()) ac.pop_back();
      while (4 < bc.size()) bc.pop_back();

      for (int i = 0; i < ab.size(); ++i) {
        for (int j = 0; j < c1.size(); ++j) {
          if (ab[i].second != c1[j].second) setmin(mn, ab[i].first + c1[j].first);
        }
      }
      for (int i = 0; i < ac.size(); ++i) {
        for (int j = 0; j < b1.size(); ++j) {
          if (ac[i].second != b1[j].second) setmin(mn, ac[i].first + b1[j].first);
        }
      }
      for (int i = 0; i < bc.size(); ++i) {
        for (int j = 0; j < a1.size(); ++j) {
          if (bc[i].second != a1[j].second) setmin(mn, bc[i].first + a1[j].first);
        }
      }
    }

    cout << mn << endl;
  }
  return 0;
}
