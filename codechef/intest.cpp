/*
Enormous Input Test
Problem code: INTEST
	
SUBMITMY SUBMISSIONSALL SUBMISSIONS
All submissions for this problem are available.

The purpose of this problem is to verify whether the method you are using to read input data is sufficiently fast to handle problems branded with the enormous Input/Output warning. You are expected to be able to process at least 2.5MB of input data per second at runtime.
Input

The input begins with two positive integers n k (n, k<=107). The next n lines of input contain one positive integer ti, not greater than 109, each.
Output

Write a single integer to output, denoting how many integers ti are divisible by k.
Example

Input:
7 3
1
51
966369
7
9
999996
11

Output:
4
*/
#include<cstdio>
using namespace std;
int main(){
	int tests, k;
	scanf("%d%d", &tests, &k);//cin>>tests>>k;
	int ans=0;
	int n;
	for(int t=0; t<tests; t++){
		scanf("%d", &n);
		if(n%k == 0)
			ans++;
	}
	printf("%d\n", ans);//cout<<ans<<endl;
	return 0;
}
