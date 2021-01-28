#include<bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef pair<int, int>    ii;
typedef vector<ii>        vii;
typedef vector<int>       vi;
#define INF 1000000000;

int max_score = 0, chess_scores[8][8], row[8];
bitset<20> rw, ld, rd;

bool can_place(int r, int c)
{
  return !rw[r] && !ld[r-c+7] && !rd[r+c];
}

void backtrack(int c)
{
  if (c == 8)
  {
    int sum = 0;
    for (int col = 0; col < 8; col++)
    {
      sum += chess_scores[row[col]][col];
    }
    max_score = max(max_score, sum);
  }
  else
  {
    for (int r = 0; r < 8; r++)
    {
      if (can_place(r, c))
      {
        rw[r] = ld[r-c+7] = rd[r+c] = true;
        row[c] = r;
        backtrack(c+1);
        rw[r] = ld[r-c+7] = rd[r+c] = false;
      }
    }
  }
}

void solve()
{
  max_score = 0;
  
  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      cin >> chess_scores[i][j];
    }
  }
  
  backtrack(0);
  printf("%5d", max_score);
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
    printf("\n");
  }

  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
