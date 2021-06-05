// codeforces/e110/C/main.cpp
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

void show(queue<char> q)
{
  str s;
  while (q.size()) {
    s += q.front();
    q.pop();
  }
  cout << s << endl;
  return ;
}

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
    vec<str> v;
    queue<char> q;
    lli x = 0;
    map<char, int> m;
    map<char, queue<int>> prev;
    auto fn = [&] (const char c, const int idx) {
      const char d = ((s[idx] - '0') ^ 1) + '0';
      if (prev[c].size() && prev[c].front() % 2 != idx % 2) {
        return false;
      }
      if (prev[d].size() && prev[d].front() % 2 == idx % 2) {
        return false;
      }
      return true;
    };
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] != '?' && !fn(s[i], i)) {
        while (q.size() && !fn(s[i], i)) {
          // show(q);
          x += q.size();
          const char d = q.front();
          q.pop();
          --m[d];
          prev[d].pop();
        }
      }
      prev[s[i]].push(i);
      ++m[s[i]];
      q.push(s[i]);
    }
    while (q.size()) {
      // show(q);
      x += q.size();
      q.pop();
    }
    cout << x << endl;
    // cout << endl;
  }

  return 0;
}
