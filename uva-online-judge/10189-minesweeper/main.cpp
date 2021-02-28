#include<bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef pair<int, int>    ii;
typedef vector<ii>        vii;
typedef vector<int>       vi;
#define INF 1000000000

int c = 1;
int n, m;
char mines[100][100];
int close_mines[100][100];

void solve()
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> mines[i][j];
    }
  }
  
  int sum = 0;
  
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      sum = 0;
      
      for (int k = max(0, i - 1); k < min(n, i + 2); k++)
      {
        for (int z = max(0, j - 1); z < min(m, j + 2); z++)
        {
          if (mines[k][z] == '*') sum += 1;
        }
      }
      
      close_mines[i][j] = sum;
    }
  }
  
  cout << "Field #" << c++ << ":\n";
  
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (mines[i][j] == '*') cout << "*";
        else cout << close_mines[i][j];
      }
      
      cout << "\n";
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
  
  cin >> n >> m;
  
  while (n && m)
  {
    solve();
    
    cin >> n >> m;
    
    if (n && m) cout << "\n";
  }

  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
