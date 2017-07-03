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

struct S {
  int begin, end;
  lli cost;
  S(int b, int e, lli c) : begin(b), end(e), cost(c) {}
  lli operator () (){
    return end - begin + 1;
  }
};

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, x;
  while (cin >> n >> x) {
    vector<S> v;
    for (int i = 0; i < n; ++i) {
      int a, b;
      lli c;
      cin >> a >> b >> c;
      v.push_back(S(a, b, c));
    }
    const int X = 2 * 100000 + 1;
    static vector<pair<int, lli>> u[X];
    fill(u, u + X, vector<pair<int, lli>>());
    each (i, v) {
      u[i()].push_back(make_pair(i.begin, i.cost));
    }
    for (int i = 0; i < X; ++i) {
      sort(u[i].begin(), u[i].end());
    }

    static vector<lli> acc[X];
    fill(acc, acc + X, vector<lli>());
    for (int i = 0; i < X; ++i) {
      if (u[i].empty()) continue;
      vector<lli> v(u[i].size(), u[i].back().second);
      for (int j = v.size() - 2; 0 <= j; --j) {
        v[j] = min(v[j + 1], u[i][j].second);
      }
      acc[i] = v;
    }
    
    const lli inf = 1LL << 60;
    lli mn = inf;
    each (i, v) {
      const int j = x - i();
      unless (0 <= j) continue;
      auto itr = lower_bound(u[j].begin(), u[j].end(), make_pair(i.end + 1, 0LL));
      if (itr == u[j].end()) continue;
      const int k = distance(u[j].begin(), itr);
      mn = min(mn, i.cost + acc[j][k]);
      // cout << i.begin << ' ' << i.end << ' ' << i.cost << ": " << *itr << endl;
    }
    cout << (mn == inf ? -1 : mn) << endl;
  }
  
  return 0;
}
