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

lli fn(vector<lli> a)
{
  deque<lli> p, q;
  each (i, a) p.push_back(i);

  int cnt = 0;
  while (1 < p.size()) {
    if (q.empty()) {
      q.push_back(p.front());
      p.pop_front();
    } else {
      lli x, y;
      if (cnt % 2) {
        x = p.back();
        p.pop_back();
        y = p.back();
        p.pop_back();
      } else {
        x = p.front();
        p.pop_front();
        y = p.front();
        p.pop_front();
      }
      q.push_back(x);
      q.push_front(y);
    }
    ++cnt;
  }

  if (p.size()) {
    if (abs(q.front() - p.front()) < abs(q.back() - p.front())) {
      q.push_back(p.front());
      p.pop_front();
    } else {
      q.push_front(p.front());
      p.pop_front();
    }
  }

  vector<lli> b;
  while (q.size()) {
    b.push_back(q.front());
    q.pop_front();
  }

  // cout << b << endl;
  lli sum = 0;
  for (int i = 0; i + 1 < b.size(); ++i) {
    sum += abs(b[i] - b[i + 1]);
  }
  return sum;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    vector<lli> a(n);
    cin >> a;
    sort(a.begin(), a.end());    
    lli x = fn(a);
    reverse(a.begin(), a.end());
    lli y = fn(a);
    cout << max(x, y) << endl;
  }
  
  return 0;
}
