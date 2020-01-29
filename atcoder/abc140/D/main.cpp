// atcoder/abc140/D/main.cpp
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
  string s;
  while (cin >> n >> k >> s) {
    vector<string> v;
    string t;
    each (c, s) {
      if (!t.empty() && t.back() != c) {
        v.push_back(t);
        t = "";
      }
      t += c;
    }
    if (t.size()) v.push_back(t);

    map<char, char> rev;
    rev['R'] = 'L';
    rev['L'] = 'R';

    for (int i = 1; i < v.size() && k; ++i) {
      if (v[i - 1].front() != v[i].front()) {
        v[i] = string(v[i].size(), v[i - 1].front());
        --k;
      }
    }

    t = accumulate(v.begin(), v.end(), string(""));
    int cnt = 0;
    for (int i = 0; i + 1 < t.size(); ++i) {
      cnt += (t[i] == t[i + 1]);
    }
    cout << cnt << endl;
  }

  return 0;
}
