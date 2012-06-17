/*
Birthday Candles
Problem code: CANDLE
	
SUBMITMY SUBMISSIONSALL SUBMISSIONS
All submissions for this problem are available.

The chef is preparing a birthday cake for one of his guests, and his decided to write the age of the guest in candles on the cake. There are 10 types of candles, one for each of the digits '0' through '9'. The chef has forgotten the age of the guest, however, so doesn't know whether he has enough candles of the right types. For example, if the guest were 101 years old, the chef would need two '1' candles and one '0' candle. Given the candles the chef has, your task is to determine the smallest positive integer that cannot be represented with those candles.
Input:

Input will begin with an integer T≤100, the number of test cases. Each test case consists of a single line with exactly 10 integers, each between 0 and 8, inclusive. The first integer of each test case represents the number of '0' candles the chef has, the second integer represents the number of '1' candles the chef has, and so on.
Output:

For each test case, output on a single line the smallest positive integer that cannot be expressed with the given candles.
Sample input:

3
2 1 1 4 0 6 3 2 2 2
0 1 1 1 1 1 1 1 1 1
2 2 1 2 1 1 3 1 1 1
 
Sample output:

4
10
22
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
#define MAXNUM 1003003
using namespace std;
vector<pair<int,bool> > nums;
int main(){
	int n;
	cin>>n;
	for(int test=1; test<=n; test++){
		vector<int> nums;
		for(int i=0; i<10; i++){
			int num;
			cin>>num;
			nums.push_back(num);
		}
		int minNum=2000000000, minIndex;
		for(int i=1; i<10; i++){
			if(minNum > nums[i]){
				minIndex = i;
				minNum = nums[i];
			}
		}
		if(minNum > nums[0]){
			cout<<"1";
			minNum = nums[0];
			minIndex=0;
		}
		for(int i=0; i<=minNum; i++){
			cout<<minIndex;
		}
		cout<<endl;
	}
//	cin>>n;
	return 0;
}
