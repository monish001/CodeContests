/*
http://www.codechef.com/problems/GROWGOLD 

Golden Trees
Problem code: GROWGOLD
	
SUBMITMY SUBMISSIONSALL SUBMISSIONS
All submissions for this problem are available.

Long ago there was a beautiful kingdom in the island of Sona, the golden island, deep inside Africa. The trees in Sona island are made of gold and farmers are the richest group of people and are also heavy tax payers.
As you know that price of gold increases every year, the minister of Sona has proposed the following tax policy.
Pay initTax units of gold in the first year.

In each of the next slot1 years, pay one unit of gold more than the previous year.

In each of the next slot2 years, pay double the units of gold of the previous year.

In each of the following years, pay number of gold units equal to the product of the number of units paid in K recent years.


Given an integer N, find the number of units of gold to be paid in the Nth year. This result can be huge, so output the result modulo 100000007 (108+7).
Input

First line has an integer T (number of test cases, 1 = T = 3). Each of the next T lines has 5 integers, initTax slot1 slot2 K N.
1 = initTax, slot1, slot2 = 50
1 = K = slot1 + slot2 + 1
1 = N = 1000000000 (109)
Output

For each test case, output the tax in units of gold to be paid in the Nth year modulo 100000007 (108+7).
Example

Input:
3
1 3 2 4 4
1 3 2 4 7
1 3 2 4 9

Output:
4
1536
18811834

Explanation:

Let tax[i] be the tax paid in ith year.

Init : tax[1] = 1

Next 3 years in slot1 (tax[i] = tax[i-1] + 1) : tax[2] = 2 , tax[3] = 3, tax[4] = 4

Next 2 years in slot2 (tax[i] = 2 * tax[i-1]) : tax[5] = 8 , tax[6] = 16

We have tax[1..6] = { 1, 2, 3, 4, 8, 16 }

tax[7] = tax[3] * tax[4] * tax[5] * tax[6] = 3 * 4 * 8 * 16 = 1536

tax[8] = 4*8*16*1536 = 786,432

similarly, tax[9] = 8 * 16 * 1536 * 786,432 = 18811834
tax[10] = 16*1536*786,432*18,811,834 = 84,208,956
tax[11] = 1536*786432*18811834*84208956 = 35889352
tax[12] = 786432*18811834*84208956*35889352 = 75453662
tax[13] = 18811834*84208956*35889352*75453662 = 44609468

Do not forget to print only the reminder of the result when divided by 100000007 (108+7).
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
#include <stack>
#include <queue>
#include <map>
#include <sstream>
#include <ctime>
#include <numeric>
#include <cstring>
#include <functional>
#define MOD 100000007
using namespace std;

//Class Matrix
class Matrix {
    unsigned _row, _col;
    string _name;
    int** _mat;
public:
	//default ctor
	Matrix():_row(0), _col(0),_name("UnInit"){}
	//cleans up any memory taken by _mat and allocates afresh as per row and col value.
	void init(unsigned rw, unsigned cl, const string& name="NoName"){
		//cout<<"DEBUG: In init. name="<<name<<endl;
		if(_row > 0){
			if(_col > 0){
				for(unsigned r=0; r<_row; r++)
					delete[] _mat[r];
			}
			delete[] _mat;
		}
		_name = name;
		_row = rw;
		_col = cl;
        _mat = new int*[_row]; //TODO: use exception handling
        for (unsigned r=0; r<_row; r++){
            _mat[r] = new int[_col];
			for(unsigned c=0; c<_col; c++)
				_mat[r][c] = 0;
		}
    }
	//copy ctor
    Matrix(const Matrix& mat){
		_row = 0; _col = 0; _name = "UnInit";
		init(mat._row, mat._col, "CreatedInCopyCtor");
        for (unsigned i=0; i<mat._row; i++)
            for (unsigned j=0; j<mat._col; j++)
                _mat[i][j] = mat._mat[i][j];
    }
    void operator=(const Matrix& mat){
		init(mat._row, mat._col, "Copy of "+mat._name);
        for (unsigned i=0; i<mat._row; i++)
            for (unsigned j=0; j<mat._col; j++)
                _mat[i][j] = mat._mat[i][j];
    }
	//Creates and returms mat^expo in LOG(expo) time. :)
	static Matrix* power(const Matrix& mat, unsigned expo, const int modulus) {
        //cout<<"DEBUG: Entered power\n";
        vector<Matrix*> cache;//eg. cache[0] = (mat)^1, cache[3] = (mat)^8
        Matrix* ansMat = new Matrix();
        ansMat->operator=(mat);
		expo--;//as ansMat already is assigned as mat
		Matrix* cacheMat = new Matrix(); cacheMat->operator=(mat);
        cache.push_back(cacheMat);
        //cout<<"DEBUG: cache.pushed()\n";
        //find max 2 ki power needed for finding ansMat. let it be 'count'. Ex. for expo=31 (11111), 'count' is 4.
        unsigned count = 0;
		int expoTmp = expo>>1;
		while(expoTmp){
			count++;
			expoTmp>>=1;
		}
        //cout<<"DEBUG:count = "<<count<<endl;
        for (unsigned i=1; i<=count; i++) {
            Matrix* tmpMat = new Matrix();
			tmpMat->operator=(*cache[i-1]);
			tmpMat->operator=(*(tmpMat->multiply(cache[i-1], modulus)));
            cache.push_back(tmpMat);
            //cout<<"DEBUG: cache["<<cache.size()-1<<"] created as follows:"; tmpMat->print(cout);
        }
        for (unsigned bit=0; bit<=count; bit++)
            if (1<<bit & expo) {
                //cout<<"DEBUG:bit "<<bit<<" is set.\n";
				//cout<<"DEBUG: Will call multiply with following mats:"; ansMat->print(cout); cache[bit]->print(cout);
				Matrix* tmpMat = ansMat->multiply(cache[bit], modulus);
                //cout<<"DEBUG:tmpMat create for bit "<<bit<<" as follows:"; tmpMat->print(cout);
                ansMat->operator=(*tmpMat);
                //cout<<"DEBUG:ansMat *= tmpMat DONE for bit="<<bit<<" with result:."; ansMat->print(cout);
            }
		for(unsigned i=0; i<cache.size(); i++)
			delete cache[i];
        return ansMat;
    }
    Matrix* multiply(const Matrix* mat, const int modulus) {
        assert(this->_col == mat->_row);
		assert(mat != NULL);
        Matrix* ans = new Matrix();
		ans->init(this->_row, mat->_col, "CreatedInMultiply");
        for (unsigned row=0; row<this->_row; row++)
            for (unsigned col=0; col<mat->_col; col++) {
                ans->_mat[row][col] = 0;
				//cout<<"DEBUG: In multiply, ans->_mat["<<row<<"]["<<col<<"] computed as \n";
                for (unsigned index=0; index<this->_col; index++){
					//cout<<"DEBUG:\t"<<this->_mat[row][index]<<"*"<<mat->_mat[index][col]<<endl;
                    long long tmp = ans->_mat[row][col];
					tmp += this->_mat[row][index]*(long long)(mat->_mat[index][col]);
					if(tmp >= modulus)
						ans->_mat[row][col] = tmp%modulus;
					else 
						ans->_mat[row][col] = tmp;
				}
				//cout<<"DEBUG:\t"<<ans->_mat[row][col]<<endl;
            }
        return ans;
    }	
    void setColumn(unsigned colIndex, int value) {
        for (unsigned i=0; i<_row; i++)
            _mat[i][colIndex] = value;
    }
    int& getElement(unsigned rowIndex/*1 based*/, unsigned colIndex/*1 based*/) {
        assert(rowIndex<_row);
        assert(colIndex<_col);
        return _mat[rowIndex][colIndex];
    }
    void print(ostream& cout) {
        cout<<endl;
        for (unsigned r=0; r<_row; r++) {
            for (unsigned c=0; c<_col; c++)
                cout<<_mat[r][c]<<"\t";
            cout<<endl;
        }
        cout<<endl;
	}
    ~Matrix() {
        //cout<<"DEBUG: In dtor for "<<this->_name<<endl;
        for (unsigned r=0; r<_row; r++)
            delete[] _mat[r];
        delete[] _mat;
    }
};


long long myPowMOD(const int num, const int expo){
    Matrix mat;
	mat.init(1, 1, "CreatedInMain");//inits all elems with 0;
    mat.getElement(0,0) = num;
    //cout<<"DEBUG:power("<<num<<", 1):";    mat.print(cout);
    
    Matrix* mat2 = Matrix::power(mat, expo, MOD);
    //cout<<"DEBUG:power("<<num<<", "<<expo<<"):";    mat2->print(cout);
	
	long long ans = mat2->getElement(0,0);
	delete mat2;
	return ans;
}
int findLastYearTax(unsigned expo, const vector<int>& list){
    const unsigned size = list.size();
    Matrix mat;
	mat.init(size, size, "CreatedInMain");//inits all elems with 0;
    mat.setColumn(0, 1);//sets column 0 as 1
    for (unsigned colIndex=1; colIndex<size; colIndex++)
        mat.getElement(colIndex-1,colIndex) = 1;
    //cout<<"DEBUG:power(mat, 1):";    mat.print(cout);

    Matrix* ansMat = Matrix::power(mat, expo, MOD-1);
    //cout<<"DEBUG:power(mat, "<<expo<<"):";    ansMat->print(cout);

	long long ans = 1;
	for(unsigned index=0; index<size; index++){
		ans *= myPowMOD(list[size-1-index], ansMat->getElement(index,0));
		if(ans>=MOD)
			ans %= MOD;
	}
	delete ansMat;
	return ans;
}
void solve()
{
	int initTax, s1, s2, k, n;
	cin>>initTax>>s1>>s2>>k>>n;
	int ans = initTax;
	if(n < 1+s1+s2+1){
		if(n<=s1+1)
			ans += n-1;
		else{
			ans += s1;
			n-= (s1+1);
			while(n--)
			{
				ans<<=1;
				ans = (ans>=MOD)?(ans%MOD):ans;
			}
		}
	}else{//maintain list of amount of tax paid in last k years.
		assert(k<=1+s1+s2);
		vector<int> list;
		if(k == 1+s1+s2){
			list.push_back(initTax);
			for(int i=1; i<=s1; i++)
				list.push_back(initTax+i);
		}else if(k>s2){
			for(int i=k-s2; i<=s1; i++)
				list.push_back(initTax+i);
		}
		int prevTax = initTax + s1;
		for(int years=1; years<=s2; years++){
			int curTax = prevTax<<1;
			curTax = ((curTax>=MOD)?(curTax%MOD):(curTax));
			if(s2-years+1 <= k)
				list.push_back(curTax);
			prevTax = curTax;
		}
		
		//cout<<"DEBUG:list's k elements: "; for(unsigned i=0; i<list.size(); i++) cout<<list[i]<<"\t"; cout<<endl;
		int yearsLeft = n-1-s1-s2;
		ans = findLastYearTax(yearsLeft, list);//list[size()-1] has late year tax value
	}
	//cout<<"DEBUG: ANS=";
	cout<<ans<<endl;
}
int main(){
	int tt;
	cin>>tt;
	for(int t=0; t<tt; t++)
	{
		solve();
	}
	return 0;
}
