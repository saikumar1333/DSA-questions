#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	string str;
	cin>>str;
	int h=count(str.begin(), str.end(), 'h');
    int e=count(str.begin(), str.end(), 'e');
    int l=count(str.begin(), str.end(), 'l');
    int o=count(str.begin(), str.end(), 'o');
    if(h>=1 and e>=1 and l>=2 and o>=1){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }

	return 0;
}