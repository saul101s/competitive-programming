#include<bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef pair<int, int>    ii;
typedef vector<ii>        vii;
typedef vector<int>       vi;
#define INF 1000000000;

int M;

void solve()
{
  int tmp = 0, tmp2 = 0;
  char ch;
  int min_distance = 0;
  vii ones;
  vii threes;
  
  for (int row = 0; row < M; row++)
  {
    for (int col = 0; col < M; col++)
    {
      cin >> ch;
      
      if (ch - '0' == 1)
      {
        ones.push_back(make_pair(row, col));
      }
      else if (ch - '0' == 3)
      {
        threes.push_back(make_pair(row, col));
      }
    }
  }
  
  for (int i = 0; i < (int)ones.size(); i++)
  {
    tmp2 = INF;
    
    for (int j = 0; j < (int)threes.size(); j++)
    {
      tmp = abs(ones[i].first - threes[j].first) + abs(ones[i].second - threes[j].second);
      
      if (tmp < tmp2)
      {
        tmp2 = tmp;
      }
    }
    
    min_distance = max(min_distance, tmp2);
  }
  
  cout << min_distance;
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

  while (cin >> M)
  {
    cin.ignore(5, '\n');
    solve();
    cout << "\n";
  }

  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
