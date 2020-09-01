// atcoder/arc053/B/main.cpp
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

  str s;
  while (cin >> s) {
    map<char, int> m;
    each (c, s) ++m[c];
    map<char, int> x;
    each (i, m) {
      if (i.second % 2) {
        ++x[i.first] = i.second / 2;
        ++x[i.first + min('a', 'A') - max('a', 'A')] = (i.second + 1) / 2;
      } else {
        x[i.first] = i.second;
      }
    }

    priority_queue<int> q;
    each (i, x) {
      if (i.second % 2) {
        q.push(-1);
        --i.second;
      }
    }

    if (q.empty()) {
      cout << s.size() << endl;
      continue;
    }

    each (i, x) {
      while (i.second) {
        i.second -= 2;
        int z = abs(q.top());
        q.pop();
        z += 2;
        q.push(-z);
      }
    }

    int mn = 1 << 29;
    while (q.size()) {
      setmin(mn, abs(q.top()));
      q.pop();
    }
    cout << mn << endl;
  }

  return 0;
}
