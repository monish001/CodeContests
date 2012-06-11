/*
Small factorials
Problem code: FCTRL2
	
SUBMITMY SUBMISSIONSALL SUBMISSIONS
All submissions for this problem are available.

A tutorial for this problem is available here
You are asked to calculate factorials of some small positive integers.
Input

An integer t, 1<=t<=100, denoting the number of testcases, followed by t lines, each containing a single integer n, 1<=n<=100.
Output

For each integer n given at input, display a line with the value of n!
Example

Sample input:
4
1
2
5
3
Sample output:
1
2
120
6
*/
import java.util.ArrayList;
import java.math.BigInteger;
public class Main{
	public static void main(String args[]) throws java.lang.Exception
	{
		ArrayList<BigInteger> list = new ArrayList<BigInteger>();
		list.add(BigInteger.ONE);
		for(int i=1; i<=100; i++){
			list.add(list.get(i-1).multiply(new BigInteger((new Integer(i)).toString())));
		}
		
		java.io.BufferedReader r = new java.io.BufferedReader(new java.io.InputStreamReader(System.in));
		int t = Integer.parseInt(r.readLine());
		for(int test=0; test<t; test++){
			int ii = Integer.parseInt(r.readLine());
			System.out.println(list.get(ii));
		}
		
//		String s;
//		while(!(s=r.readLine()).startsWith("42")) System.out.println(s);
		
	}
}