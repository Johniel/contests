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

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  string s;
  while (cin >> n >> s) {
    const int sheep = 0;
    const int wolf = 1;
    vector<int> v(n, -1);

    auto fn = [&] () {
      for (int i = 0; i < n; ++i) {
        int j = (i - 1 + n) % n;
        int k = (i + 1) % n;
        if (v[i] == sheep) {
          if (s[i] == 'o' && v[j] != v[k]) return false;
          if (s[i] == 'x' && v[j] == v[k]) return false;
        }
        if (v[i] == wolf) {
          if (s[i] == 'x' && v[j] != v[k]) return false;
          if (s[i] == 'o' && v[j] == v[k]) return false;
        }
      }
      return true;
    };

    for (int a = 0; a <= 1; ++a) {
      for (int b = 0; b <= 1; ++b) {
        v[0] = a;
        v[1] = b;
        for (int i = 1; i < n; ++i) {
          const int j = (i - 1 + n) % n;
          const int k = (i + 1) % n;
          if (v[i] == sheep) {
            if (s[i] == 'o') v[k] = v[j];
            else v[k] = v[j] ^ 1;
          }
          if (v[i] == wolf) {
            if (s[i] == 'o') v[k] = v[j] ^ 1;
            else v[k] = v[j];
          }
        }
        if (fn()) a = b = 2;
      }
    }

    if (fn()) {
      each (i, v) {
        if (i == sheep) cout << 'S';
        else cout << 'W';
      }
      cout << endl;
    } else {
      cout << -1 << endl;
    }
  }

  return 0;
}
