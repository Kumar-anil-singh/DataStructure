string reverseWords(string s) {
        
        int len = s.length();
        int j=0;
        //remove double space 
        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1] && s[i]==' '){
                s.erase(s.begin()+i-1);
                i--;
            }
        }
        //check at head
        if(s[0]==' '){
            s.erase(s.begin());
        }
        int n=s.size();

        //check at end
        if(s[n-1]==' '){
            s.erase(s.begin()+n-1);
            n--;
        }
        reverse(s.begin(), s.end());
        for(int i=0; i<len; i++)
        {
            if(s[i]==' ')
            {
                reverse(s.begin()+j, s.begin()+i);
                j=i+1;
            }
            else if(i == len-1)
            {
                reverse(s.begin()+j,s.end());
            }
        }
        
        return s;
    }
