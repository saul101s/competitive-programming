#include<bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef pair<int, int>    ii;
typedef vector<ii>        vii;
typedef vector<int>       vi;
#define INF 1000000000;

int n, m;

struct Restriction
{
  int p1;
  int p2;
  int d;
  
  Restriction()
  {
    p1 = 0;
    p2 = 0;
    d = 0;
  }
};

void solve()
{
  int c = 0;
  int d = 0;
  bool correct = true;
  int p[n];
  int pos[n];
  vector<Restriction> r;
  Restriction tmp;
  
  for (int i = 0; i < n; i++)
  {
    p[i] = i;
  }
  
  for (int i = 0; i < m; i++)
  {
    cin >> tmp.p1 >> tmp.p2 >> tmp.d;
    r.push_back(tmp);
  }
  
  do
  {
    if (r.size() == 0)
    {
      c++;
      continue;
    }
    
    for (int i = 0; i < n; i++)
    {
      pos[p[i]] = i;
    }
    
    correct = true;
    
    for (int i = 0; i < m; i++)
    {
      d = abs(pos[r[i].p1] - pos[r[i].p2]);
      
      if ((r[i].d < 0 && d < -r[i].d)
          || (r[i].d > 0 && d > r[i].d))
      {
          correct = false;
          break;
      }
    }
    
    if (correct)
    {
      c++;
    }
    
  } while (next_permutation(p, p + n));
  
  cout << c;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("my-output.txt", "w", stdout);
  freopen("error.txt", "w", stderr);
  #endif

  cin >> n >> m;

  while (n)
  {
    solve();
    cout << "\n";
    
    cin >> n >> m;
  }

  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
