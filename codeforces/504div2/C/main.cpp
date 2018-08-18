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

template<typename T>
ostream& operator << (ostream& os, vector<T> v)
{
  os << "(";
  each (i, v) os << i << ",";
  os << ")";
  return os;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  string s;
  while (cin >> n >> k >> s) {
    stack<int> t;
    int color[s.size()];
    int cnt = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '(') {
        color[i] = cnt++;
        t.push(color[i]);
      } else {
        color[i] = t.top();
        t.pop();
      }
    }

    // for (int i = 0; i < s.size(); ++i) cout << color[i] << ' '; cout << endl;
    
    string u;
    for (int i = 0; i < s.size(); ++i) {
      if (k/2 > color[i]) u += s[i];
    }
    assert(u.size() == k);
    cout << u << endl;  
  }
  
  return 0;
}
