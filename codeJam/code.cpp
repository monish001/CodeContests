#include<fstream>
#include<algorithm>
using namespace std;
int gcd(int a, int b)
{
		if( a == 0 )
			return b;

        if( b == 0 )
			return a;
    while( 1 )
    {
        a = a % b;
		if( a == 0 )
			return b;
		b = b % a;

        if( b == 0 )
			return a;
    }
}

int main(){
	int t;
	ofstream cout("out.txt");
	ifstream cin("in.txt");
	cin>>t;
	for(int test=1; test<=t; test++){
		long long int n;
		int pd, pg;
		cin>>n>>pd>>pg;
		string ans("Broken");
		if(pg==100){
			if(pd==100)
				ans = "Possible";
			else
				;
		}else{
			int k = 100/gcd(pd, 100-pd);
			/*if(k * gcd(pd, 100-pd) != 100)
				ans == "Broken";
			else */for(long long int i=min(n, 100LL); i>=1; i--){
				if(i%k==0 || i==k==1){
					ans = "Possible";
					break;
				}
			}
		}
		cout<<"Case #"<<test<<": "<<ans<<endl;
	}
	return 0;
}
