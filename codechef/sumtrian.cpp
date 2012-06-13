/*
Sums in a Triangle
Problem code: SUMTRIAN
	
SUBMITMY SUBMISSIONSALL SUBMISSIONS
All submissions for this problem are available.

Let's consider a triangle of numbers in which a number appears in the first line, two numbers appear in the second line, three in the third line, etc. Develop a program which will compute the largest of the sums of numbers that appear on the paths starting from the top towards the base, so that:
on each path the next number is located on the row below, more precisely either directly below or below and one place to the right;
the number of rows is strictly positive, but less than 100
all numbers are positive integers between O and 99.
Input

In the first line integer n - the number of test cases (equal to about 1000).
Then n test cases follow. Each test case starts with the number of lines which is followed by their content.
Output

For each test case write the determined value in a separate line.
Example

Input:
2
3
1
2 1
1 2 3
4 
1 
1 2 
4 1 2
2 3 1 1 

Output:
5
9


Warning: large Input/Output data, be careful with certain languages 
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <sstream>
#include <ctime>
#include <numeric>
#include <cstring>
#include <functional>
using namespace std;
int array[99][99];
int main(int argc, char *argv[]) {
	int t;
	scanf("%d", &t);
	for(int test=1; test<=t; test++){
		int n;
		scanf("%d", &n);
		for(int row=0; row<n; row++){
			for(int col=0; col<=row; col++){
				scanf("%d", &array[row][col]);
			}
		}
		for(int row=n-2; row>=0; row--){
			for(int col=0; col<=row; col++){
				array[row][col] += max(array[row+1][col], array[row+1][col+1]);
			}
		}
		printf("%d\n", array[0][0]);
	}
	return 0;
}
