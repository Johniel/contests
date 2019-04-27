// codeforces/555div3/C/main.cpp
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

  int n;
  while (cin >> n) {
    deque<int> q;
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      q.push_back(x);
    }
    int x = -1;
    string s;
    while (q.size()) {
      if (x >= min(q.front(), q.back())) break;
      if (q.front() == q.back()) break;
      if (q.front() < q.back()) {
        x = q.front();
        s += 'L';
        q.pop_front();
        continue;
      }
      if (q.front() > q.back()) {
        x = q.back();
        s += 'R';
        q.pop_back();
        continue;
      }
    }

    int prev;
    pair<int, int> R, L;

    prev = x;
    for (int i = 0; i < q.size(); ++i) {
      unless (prev < q[i]) break;
      ++L.first;
      L.second = q[i];
      prev = q[i];
    }
    prev = x;
    for (int i = q.size() - 1; 0 <= i; --i) {
      unless (prev < q[i]) break;
      ++R.first;
      R.second = q[i];
      prev = q[i];
    }

    if (R > L) {
      s += string(R.first, 'R');
    } else {
      s += string(L.first, 'L');
    }
    cout << s.size() << endl;
    cout << s << endl;
  }

  return 0;
}
