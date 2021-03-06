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

  string s;
  while (cin >> s) {
    set<int> idx;
    vector<string> v = {"Danil", "Olya", "Slava", "Ann", "Nikita"};
    for (int i = 0; i < s.size(); ++i) {
      string t = s.substr(i);
      each (j, v) {
        auto x = t.find(j);
        if (x != string::npos) idx.insert(x + i);
      }
    }
    cout << (idx.size() == 1 ? "YES" : "NO") << endl;
  }
  
  return 0;
}
