#include<bits/stdc++.h>
using namespace std;

void solve();

int reqs, opts;
int c = 1;

constexpr int STRING_MAX_SIZE = 80;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("my-output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif

    scanf("%d %d\n", &reqs, &opts);

    while (reqs && opts)
    {
        solve();
        printf("\n");
        
		scanf("%d %d\n", &reqs, &opts);
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

void solve()
{
	char proposal [STRING_MAX_SIZE + 1];
	char selected_proposal [STRING_MAX_SIZE + 1];
	int reqs_met;
	float price, compliance;
	float selected_proposal_price = 1000000000.0f, selected_proposal_compliance = 0.0f;
	bool exist_compliant_proposal = false;
	
	for (int i = 0; i < reqs; i++)
	{
		fgets(proposal, STRING_MAX_SIZE, stdin);
	}

	while (opts--)
	{
		scanf("%s\n", proposal);
		scanf("%f %d\n", &price, &reqs_met);
		
		if (reqs_met >= reqs)
		{ // Compliant proposal
			if (exist_compliant_proposal)
			{
				if (price < selected_proposal_price)
				{
					memcpy(selected_proposal, proposal, STRING_MAX_SIZE);
					selected_proposal_price = price;
				}
			}
			else
			{
				memcpy(selected_proposal, proposal, STRING_MAX_SIZE);
				selected_proposal_price = price;
			}
		}
		else
		{
			compliance = (float)reqs_met / reqs;
				
			if (compliance > selected_proposal_compliance)
			{
				memcpy(selected_proposal, proposal, STRING_MAX_SIZE);
				selected_proposal_price = price;
				selected_proposal_compliance = compliance;
			}
		}
		
		for (int i = 0; i < reqs_met; i++)
		{
			fgets(proposal, STRING_MAX_SIZE, stdin);
		}
	}
	
	printf("RFP #%d\n", c++);
	printf("%s\n", selected_proposal);
}
