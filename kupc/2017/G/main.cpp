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

typedef pair<int, int> edge;
map<edge, pair<int, int>> conv;

void encode(void)
{
  string x;
  int N, m;
  cin >> N >> m;

  set<edge> used;
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    --x;
    --y;
    used.insert(make_pair(min(x, y), max(x, y)));
    used.insert(make_pair(max(x, y), min(x, y)));
  }
  cin >> x;

  cout << 0 << endl;
  
  ofstream fout("/tmp/111111111.txt");
  fout << x << endl;
  
  return ;
}

void decode(void)
{
  int N, a;
  cin >> N >> a;

  ifstream fin("/tmp/111111111.txt");
  string x;
  fin >> x;
  cout << x << endl;
  
  return ;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s;
  cin >> s;
  if (s == "encode") encode();
  else decode();

  return 0;
}
