/*
Transform the Expression
Problem code: ONP
	
SUBMITALL SUBMISSIONS
All submissions for this problem are available.

Reverse Polish Notation (RPN) is a mathematical notation where every operator follows all of its operands. For instance, to add three and four, one would write "3 4 +" rather than "3 + 4". If there are multiple operations, the operator is given immediately after its second operand; so the expression written "3 - 4 + 5" would be written "3 4 - 5 +" first subtract 4 from 3, then add 5 to that.
Transform the algebraic expression with brackets into RPN form.
You can assume that for the test cases below only single letters will be used, brackets [] will not be used and each expression has only one RPN form (no expressions like a*b*c)
Input

The first line contains t, the number of test cases (less then 100).
Followed by t lines, containing an expression to be translated to RPN form, where the length of the expression is less then 400.
Output

The expressions in RPN form, one per line.
Example

Input:
3
(a+(b*c))
((a+b)*(z+x))
((a+t)*((b+(a+c))^(c+d)))

Output:
abc*+
ab+zx+*
at+bac++cd+^*
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

int main(int argc, char *argv[]) {
	int t;
	cin>>t;
	for(int test=1; test<=t; test++){
		string str;
		cin>>str;
		stack<string> operators, operands;
		str = '(' +str + ')';
		for(int i=0; i<str.size(); i++){
			char c = str[i];
			if((c>='a' && c<='z') || (c>='A' && c<='Z')){
				operands.push(string(1,c));//make it string if needed
			}else if(c == ')'){
				string poped;
				while((poped = operators.top()) != "("){
					string op2 = operands.top(); operands.pop(); 
					string op1 = operands.top(); operands.pop(); 
					operands.push(op1 + op2 + operators.top());
					operators.pop();
				}
				operators.pop();
			}else{
				operators.push(string(1,c));
			}
		}
		cout<<operands.top()<<endl;
	}
	return 0;
}
