/*
A Very Easy Problem!
Problem code: EASYPROB
	
SUBMITMY SUBMISSIONSALL SUBMISSIONS
All submissions for this problem are available.

Input

There's no input.
Output

Output some form of these numbers: 137, 1315, 73, 136, 255, 1384, 16385, one per line in the listed order.
Example

Output:
The first two lines of the CORRECT output file are:

137=2(2(2)+2+2(0))+2(2+2(0))+2(0)
1315=2(2(2+2(0))+2)+2(2(2+2(0)))+2(2(2)+2(0))+2+2(0)

The correct output file should contain 7 lines.
*/
#include <iostream>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <sstream>
#include <ctime>
#include <numeric>
#include <cstring>
#include <functional>

using namespace std;
int main(){
	map<int, string> mp;
	mp[1]="2(0)";
	mp[2]="2";
	mp[4]="2(2)";
	mp[8]="2(2+2(0))";
	mp[16]="2(2(2))";
	mp[32]="2(2(2)+2(0))";
	mp[64]="2(2(2)+2)";
	mp[128]="2(2(2)+2+2(0))";
	mp[256]="2(2(2+2(0)))";
	mp[512]="2(2(2+2(0))+2(0))";
	mp[1024]="2(2(2+2(0))+2)";
	mp[2048]="2(2(2+2(0))+2+2(0))";
	mp[4096]="2(2(2+2(0))+2(2))";
	mp[8192]="2(2(2+2(0))+2(2)+2(0))";
	mp[16384]="2(2(2+2(0))+2(2)+2)";
	int array[] = {137, 1315, 73, 136, 255, 1384, 16385};
	for(int i=0; i<7; i++){
		int n=array[i];
		string ans("");
		bool addPlus = false;
		for(int j=1; n!=0; j*=2){
			if(n&1){//if n odd
				if(addPlus)
					ans = "+"+ans;
				ans = mp[j]+ans;
				addPlus = true;
			}
			n>>=1;
		}
		cout<<array[i]<<"="<<ans<<endl;
	}
	cin>>array[0];
	return 0;
}
