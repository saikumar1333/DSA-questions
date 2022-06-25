#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t,d,a,b;
    cin>>t;
	for(int i=0;i<t;i++){
	    cin>>d>>a>>b;

	   
	}
	while(t>0){
	 if(a+b>d and abs(a-b)<d){
	        cout<<"2"<<endl;
	    }
	    if(a+b==d or abs(a-b)==d){
	        cout<<"1"<<endl;
	    }
	    if(d=0 or a+b<d ){
	        cout<<"0"<<endl;
	    }
        t--;
	}
	return 0;
}