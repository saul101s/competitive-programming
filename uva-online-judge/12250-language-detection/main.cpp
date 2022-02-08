#include<bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef pair<int, int>    ii;
typedef vector<ii>        vii;
typedef vector<int>       vi;
#define INF 1000000000

char word[13];
int c = 1;

void solve()
{
  printf("Case %d: ", c++);
  
  if (strcmp(word, "HELLO") == 0)
  {
    printf("%s", "ENGLISH");
  }
  else if (strcmp(word, "HOLA") == 0)
  {
    printf("%s", "SPANISH");
  }
  else if (strcmp(word, "HALLO") == 0)
  {
    printf("%s", "GERMAN");
  }
  else if (strcmp(word, "BONJOUR") == 0)
  {
    printf("%s", "FRENCH");
  }
  else if (strcmp(word, "CIAO") == 0)
  {
    printf("%s", "ITALIAN");
  }
  else if (strcmp(word, "ZDRAVSTVUJTE") == 0)
  {
    printf("%s", "RUSSIAN");
  }
  else
  {
    printf("%s", "UNKNOWN");
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

  scanf("%s", word);


  while (strcmp(word, "#") != 0)
  { 
    solve();
    printf("\n");
    
    scanf("%s", word);
  }

  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
