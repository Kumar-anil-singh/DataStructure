#include<iostream>
#include<unordered_set>
using namespace std;

int findLongestSubstring(string s) 
{
	int left=0,right=0,max=0;
	int len = s.length();
	unordered_set<char> Set;
	while(right < len)
	{
		char c = s[right];
		if(Set.find(c) == Set.end())
		{
			Set.insert(c);
			max = std::max(max, (right-left)+1);
			right++;		
		}
		else
		{
			while(s[left] != c)
			{
				Set.erase(s[left]);
				left++;
			}
			Set.erase(s[left]);
			left++;
		}
	}  
	return max; 
}

int main()
{
    string str = "abbcdafeegh";
 
    cout << findLongestSubstring(str);
 
    return 0;
}
