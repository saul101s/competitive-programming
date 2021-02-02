#include<bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef pair<int, int>    ii;
typedef vector<ii>        vii;
typedef vector<int>       vi;
#define INF 1000000000;

int possible_scores[43] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 24, 26, 27, 28, 30, 32, 33, 34, 36, 38, 39, 40, 42, 45, 48, 50, 51, 54, 57, 60};

int score;

void solve()
{
  int n_permutations = 0, n_combinations = 0;
  int s1, s2, s3;
  set<vi> combinations;
  vi combination = vi(3);

  for (int i = 0; i < 43; i++)
  {
    s1 = possible_scores[i];
    
    for (int j = 0; j < 43; j++)
    {
      s2 = possible_scores[j];
      
      for (int k = 0; k < 43; k++)
      {
        s3 = possible_scores[k];
        
        if (s1 + s2 + s3 == score)
        {
          combination[0] = s1;
          combination[1] = s2;
          combination[2] = s3;
          sort(combination.begin(), combination.end());
          
          n_permutations++;
          
          if (combinations.find(combination) == combinations.end())
          {
            n_combinations++;
            combinations.insert(combination);
          }
        }
      }
    }
  }
  
  if (n_permutations > 0)
  {
    cout << "NUMBER OF COMBINATIONS THAT SCORES " << score << " IS " << n_combinations << "." << endl;
    cout << "NUMBER OF PERMUTATIONS THAT SCORES " << score << " IS " << n_permutations << "." << endl;
  }
  else
  {
    cout << "THE SCORE OF " << score << " CANNOT BE MADE WITH THREE DARTS." << endl;
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

  while (cin >> score && score > 0)
  {
    solve();
    cout << "**********************************************************************\n";
  }
  
  cout << "END OF OUTPUT" << endl;

  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
