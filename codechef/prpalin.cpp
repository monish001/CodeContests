/*
Prime Palindromes
Problem code: PRPALIN

SUBMITMY SUBMISSIONSALL SUBMISSIONS
All submissions for this problem are available.

An integer is said to be a palindrome if it is equal to its reverse. For example, 79197 and 324423 are palindromes. In this task you will be given an integer N, 1 N 1000000. You must find the smallest integer M N such that M is a prime number and M is a palindrome.
For example, if N is 31 then the answer is 101.
Input

A single integer N, (1 N 1000000), on a single line.
Output

Your output must consist of a single integer, the smallest prime palindrome greater than or equal to N.
Example

Input:
31
Output:
101
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
bool prime[MAXNUM]={0};//prime[i] will be true only if i is prime palindrome
void computePrimes(){
	for(int i=0; i<MAXNUM; i++){
		prime[i]=true;
	}
	for(int i=2; i<MAXNUM; i++){
		if(prime[i]==true){
			int prod;
			for(int j=2; (prod=i*j)<MAXNUM; j++){
				prime[prod] = false;
				//cout<<prod<<" is not prime.\n";
			}
			int rev=0, n=i;
			while(n){
				rev *= 10;
				rev += n%10;
				n/=10;
			}
			if(rev != i)
				prime[i]=false;
			//else 
				//cout<<i<<"\t";
		}
		
	}
}
int main(){
	computePrimes();
	int n;
	cin>>n;
	for(int i=n+1; i<MAXNUM; i++)
	if(prime[i]){
		cout<<i;
		break;
	}
//	cin>>n;
	return 0;
}
