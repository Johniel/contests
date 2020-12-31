// codeforces/GoodBye2020/C/main.cpp
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

void fn(const str& S)
{
  const int N = S.size();
  int R[N];
  fill(R, R + N, 0);
  int c = 0;
  for (int i = 0; i < S.size(); ++i) {
    int l = c - (i-c);
    if (i+R[l] < c+R[c]) {
      R[i] = R[l];
    } else {
      int j = c+R[c] - i;
      while (i-j >= 0 && i+j < S.size() && S[i-j] == S[i+j]) ++j;
      R[i] = j;
      c = i;
    }
  }
  for (int i = 0; i < N; ++i) {
    cout << R[i] <<",";
  }
  cout << endl;
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
    vec<int> v;
    each (c, s) v.push_back(c - 'a');
    int x = 0;
    for (int i = 0; i < v.size(); ++i) {
      if (i + 1 < v.size() && v[i] == v[i + 1]) {
        v[i + 1] = --x;
      }
      if (i + 2 < v.size() && v[i] == v[i + 2]) {
        v[i + 2] = --x;
      }
    }
    int y = 0;
    each (i, v) y += (i < 0);
    cout << y << endl;
  }

  return 0;
}
