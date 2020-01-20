// atcoder/abc027/C/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; each (i, v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { each (i, v) is >> i; return is; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

constexpr lli mod = 1e9 + 7;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  lli n;
  while (cin >> n) {
    vector<int> v;
    for (int i = 0; i < 60; ++i) {
      v.push_back(bool(n & (1LL << i)));
    }

    while (v.back() == 0) v.pop_back();
    reverse(v.begin(), v.end());

    // cout << v << endl;

    const string A = "Aoki";
    const string T = "Takahashi" ;

    string s = v.size() % 2 ? A : T;
    string t[2] = {A, T};
    // cout << s << endl;

    for (int i = 1; i < v.size(); ++i) {
      if (v[i] == 0 && s != t[i % 2]) {
        s = t[i % 2];
        break;
      }
      if (v[i] == 1 && s == t[i % 2]) {
        break;
      }
    }
    cout << s << endl;
    // cout << endl;
  }

  return 0;
}
