// codeforces/552div3/E/main.cpp
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

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  while (cin >> n >> k) {
    vector<int> v(n);
    cin >> v;
    map<int, int> idx;
    for (int i = 0; i < v.size(); ++i) {
      idx[v[i]] = i;
    }
    set<int> rem;
    each (i, v) rem.insert(i);
    vector<int> left(n, -1);
    vector<int> right(n, -1);
    for (int i = 0; i < v.size(); ++i) {
      if (i) left[i] = i - 1;
      if (i + 1 < v.size()) right[i] = i + 1;
    }
    map<int, int> color;
    for (int i = 0; i < n; ++i) color[i] = -1;
    int cnt = 0;
    while (rem.size()) {
      int x = *rem.rbegin();

      int L = idx[x];
      for (int i = 0; i <= k; ++i) {
        rem.erase(v[L]);
        color[L] = cnt % 2;
        L = left[L];
        if (L == -1) break;
      }
      int R = idx[x];
      for (int i = 0; i <= k; ++i) {
        rem.erase(v[R]);
        color[R] = cnt % 2;
        R = right[R];
        if (R == -1) break;
      }

      if (R != -1) left[R] = L;
      if (L != -1) right[L] = R;

      // for (int i = 0; i < v.size(); ++i) cout << color[i]+1; cout << endl;
      ++cnt;
    }

    for (int i = 0; i < v.size(); ++i) cout << color[i]+1; cout << endl;
    // cout << endl;
  }
  
  return 0;
}
