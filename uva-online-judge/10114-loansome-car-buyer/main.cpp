#include<bits/stdc++.h>
using namespace std;

void solve();

int loan_months, records;
float payment_down, loan_amount;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("my-output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif

    scanf("%d %f %f %d", &loan_months, &payment_down, &loan_amount, &records);

    while (loan_months > 0)
    {
        solve();
        printf("\n");
        
        scanf("%d %f %f %d", &loan_months, &payment_down, &loan_amount, &records);
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

void solve()
{
	float car_value, to_pay, dep_old, dep_new, month_payment;
  int dep_month, months;
  
  car_value = loan_amount + payment_down;
  to_pay = loan_amount;
  month_payment = loan_amount / loan_months;
  months = 0;
  
  scanf("%d %f", &dep_month, &dep_old);
  car_value *= (1 - dep_old);
  records--;
  
  if (records)
  {
    scanf("%d %f", &dep_month, &dep_new);
    records--;
  }
  
  while (to_pay > car_value && months < loan_months)
  {
    to_pay -= month_payment;
    
    if ((months + 1) >= dep_month)
    {
      dep_old = dep_new;
      
      if (records)
      {
        scanf("%d %f", &dep_month, &dep_new);
        records--;
      }
    }
    
    car_value *= (1 - dep_old);
    
    months++;
  }
  
  printf("%d %s", months, months == 1 ? "month" : "months");
}
