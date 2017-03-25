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

  vector<string> names;
  for (char c = 'A'; c <= 'Z'; ++c) {
    for (char d = 'a'; d <= 'z'; ++d) {
      names.push_back(string("") + c + d);
    }
  }
  reverse(names.begin(), names.end());

  int n, k;
  while (cin >> n >> k) {
    const int m = n - k + 1;

    string a[n];
    
    string b[n];
    for (int i = 0; i < m; ++i) {
      cin >> b[i];
    }
    int idx = -1;
    for (int i = 0; i < m; ++i) {
      if (b[i] == "YES") {
        idx = i;
        break;
      }
    }
    if (idx == -1) {
      for (int i = 0; i < n; ++i) {
        if (i) cout << ' ' ;
        cout << "Xx" ;
      }
      cout << endl;
      continue;
    }
    for (int i = 0; i < k; ++i) {
      a[idx + i] = names.back();
      names.pop_back();
    }
    for (int i = idx + 1, j = idx + k; i < m; ++i, ++j) {
      if (b[i] == "YES") {
        a[j] = names.back();
        names.pop_back();
      } else {
        a[j] = a[i];
      }
    }
    for (int i = idx - 1; 0 <= i; --i) {
      if (b[i] == "YES") {
        a[i] = names.back();
        names.pop_back();
      } else {
        a[i] = a[i + k - 1];
      }
    }
    
    for (int i = 0; i < n; ++i) {
      if (a[i].empty()) a[i] = '-';
      if (i) cout << ' ';
      cout << a[i];
    }
    cout << endl;
  }
  
  return 0;
}
