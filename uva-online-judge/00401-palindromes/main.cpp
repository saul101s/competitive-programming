#include<bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef pair<int, int>    ii;
typedef vector<ii>        vii;
typedef vector<int>       vi;
#define INF 1000000000

string word;
map<char, char> reverseMap {
  {'A', 'A'},
  {'E', '3'}, {'3', 'E'},
  {'H', 'H'},
  {'I', 'I'},
  {'J', 'L'}, {'L', 'J'},
  {'M', 'M'},
  {'O', 'O'},
  {'S', '2'}, {'2', 'S'},
  {'T', 'T'},
  {'U', 'U'},
  {'V', 'V'},
  {'W', 'W'},
  {'X', 'X'},
  {'Y', 'Y'},
  {'Z', '5'}, {'5', 'Z'},
  {'1', '1'},
  {'8', '8'}
};

void solve()
{
  bool isPalindrome = true;
  bool isMirror = true;
  int halfSize = word.size() / 2;
  
  for (int i = 0; i < halfSize; i++) {
    char c = word[i];
    char sc = word[word.size() - 1 - i];
    if (c != sc)
      isPalindrome = false;
    if (reverseMap.find(sc) == reverseMap.end() || c != reverseMap[sc])
      isMirror = false;
  }
  
  if (word.size() % 2 != 0) {
    char c = word[halfSize];
    if (reverseMap.find(c) == reverseMap.end() || reverseMap[c] != c)
        isMirror = false;
  }
  
  cout << word << " -- ";
  
  if (isPalindrome)
    if (isMirror)
      cout << "is a mirrored palindrome.";
    else
      cout << "is a regular palindrome.";
  else
    if (isMirror)
      cout << "is a mirrored string.";
    else
      cout << "is not a palindrome.";
      
  cout << "\n";
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

  while (cin >> word)
  {
    solve();
    cout << "\n";
  }

  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
