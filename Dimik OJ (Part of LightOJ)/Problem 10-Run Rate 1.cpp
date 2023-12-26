#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, run1, run2, ball, balldone;
	double present_rate, wishing_rate;

	cin >> n;
	while(n--){
		cin >> run1 >> run2 >> ball;
		balldone = 300 - ball;
		present_rate = ((run2*1.0) / balldone) * 6.0;
        
        if (run2 > run1)
            wishing_rate = 0.0;
        else 
            wishing_rate = (((run1 - run2 + 1) * 1.0) / ball) * 6.0;
		
		printf("%0.2lf %0.2lf\n",present_rate,wishing_rate);
	}
}