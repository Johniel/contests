// github.com/Johniel/contests
// atcoder/arc156/A/main.cpp

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

int fn(str s)
{
  queue<str> q;
  map<str, int> m;
  for (q.push(s); q.size(); q.pop()) {
    str t = q.front();
    for (int i = 0; i < t.size(); ++i) {
      for (int j = i+2; j < t.size(); ++j) {
        str u = t;
        u[i] = (u[i] - '0') ^ 1 + '0';
        u[j] = (u[j] - '0') ^ 1 + '0';
        unless (m.count(u)) {
          m[u] = m[t] + 1;
          q.push(u);
        }
      }
    }
  }
  str t = str(s.size(), '0');
  if (m.count(t)) return m[t];
  else return -1;
}

int main(int argc, char *argv[])
{
  int _;
  cin >> _;

  int n;
  str s;
  while (cin >> n >> s) {

    if (n < 7) {
      cout << fn(s) << endl;
      continue;
    }

    int _1 = count(s.begin(), s.end(), '1');
    int _0 = count(s.begin(), s.end(), '0');
    if (_1 % 2) cout << -1 << endl;
    else {
      if (_1 == 2) {
        vec<int> v;
        for (int i = 0; i < s.size(); ++i) {
          if (s[i] == '1') v.push_back(i);
        }
        if (v[0] + 1 == v[1]) cout << 2 << endl;
        else cout << _1 / 2 << endl;
      }
      else cout << _1 / 2 << endl;
    }
  }
  return 0;
}
