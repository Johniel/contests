// atcoder/abc244/D/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

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

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

using lli = long long int;
using ull = unsigned long long;
using point = complex<double>;
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;
// constexpr lli mod = 998244353;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  char s1, s2, s3;
  char t1, t2, t3;
  while (cin >> s1 >> s2 >> s3 >> t1 >> t2 >> t3) {
    str s = str("") + s1 + s2 + s3;
    str t = str("") + t1 + t2 + t3;
    const int N = 30;
    set<str> vis[N];
    vis[0].insert(s);
    for (int i = 0; i + 1 < N; ++i) {
      each (curr, vis[i]) {
        for (int j = 0; j < curr.size(); ++j) {
          for (int k = j + 1; k < curr.size(); ++k) {
            str tmp = curr;
            swap(tmp[j], tmp[k]);
            vis[i + 1].insert(tmp);
          }
        }
      }
    }
    bool f = false;
    for (int i = 0; i < N; ++i) {
      each (u, vis[i]) {
        if (u == t && i % 2 == 0) f = true;
      }
    }
    cout << (f ? "Yes" : "No") << endl;
  }

  return 0;
}
