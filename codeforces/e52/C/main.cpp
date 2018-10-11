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

template<typename T>
struct Acc {
  vector<T> sum;
  Acc(vector<T> v) {
    sum.push_back(0);
    each (i, v) {
      sum.push_back(sum.back() + i);
    }
  }
  T operator () (int begin, int end) const {
    return query(begin, end);
  }
  T query(int begin, int end) const {
    return sum[end] - sum[begin];
  }
};


int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  lli n, k;
  while (cin >> n >> k) {
    vector<lli> v(n);
    cin >> v;
    sort(v.begin(), v.end());

    lli mn = v.front();
    each (i, v) i -= mn;

    Acc<lli> acc(v);

    auto count = [&] (lli h) {
      int idx = lower_bound(v.begin(), v.end(), h) - v.begin();
      return acc(idx, v.size()) - (v.size() - idx) * h;
    };
    auto cost = [&] (lli prev, lli h) { return count(h) - count(prev); };

    lli prev = v.back();
    int cnt = 0;
    while (true) {
      lli x;
      for (lli next = prev; 0 <= next; --next) {
        if (cost(prev, next) <= k) {
          x = next;
        } else {
          break;
        }
      }
      if (prev == x) break;
      prev = x;
      ++cnt;
    }
    cout << cnt << endl;
  }
  
  return 0;
}
