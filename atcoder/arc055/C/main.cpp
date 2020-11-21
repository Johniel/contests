// atcoder/arc055/C/main.cpp
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

vec<int> z_algorithm(str S)
{
  vector<int> Z(S.size());
  Z[0] = S.size();
  int i = 1, j = 0;
  while(i < S.size()){
    while(i + j < S.size() && S[j] == S[i + j]) j++;
    Z[i] = j;

    if(j == 0){
      i++;
      continue;
    }
    int k = 1;
    while(k < j && k + Z[k] < j){
      Z[i + k] = Z[k];
      k++;
    }
    i += k;
    j -= k;
  }
  return Z;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  str s;
  while (cin >> s) {
    const int n = s.size();
    str t = s;
    reverse(t.begin(), t.end());

    const vec<int> a = z_algorithm(s);
    const vec<int> c = z_algorithm(t);

    lli x = 0;
    for (int i = 1; i + 1 < s.size(); ++i) {
      const int j = n - i;
      unless (a[i]) continue;
      unless (c[j]) continue;
      unless (n - i <= a[i] + c[j]) continue;
      if (i <= n - i) continue;
      int y = min(n - i - 1, a[i]);
      int z = min(n - i - 1, c[n - i]);
      x += min(n - i - 1, y + z - (n - i) + 1);
    }
    cout << x << endl;
  }

  return 0;
}
