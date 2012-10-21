/*
A Prime Conjecture
Problem code: PRIMES2

SUBMITMY SUBMISSIONSALL SUBMISSIONS
All submissions for this problem are available.

Chef has been exploring prime numbers lately, and has recently made a conjecture resembling one of Goldbach's conjectures. Chef's conjecture is that any odd number greater than 61 can be expressed as the sum of a prime, a square of a prime, and a cube of a prime. He wants you to help verify his conjecture for small numbers.
Note: negative numbers are never considered to be prime, nor are 0 and 1.
Input

Input will consist of a series of odd numbers greater than 61 and less than 106, one per line, terminated by the number 0 on a line by itself. There will be at most 1000 lines.
Output

For each odd number in the input, print 3 primes P1, P2, P3 on a line, where P1 + P22 + P33 is equal to the number from the input. If no such primes exist, print "0 0 0" instead (quotes for clarity). If there are multiple triplets of primes that satisfy the equation, print any such triplet.
Sample Input

81
85
155
0
Sample Output

5 7 3
73 2 2
5 5 5
*/
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>
#include<map>
#include<cmath>
#include<cstdlib>
#define OneM 1000000
using namespace std;
class set{
    public:
    set():num1(0), num2(0), num3(0){}
	void edit(int i, int j, int k){
        num1 = i; num2=j; num3=k;
	}
	int num1, num2, num3;
	void print(){
		cout<<num1<<" "<<num2<<" "<<num3<<endl;
	}
};

int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73,
79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163,
 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251,
 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349,
 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443,
 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557,
 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647,
 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757,
 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863,
 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983,
 991, 997};

inline bool isPrime(int num){
	if(num<2)
		return false;
    int sqrt_num = sqrt(num);
	for(int i=2; i<=sqrt_num; i++)
		if(num%i==0)
			return false;
	return true;
}
int main(){

	int n;
	cin>>n;
//    cout<<'a'<<endl;
	while(n){
        set ans;
	    bool searching = true;

        for(int ind=0; ind<25 && searching; ind++){
            int i=prime[ind], i3 = i*i*i;
            if(i3<n)
            for(int ind2=0; ind2<168; ind2++){
                int j=prime[ind2], j2=j*j, k=n-j2-i3;
				if(i3+j2<n && isPrime(k)){
					ans.edit(k,j,i);
					searching = false;
					break;
				}
			}
		}
        ans.print();
        cin>>n;
	}
//    cout<<"Done Input";
	return 0;
}


