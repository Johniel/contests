// github.com/Johniel/contests
// codeforces/878div3/E/main.cpp

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

  str s, t;
  int w, q;
  while (cin >> s >> t >> w >> q) {
    vec<vec<int>> v;
    for (int i = 0; i < q; ++i) {
      int op;
      cin >> op;
      if (op == 1) {
        int pos;
        cin >> pos;
        --pos;
        v.push_back(vec<int>({i, 1, pos, '@', '@'}));
        v.push_back(vec<int>({i+w, 1, pos, s[pos], t[pos]}));
      }
      if (op == 2) {
        int a, p1;
        int b, p2;
        cin >> a >> p1 >> b >> p2;
        --a;
        --p1;
        --b;
        --p2;
        v.push_back(vec<int>({i, 2, a, p1, b, p2}));
      }
      if (op == 3) {
        v.push_back(vec<int>({i, 3}));
      }
    }
    sort(v.begin(), v.end());
    int diff = 0;
    for (int i = 0; i < s.size(); ++i) {
      diff += (s[i] != t[i]);
    }
    each (cmd, v) {
      // cout << s << ' ' << t << ", " << diff << endl;
      if (cmd[1] == 1) {
        const int pos = cmd[2];
        diff -= (s[pos] != t[pos]);
        s[pos] = cmd[3];
        t[pos] = cmd[4];
        diff += (s[pos] != t[pos]);
      }
      if (cmd[1] == 2) {
        const int a  = cmd[2];
        const int p1 = cmd[3];
        const int b  = cmd[4];
        const int p2 = cmd[5];
        diff -= (s[p1] != t[p1]);
        diff -= (s[p2] != t[p2]);
        if (a == 0 && b == 0) swap(s[p1], s[p2]);
        if (a == 0 && b == 1) swap(s[p1], t[p2]);
        if (a == 1 && b == 0) swap(t[p1], s[p2]);
        if (a == 1 && b == 1) swap(t[p1], t[p2]);
        diff += (s[p1] != t[p1]);
        diff += (s[p2] != t[p2]);
      }
      if (cmd[1] == 3) {
        cout << (diff ? "NO" : "YES") << endl;
      }
    }
  }
  return 0;
}
