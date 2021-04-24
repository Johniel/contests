// codeforces/710div3/G/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

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

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int _;
  cin >> _;


  str s;
  while (cin >> s) {
    const int N = 2 * 1e5 + 3;
    static map<char, int> next[N];
    for (int i = 0; i < s.size() + 1; ++i) {
      for (char c = 'a'; c <= 'z'; ++c) {
        next[i][c] = -1;
      }
    }
    for (int i = s.size() - 1; 0 <= i; --i) {
      next[i] = next[i + 1];
      next[i][s[i]] = i;
    }

    set<char> rem;
    set<char> vis;
    each (c, s) rem.insert(c);

    str t;
    int idx = 0;
    while (true) {
      bool f = false;
      for (char c = 'z'; 'a' <= c; --c) {
        if (vis.count(c)) continue;
        if (next[idx][c] != -1) {
          bool ok = true;
          each (d, rem) {
            if (next[next[idx][c]][d] == -1) {
              ok = false;
              break;
            }
          }
          if (ok) {
            vis.insert(c);
            rem.erase(c);
            t += c;
            idx = next[idx][c];
            f = true;
            break;
          }
        }
      }
      unless (f) break;
    }
    cout << t << endl;
  }

  return 0;
}
