// github.com/Johniel/contests
// codeforces/854div1div2/C/main.cpp

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
template<typename T> using heap = priority_queue<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;
// constexpr lli mod = 998244353;

map<char, int> m;
str rec(int turn)
{
  // cout << m << endl;
  if (m.empty()) return str("");
  if (m.size() == 1) {
    return str(m.begin()->second, m.begin()->first);
  }

  auto itr = m.begin();
  ++itr;
  char d = itr->first;
  char c = m.begin()->first;
  if (m[c] == 1 && 2 < m.size()) {
    str a;
    a += c;
    --m[c];
    str b;
    for (char c = 'a'; c <= 'z'; ++c) {
      b += str(m[c], c);
      m[c] = 0;
    }
    reverse(b.begin(), b.end());
    a += b;
    if (turn) reverse(a.begin(), a.end());
    return a;
  }

  if (m.size() == 2 && m[c] == 1 && 2 <= m[d]) {
    --m[d];
    --m[d];
    if (m[d] == 0) m.erase(d);
    return str("") + d + rec(turn^1) + d;
  } else if (2 < m.size() && m[c] == 1 && 2 <= m[d]) {
    --m[c];
    --m[d];
    --m[d];
    if (m[c] == 0) m.erase(c);
    if (m[d] == 0) m.erase(d);
    if (turn) return str("") + c + rec(turn^1) + d + d;
    else return str("") + d + d + rec(turn^1) + c;
  } else if (2 <= m[c]) {
    --m[c];
    --m[c];
    if (m[c] == 0) m.erase(c);
    return c + rec(turn) + c;
  } else if (m[c] == 1 && m[d] == 1) {
    str a;
    a += c;
    --m[c];
    str b;
    for (char c = 'a'; c <= 'z'; ++c) {
      b += str(m[c], c);
      m[c] = 0;
    }
    reverse(b.begin(), b.end());
    a += b;
    if (turn) reverse(a.begin(), a.end());
    return a;
  } else {
    --m[c];
    --m[d];
    if (m[c] == 0) m.erase(c);
    if (m[d] == 0) m.erase(d);
    if (turn) return str("") + c + rec(turn^1) + d;
    else return str("") + d + rec(turn^1) + c;
  }
}

str fn(str s)
{
  m.clear();
  each (c, s) ++m[c];
  str x = rec(0);
  str y = x;
  reverse(y.begin(), y.end());
  return max(x, y);
}

str fn2(str s)
{
  str mn(s.size() + 1, 'z');
  sort(s.begin(), s.end());
  do {
    str x = s;
    str y = x;
    reverse(y.begin(), y.end());
    setmin(mn, max(x, y));
  } while (next_permutation(s.begin(), s.end()));
  return mn;
}

uint32_t xorshift(void)
{
  // https://shindannin.hatenadiary.com/entry/2021/03/06/115415
  static uint32_t x = 123456789;
  static uint32_t y = 362436069;
  static uint32_t z = 521288629;
  static uint32_t w = 88675123;
  uint32_t t;

  t = x ^ (x << 11);
  x = y; y = z; z = w;
  return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
}

int main(int argc, char *argv[])
{
  if (0) while (true) {
    int n = xorshift() % 8 + 1;
    str s;
    for (int i = 0; i < n; ++i) {
      s += 'a' + xorshift() % 25;
    }
    str a = fn(s);
    str b = fn2(s);
    cout << a << endl;
    cout << b << endl;
    assert(a == b);
  }

  int _;
  cin >> _;

  str s;
  while (cin >> s) {
    cout << fn(s) << endl;
  }
  return 0;
}
