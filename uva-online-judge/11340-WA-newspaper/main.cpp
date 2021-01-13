#include<bits/stdc++.h>
using namespace std;

// Read character by character gives a TLE

void solve()
{
	unordered_map<char, int> ch_value;
	int letters, lines, value;
	char ch;
	string input;
	
	cin >> letters;
	getline(cin, input);
	
	while (letters--)
	{
		stringstream ss;
		getline(cin, input);
		ss << input;
		
		ss >> ch >> value;
		ch_value[ch] = value;
	}
	
	value = 0;
	
	cin >> lines;
	getline(cin, input);
	
	while (lines--)
	{
		getline(cin, input);
		
		for (int i = 0; i < (int)input.size(); i++)
		{
			if (ch_value.find(input[i]) != ch_value.end())
			{
				value += ch_value[input[i]];
			}
		}
	}
	
	printf("%.2f$", value / 100.0f);
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
