// atcoder/arc125/A/main.cpp
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

  int n, m;
  while (cin >> n >> m) {
    vec<lli> a(n), b(m);
    cin >> a >> b;
    {
      set<lli> vis(a.begin(), a.end());
      bool f = true;
      each (i, b) f = f && vis.count(i);
      unless (f) {
        cout << -1 << endl;
        continue;
      }
    }

    int z = 1 << 29;
    {
      int x = 0;
      int i = 0;
      int j = 0;
      int turn = 0;
      for (; j < b.size(); ) {
        if (b[j] == a[i]) {
          ++x;
          ++j;
        } else {
          turn ^= 1;
          while (b[j] != a[i]) {
            ++x;
            if (turn) i = (i + 1) % a.size();
            else      i = (i - 1 + n) % a.size();
          }
        }
      }
      setmin(z, x);
    }
    {
      int x = 0;
      int i = 0;
      int j = 0;
      int turn = 0;
      for (; j < b.size(); ) {
        if (b[j] == a[i]) {
          ++x;
          ++j;
        } else {
          turn ^= 1;
          while (b[j] != a[i]) {
            ++x;
            unless (turn) i = (i + 1) % a.size();
            else          i = (i - 1 + n) % a.size();
          }
        }
      }
      setmin(z, x);
    }

    cout << z << endl;
  }

  return 0;
}
