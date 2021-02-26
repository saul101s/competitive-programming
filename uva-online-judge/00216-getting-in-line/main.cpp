#include<bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef pair<int, int>    ii;
typedef vector<ii>        vii;
typedef vector<int>       vi;
#define INF 1000000000

struct State
{
  float min_dist;
  vector<int> path;
  
  State()
  {
    min_dist = INF;
    path = vi();
  }
  
  State(float _min_dist, const vector<int>& _path)
  {
    min_dist = _min_dist;
    path = _path;
  }
};

int c = 1;
int N;
int x[8], y[8];
float distances[8][8];
State memo[8][1 << 8];

State tsp(int pos, int bitmask)
{ 
  if (bitmask == ((1 << N) - 1)) return State(0, vi({pos}));
  if (memo[pos][bitmask].min_dist < INF) return memo[pos][bitmask];
  
  State ans = State(INF, vi());
  State tmp;
  
  for (int i = 0; i < N; i++)
  {
    if (!(bitmask & (1 << i)) && pos != i)
    {
      tmp = tsp(i, bitmask | (1 << i));
      tmp.min_dist += distances[pos][i];
      
      if (tmp.min_dist < ans.min_dist)
      {
        ans = tmp;
        ans.path.push_back(pos);
      }
    }
  }
  
  return ans;
}

void solve()
{
  for (int i = 0; i < N; i++)
  {
    cin >> x[i] >> y[i];
  }
  
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      distances[i][j] = -1.0f;
    }
  }
    
  int dx, dy;
  
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      dx = x[j] - x[i];
      dy = y[j] - y[i];
      
      if (distances[j][i] != -1) distances[i][j] = distances[j][i];
      else distances[i][j] = sqrt(dx*dx + dy*dy) + 16.0f;
    }
  }
  
  State ans = tsp(0, 1);
  State tmp;
  
  for (int i = 1; i < 8; i++)
  {
    tmp = tsp(i, (1 << i));
    
    if (tmp.min_dist < ans.min_dist) ans = tmp;
  }
  
  
  int pos = 0;
  int prev = 0;
  
  for (int i = ans.path.size() - 1; i > 0; i--)
  {
    pos = ans.path[i];
    prev = ans.path[i - 1];
    
    printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2f feet.\n", x[pos], y[pos], x[prev], y[prev], distances[pos][prev]);
  }
  
  printf("Number of feet of cable required is %.2f.", ans.min_dist);
  cerr << endl;
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
  
  while (cin >> N && N)
  {
    printf("**********************************************************\nNetwork #%d\n", c++);
    solve();
    printf("\n");
  }

  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
