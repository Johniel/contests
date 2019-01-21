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

  int n, k;
  string s;
  while (cin >> n >> k >> s) {
    int mx = 0;
    for (char c = 'a'; c <= 'z'; ++c) {
      int x = 0;
      int cnt = 0;
      for (int i = 0; i < s.size(); ++i) {
        if (s[i] == c) {
          ++cnt;
          if (cnt == k) {
            ++x;
            cnt = 0;
          }
        } else {
          cnt = 0;
        }
      }
      setmax(mx, x);
    }
    cout << mx << endl;
  }
  
  return 0;
}
