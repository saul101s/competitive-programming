#include<bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef pair<int, int>    ii;
typedef vector<ii>        vii;
typedef vector<int>       vi;
#define INF 1000000000

int L = 0;
string line;
unsigned char path [2000000];

void solve()
{
  getline(cin, line); // \n
  getline(cin, line);
  int shortest_distance = L;
  int current_distance = 1;
  int last_store = 0; // 0 - none, 1 - restaurant, 2 - drugstore
  
  for (size_t i = 0; i < line.size(); i++) {
    switch (line[i]) {
      case 'R': {
        if (2 == last_store && current_distance < shortest_distance) {
          shortest_distance = current_distance;
        }
        last_store = 1;
        current_distance = 1;
      } break;
      case 'D': {
        if (1 == last_store && current_distance < shortest_distance) {
          shortest_distance = current_distance;
        }
        last_store = 2;
        current_distance = 1;
      } break;
      case '.': {
        ++current_distance;
      } break;
    }
    
    if ('Z' == line[i]) {
      shortest_distance = 0;
      break;
    }
  }
  
  cout << shortest_distance;
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

  cin >> L;

  while (0 != L)
  {
    solve();
    cout << "\n";
    cin >> L;
  }

  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
