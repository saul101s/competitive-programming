#include<bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef pair<int, int>    ii;
typedef vector<ii>        vii;
typedef vector<int>       vi;
#define INF 1000000000

int n;

vi adjList[200];
int colors[200];


queue<int> q;

void solve()
{
  int l = 0, a = 0, b = 0;
  int color = 0;
  bool can_be_colored = true;
  
  cin >> l;
  
  while (l--)
  {
    cin >> a >> b;
    adjList[a].push_back(b);
  }
  
  colors[0] = color;
  q.push(0);
  
  while (!q.empty() && can_be_colored)
  {
    int u = q.front(); q.pop();
    color = 1 - colors[u];
    
    for (int i = 0; i < (int)adjList[u].size(); i++)
    {
      int v = adjList[u][i];
      
      if (colors[v] == -1)
      {
        colors[v] = color;
        q.push(v);
      }
      else
      {
        if (colors[v] != color)
        {
          can_be_colored = false;
          break;
        }
      }
    }
  }
  
  while (!q.empty())
    q.pop();
    
  if (can_be_colored)
    cout << "BICOLORABLE.";
  else
    cout << "NOT BICOLORABLE.";
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

  while ((cin >> n) && n)
  {
    for (int i = 0; i < 200; i++)
    {
      adjList[i].clear();
    }
    
    memset(colors, -1, sizeof colors);
    
    solve();
    cout << "\n";
  }

  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
