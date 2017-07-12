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
  pair<int, int> p;
  int i;
};

bool operator < (const S& a, const S& b)
{
  return a.p < b.p;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    vector<S> v;
    string t[n];
    int len = 0;
    for (int i = 0; i < n; ++i) {
      cin >> t[i];
      int k;
      cin >> k;
      for (int j = 0; j < k; ++j) {
        int x;
        cin >> x;
        v.push_back((S){make_pair(x - 1, x - 1 + t[i].size()), i});
        len = max<int>(len, x + t[i].size() - 1);
      }
    }
    sort(v.begin(), v.end());

    // each (i, v) cout << i.p << ' ' << t[i.i] << endl;
    
    string s(len, '@');

    int idx = 0;
    each (i, v) {
      idx = max(idx, i.p.first);
      for (int j = idx; j < i.p.second; ++j) {
        s[j] = t[i.i][j - i.p.first];
        ++idx;
      }
    }
    
    replace(s.begin(), s.end(), '@', 'a');
    cout << s << endl;
  }

  return 0;
}
