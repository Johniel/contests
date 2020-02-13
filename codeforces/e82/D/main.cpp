// codeforces/e82/D/main.cpp
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
template<typename P, typename Q> inline pair<Q, P> reverse(pair<P, Q> p) { return make_pair(p.second, p.first); }

using lli = long long int;
using ull = unsigned long long;
using point = complex<double>;
using str = string;
template<typename T> using vec = vector<T>;

constexpr lli mod = 1e9 + 7;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int tc;
  cin >> tc;

  lli n;
  int m;
  while (cin >> n >> m) {
    vector<lli> a(m);
    cin >> a;

    const int L = 61;

    vector<lli> w(70, 0);
    each (i, a) {
      for (int j = 0; j < L; ++j) {
        if ((1LL << j) == i) {
          ++w[j];
        }
      }
    }

    vector<lli> u(70, 0);
    for (int j = 0; j < L; ++j) {
      if ((1LL << j) & n) {
        ++u[j];
      }
    }

    // cout << w << endl;
    // cout << u << endl;
    lli cnt = 0;
    for (int i = 0; i < L - 1; ++i) {
      if (u[i] > w[i]) {
        for (int j = i + 1; j < L; ++j) {
          if (w[j]) {
            for (int k = j; i < k; --k) {
              w[k] -= 1;
              w[k - 1] += 2;
              ++cnt;
            }
            break;
          }
        }
      }
      if (u[i] > w[i]) {
        cnt = -1;
        break;
      }
      w[i] -= u[i];
      w[i + 1] += w[i] / 2;
      w[i] %= 2;
    }
    // cout << w << endl;
    // cout << u << endl;
    cout << cnt << endl;
  }

  return 0;
}
