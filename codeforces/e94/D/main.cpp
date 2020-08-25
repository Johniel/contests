// codeforces/e94/D/main.cpp
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

  int n;
  while (cin >> n) {
    vec<lli> a(n);
    cin >> a;
    a.push_back(3000+1);
    a.push_back(3000+2);
    a.push_back(3000+3);
    a.push_back(3000+4);

    const int N = 3000 + 10;
    static int x[N];
    static int y[N];

    lli z = 0;
    for (int i = 0; i + 2 < n; ++i) {
      fill(x, x + N, 0);
      fill(y, y + N, 0);

      for (int j = i + 2; j < n; ++j) {
        ++y[a[j]];
      }
      ++x[a[i + 1]];
      --y[a[i + 2]];
      lli p = y[a[i + 1]];

      for (int k = i + 2; k + 1 < n; ++k) {
        const int ai = a[i];
        const int ak = a[k];

        // cout << make_pair(i, k) << ' ' << p << endl;

        if (ai == ak) z += p;

        const int ak1 = a[k + 1];

        p -= x[ak] * y[ak];
        ++x[ak];
        p += x[ak] * y[ak];

        p -= x[ak1] * y[ak1];
        --y[ak1];
        p += x[ak1] * y[ak1];
      }
    }

    cout << z << endl;
  }

  return 0;
}
