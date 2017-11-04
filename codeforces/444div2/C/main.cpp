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

bool fn(vector<int> v)
{
  v.insert(v.begin(), -1);
  {
    vector<int> a;
    a.push_back(v[1]);
    a.push_back(v[3]);
    a.push_back(v[5]);
    a.push_back(v[7]);
    a.push_back(v[9]);
    a.push_back(v[11]);
    a.push_back(v[24]);
    a.push_back(v[22]);
    vector<int> b;
    b.push_back(v[2]);
    b.push_back(v[4]);
    b.push_back(v[6]);
    b.push_back(v[8]);
    b.push_back(v[10]);
    b.push_back(v[12]);
    b.push_back(v[23]);
    b.push_back(v[21]);
    assert(a.size() == b.size());
    bool x = true;
    bool y = true;
    for (int i = 0; i < a.size(); ++i) {
      int j = (i + 2) % a.size();
      int k = (i - 2 + a.size()) % a.size();
      x = x && (a[i] == b[j]);
      y = y && (a[i] == b[k]);
    }
    bool z = true;
    z = z && (v[13] == v[14] && v[14] == v[15] && v[15] == v[16]);
    z = z && (v[17] == v[18] && v[18] == v[19] && v[19] == v[20]);
    if (z && (x || y)) return true;
  }

  {
    vector<int> a;
    a.push_back(v[13]);
    a.push_back(v[14]);
    a.push_back(v[5]);
    a.push_back(v[6]);
    a.push_back(v[17]);
    a.push_back(v[18]);
    a.push_back(v[21]);
    a.push_back(v[22]);
    vector<int> b;
    b.push_back(v[15]);
    b.push_back(v[16]);
    b.push_back(v[7]);
    b.push_back(v[8]);
    b.push_back(v[19]);
    b.push_back(v[20]);
    b.push_back(v[23]);
    b.push_back(v[24]);
    assert(a.size() == b.size());
    bool x = true;
    bool y = true;
    for (int i = 0; i < a.size(); ++i) {
      int j = (i + 2) % a.size();
      int k = (i - 2 + a.size()) % a.size();
      x = x && (a[i] == b[j]);
      y = y && (a[i] == b[k]);
    }
    bool z = true;
    z = z && (v[1] == v[2] && v[2] == v[3] && v[3] == v[4]);
    z = z && (v[9] == v[10] && v[10] == v[11] && v[11] == v[12]);
    if (z && (x || y)) return true;    
  }
  

  {
    vector<int> a;
    a.push_back(v[1]);
    a.push_back(v[2]);
    a.push_back(v[18]);
    a.push_back(v[20]);
    a.push_back(v[12]);
    a.push_back(v[11]);
    a.push_back(v[15]);
    a.push_back(v[13]);
    vector<int> b;
    b.push_back(v[3]);
    b.push_back(v[4]);
    b.push_back(v[17]);
    b.push_back(v[19]);
    b.push_back(v[10]);
    b.push_back(v[9]);
    b.push_back(v[16]);
    b.push_back(v[14]);
    assert(a.size() == b.size());
    bool x = true;
    bool y = true;
    for (int i = 0; i < a.size(); ++i) {
      int j = (i + 2) % a.size();
      int k = (i - 2 + a.size()) % a.size();
      x = x && (a[i] == b[j]);
      y = y && (a[i] == b[k]);
    }
    bool z = true;
    z = z && (v[5] == v[6] && v[6] == v[7] && v[7] == v[8]);
    z = z && (v[21] == v[22] && v[22] == v[23] && v[23] == v[24]);
    if (z && (x || y)) return true;    
  }

  return false;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  while (true) {
    vector<int> v(24);
    each (i, v) unless (cin >> i) return 0;
    cout << (fn(v) ? "YES" : "NO") << endl;
  }
  
  return 0;
}
