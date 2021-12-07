#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;

string removeDuplicates(string str) {
	    // code here
	    unordered_set<char> S;
	    string res="";
	    int len=str.length();
	    for(int i=0; i<len; i++)
	    {
	        char c = str[i];
	        if(S.find(c) == S.end())
	        {
	            res = res + c;
	            S.insert(c);
	        }
	    }
	    return res;
	}
	
int main()
{
	string str = "GeeksforGeeks";
	string res = removeDuplicates(str);
	cout<<res<<endl;
}
