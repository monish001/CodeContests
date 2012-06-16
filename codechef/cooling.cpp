/*
Cooling Pies
Problem code: COOLING
	
SUBMITMY SUBMISSIONSALL SUBMISSIONS
All submissions for this problem are available.

The chef has just finished baking several pies, and it's time to place them on cooling racks. The chef has exactly as many cooling racks as pies. Each cooling rack can only hold one pie, and each pie may only be held by one cooling rack, but the chef isn't confident that the cooling racks can support the weight of the pies. The chef knows the weight of each pie, and has assigned each cooling rack a maximum weight limit. What is the maximum number of pies the chef can cool on the racks?
Input:

Input begins with an integer T=30, the number of test cases. Each test case consists of 3 lines. The first line of each test case contains a positive integer N=30, the number of pies (and also the number of racks). The second and third lines each contain exactly positive N integers not exceeding 100. The integers on the second line are the weights of the pies, and the integers on the third line are the weight limits of the cooling racks.
Output:

For each test case, output on a line the maximum number of pies the chef can place on the racks.
Sample input:

2
3
10 30 20
30 10 20
5
9 7 16 4 8
8 3 14 10 10
 
Sample output:

3
4
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
	int t;
	cin>>t;
	for(int test=0; test<t; test++){
		int n;
		cin>>n;
		vector<int> pies;
		vector<int> racks;
		for(int i=0; i<n;i++){
			int inp;
			cin>>inp;
			pies.push_back(inp);
		}
		for(int i=0; i<n;i++){
			int inp;
			cin>>inp;
			racks.push_back(inp);
		}
		sort(pies.begin(), pies.end());
		sort(racks.begin(), racks.end());
		int ans=0, pie=n-1, rack=n-1;
		while(pie>=0 && rack>=0){
			while(pie>=0 && pies[pie] > racks[rack])
				pie--;
			if(pie>=0){
				ans++;
				pie--;
				rack--;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
