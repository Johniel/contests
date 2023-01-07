// github.com/Johniel/contests
// atcoder/abc284/F/main.cpp

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
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[]{"; for (auto& i: a) os << i << ","; os << "}"; return os; }

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

#include <atcoder/string>
using namespace atcoder;

pair<int, str> fn(int _, str t)
{
  {
    str s;
    for (int i = 0; i < t.size() / 2; ++i) {
      s += t[i];
    }
    str sr = s;
    reverse(sr.begin(), sr.end());
    s += sr;
    if (t == s) {
      return make_pair(0, sr);
      // cout << sr << endl;
      // cout << 0 << endl;
    }
  }

  str tr = t;
  reverse(tr.begin(), tr.end());
  str a = t + tr;
  vec<int> va = z_algorithm(a);
  str b = tr + t;
  vec<int> vb = z_algorithm(b);
  // cout << a << endl;
  // cout << va << endl;
  // cout << b << endl;
  // cout << vb << endl;
  for (int i = 1; i < t.size()/2; ++i) {
    int j = (t.size() / 2) - i - 1;
    int x = t.size() + (t.size() / 2 - i);
    int y = t.size() + i;
    // cout << make_pair(i, j) << make_pair(x, y) << ", " << make_pair(va[x], vb[y]) << endl;
    if (i <= va[x] && j <= vb[y]) {
      str u;
      for (int k = 0; k < t.size() / 2; ++k) {
        u += t[k + i];
      }
      reverse(u.begin(), u.end());
      // cout << u << endl;
      // cout << i << endl;
      return make_pair(i, u);
    }
  }
  return make_pair(-1, "");
  // break;
}

// https://stackoverflow.com/questions/440133/how-do-i-create-a-random-alpha-numeric-string-in-c
std::string gen_random(const int len) {
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    std::string tmp_s;
    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i) {
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    return tmp_s;
}

int main(int argc, char *argv[])
{
  while (0) {
    str s = gen_random(10);
    for (int i = 0; i < s.size(); ++i) {
      str pref, suff;
      for (int j = 0; j < i; ++j) {
        pref += s[j];
      }
      for (int j = i; j < s.size(); ++j) {
        suff += s[j];
      }
      str sr = s;
      reverse(sr.begin(), sr.end());
      str t = pref + sr + suff;
      assert(t.size() == s.size() * 2);
      auto p = fn(t.size(), t);
      cout << make_pair(i, make_pair(pref, suff)) << p << ", " << t << ' ' << endl;
      assert(p.first != -1);
      str a, b;
      for (int j = 0; j < p.first; ++j) a += s[j];
      for (int j = p.first; j < s.size(); ++j) b += s[j];
      assert(a + sr + b == t);
    }
  }

  int n;
  str t;
  while (cin >> n >> t) {
    auto p = fn(n, t);
    if (p.first == -1) {
      cout << -1 << endl;
    } else {
      cout << p.second << endl;
      cout << p.first << endl;
    }
    // break;
  }
  return 0;
}
