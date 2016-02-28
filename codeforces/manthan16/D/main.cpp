#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

template<typename P, typename Q>
ostream& operator << (ostream& os, pair<P, Q> p)
{
  os << "(" << p.first << "," << p.second << ")";
  return os;
}


int main(int argc, char *argv[])
{
  int n;
  while (scanf("%d", &n) == 1) {
    map<lli, int> m;
    vector<lli> v;
    for (int i = 0; i < n; ++i) {
      lli x;
      scanf("%lld", &x);
      ++m[x];
      v.push_back(x);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    int mx = 2;
    map<pair<lli, lli>, int> vis;
    for (int i = 0; i < v.size(); ++i) {
      for (int j = 0; j < v.size(); ++j) {
        lli prev = v[i];
        lli curr = v[j];
        --m[prev];
        --m[curr];
        if (m[prev] < 0 || m[curr] < 0) {
          ++m[prev];
          ++m[curr];
          continue;
        }
        vector<lli> fib = {prev, curr};
        while (true) {
          lli next = curr + prev;
          if (m.count(next) == 0 || m[next] <= 0) break;
          fib.push_back(next);
          --m[next]; 
          prev = curr;
          curr = next;
        }
        mx = max<int>(mx, fib.size());
        each (i, fib) ++m[i];
      }
    }
    printf("%d\n", mx);
  }

  return 0;
}
