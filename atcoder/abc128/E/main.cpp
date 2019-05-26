// atcoder/abc128/E/main.cpp
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

struct X {
  int idx;
  int begin, end, x;
};
bool operator < (X i, X j) {
  return i.end - i.x > j.end - j.x;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, q;
  while (cin >> n >> q) {
    vector<X> v(n);
    int idx = 0;
    each (i, v) {
      i.idx = idx++;
      cin >> i.begin >> i.end >> i.x;
    }

    vector<int> d(q);
    cin >> d;

    sort(v.begin(), v.end(), [] (auto i, auto j) {
      return i.begin - i.x < j.begin - j.x;
    });
    reverse(v.begin(), v.end());

    priority_queue<X> q;
    priority_queue<pair<int, int>> r;
    set<int> used;
    each (i, d) {
      while (v.size() && v.back().begin <= i + v.back().x) {
        q.push(v.back());
        r.push({-1 * v.back().x, v.back().idx});
        v.pop_back();
      }
      while (q.size() && !(i + q.top().x < q.top().end)) {
        used.insert(q.top().idx);
        q.pop();
      }
      while (r.size() && used.count(r.top().second)) {
        r.pop();
      }
      cout << (r.empty() ? -1 : -1 * r.top().first) << endl;
    }
  }

  return 0;
}
