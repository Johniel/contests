// codeforces/612div2/D/main.cpp
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

const int N = 2000 + 5;
int a[N];
vector<int> g[N];

int n;
vector<int> rec(int curr)
{
  if (g[curr].empty() && a[curr]) throw "";
  vector<int> v;
  each (next, g[curr]) {
    vector<int> u = rec(next);
    v.insert(v.begin(), u.begin(), u.end());
  }
  if (v.empty()) {
    v.push_back(curr);
  } else {
    auto itr = v.begin();
    itr += a[curr];
    // cout << v << " INSERT " << curr << " at " << a[curr] << endl;
    if (v.size() < a[curr]) throw "";
    v.insert(itr, curr);
  }
  return v;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  while (cin >> n) {
    fill(g, g + N, vector<int>());
    int root;
    for (int i = 0; i < n; ++i) {
      int p, c;
      cin >> p >> c;
      --p;
      a[i] = c;
      if (0 <= p) {
        g[p].push_back(i);
      } else {
        root = i;
      }
    }
    try {
      vector<int> v = rec(root);
      map<int, int> m;
      for (int i = 0; i < v.size(); ++i) {
        m[v[i]] = m.size();
      }
      cout << "YES" << endl;
      each (i, m) cout << i.second + 1 << ' ';
      cout << endl;
    } catch (const char* e) {
      cout << "NO" << endl;
    }
  }

  return 0;
}
