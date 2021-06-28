#include<iostream>
#include<math.h>
using namespace std;

int largest_cont_array(int a[] , int size){
	int i,noend=0,nosofar=INT_MIN;
	//cout<<INT_MIN<<endl;//   last value of in i.e -2^31
	
	for(i=0;i<size;i++){
		noend+=a[i];
		if(nosofar<noend){
			nosofar=noend;
		}
		if(noend<0){
			noend=0;
		}
	}
	return nosofar;
}
int main(){
	int i,j,n;
	cin>>n;
	int a[n];
	for(i=0;i<n;i++)
		cin>>a[i];
	cout<<largest_cont_array(a,n);
}
