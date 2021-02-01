#include<bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef pair<int, int>    ii;
typedef vector<ii>        vii;
typedef vector<int>       vi;
#define INF 1000000000;

struct MakerPrice
{
  char name[21];
  int l;
  int h;
};

void solve()
{
  int D, Q, P;
  bool undetermined = false;
  bool found = false;
  char N[21];
  N[0] = '\0';
  
  cin >> D;
  
  MakerPrice makers[D];
  MakerPrice maker;
  
  for (int i = 0; i < D; i++)
  {
    cin >> maker.name >> maker.l >> maker.h;
    makers[i] = maker;
  }
  
  cin >> Q;
  
  while (Q--)
  {
    cin >> P;
    cerr << strlen(N) << endl;
    
    for (int i = 0; i < D; i++)
    {
      if (P >= makers[i].l && P <= makers[i].h)
      {
        if (strlen(N) > 0)
        {
          cout << "UNDETERMINED" << "\n";
          undetermined = true;
          break;
        }
        
        found = true;
        memcpy(N, makers[i].name, strlen(makers[i].name));
        N[strlen(makers[i].name)] = '\0';
      }
    }
    
    if (found)
    {
      if (!undetermined)
      {
        cout << N << "\n";
      }
    }
    else
    {
      cout << "UNDETERMINED" << "\n";
    }
    
    undetermined = false;
    found = false;
    N[0] = '\0';
  }
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

  int t = 1;
  cin >> t;

  while (t--)
  {
    solve();
    
    if (t != 0)
    {
      cout << "\n";
    }
  }

  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
