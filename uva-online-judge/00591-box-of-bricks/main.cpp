#include<bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef pair<int, int>    ii;
typedef vector<ii>        vii;
typedef vector<int>       vi;
#define INF 1000000000

int n = 0;
int i = 1;

void solve()
{
  vi wall;
  int totalBricks = 0;
  
  while (n--) {
    int colBricks;
    cin >> colBricks;
    wall.push_back(colBricks);
    totalBricks += colBricks;
  }
  
  int avg = totalBricks / wall.size();
  
  // 3/5
  // extra = 0
  // movements = 0
  // =====================
  // movements = 2
  // extra = -2
  
  // 7/5
  // extra = -2
  // movements = 2
  // =====================
  // movements = 2
  // extra = 0
  
  int moves = 0;
  int extra = 0;
  
  for (auto colBricks = wall.begin(); colBricks != wall.end(); colBricks++) {
    int diff = *colBricks - avg;
    int colMovements = abs(diff);
    int extraUsed = 0;
    
    if (diff < 0) {
      if (extra > 0) {
        extraUsed = min(extra, colMovements);
        extra -= extraUsed;
      }
      extra -= colMovements - extraUsed;
    } else if (diff > 0) {
      if (extra < 0) {
        extraUsed = min(abs(extra), colMovements);
        extra += extraUsed;
      }
      extra += colMovements - extraUsed;
    }
    
    moves += colMovements - extraUsed;
    // cout << to_string(*colBricks) << "/" << to_string(avg) << ". Diff: " << to_string(diff) << ". Extra: " << to_string(extra) << ". Extra used: " << to_string(extraUsed) << ". Moves: " << moves << "\n";
  }
  
  cout << "Set #" << i++ << "\n";
  cout << "The minimum number of moves is " << moves << ".\n";
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

  cin >> n;

  while (n != 0)
  {
    solve();
    cout << "\n";
    cin >> n;
  }

  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
