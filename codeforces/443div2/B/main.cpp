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
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  lli k;
  while (cin >> n >> k) {
    deque<int> q;

    for (int i = 0; i < n; ++i) {
      int a;
      cin >> a;
      q.push_back(a);
    }

    int x = n;
    while (true) {
      int a = q.front();
      q.pop_front();
      int b = q.front();
      q.pop_front();
      int cnt = 1;
      int c = max(a, b);
      q.push_back(min(a, b));
      while (cnt < min<lli>(n, k)) {
        if (c < q.front()) {
          break;
        }
        ++cnt;
        q.push_back(q.front());
        q.pop_front();
      }
      if (min<lli>(n, k) == cnt) {
        x = c;
        break;
      }
      q.push_front(c);
    }
    cout << x << endl;
  }
  
  return 0;
}
