// atcoder/abc124/D/main.cpp
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

int fn(string s, int k)
{
  vector<pair<int, int>> v;
  {
    int cnt = 0;
    char prev = s[0];
    each (c, s) {
      if (prev != c) {
        v.push_back({prev - '0', cnt});
        cnt = 0;
        prev = c;
      }
      ++cnt;
    }
    v.push_back({(prev - '0'), cnt});
  }

  int mx = 0;
  each (i, v) {
    if (i.first == 1) {
      setmax(mx, i.second);
    }
  }

  int sum = 0;
  int z = 0;
  queue<pair<int, int>> q;
  each (i, v) {
    q.push(i);
    z += (i.first == 0);
    sum += i.second;
    while (q.size() && k < z) {
      pair<int, int> p = q.front();
      q.pop();
      z -= (p.first == 0);
      sum -= p.second;
    }
    setmax(mx, sum);
  }

  return mx;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  string s;
  while (cin >> n >> k >> s) {
    string t = s;
    replace(begin(t), end(t), '0', '@');
    replace(begin(t), end(t), '1', '0');
    replace(begin(t), end(t), '@', '1');
    string a = s;
    string b = t;
    reverse(begin(a), end(a));
    reverse(begin(b), end(b));
    // cout << fn(s, k) << endl;
    cout << max({fn(s, k), fn(t, k - 1), fn(a, k), fn(b, k - 1)}) << endl;
  }

  return 0;
}
