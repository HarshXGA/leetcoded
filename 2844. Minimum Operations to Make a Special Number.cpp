class Solution {
public:
    int minimumOperations(string num) {
        reverse(num.begin(),num.end());
        
        int i=0,j=0;
        int ans=0;
        string num1=num;
        int ans1=0;
        
        while(num.size()>0 && num[i]!='0')
        {
            num.erase(num.begin(),num.begin()+1);
            ans++;
        }
        
        while(num1.size()>0 && num1[j]!='5')
        {
            num1.erase(num1.begin(),num1.begin()+1);
            ans1++;
        }
        
        cout<<"num: "<<num<<" ans: "<<ans<<" num1: "<<num1<<" ans1: "<<ans1<<endl;
        
        if(num.size()>1 && num[i]=='0')
        {
            i++;
            while(num.size()>1 && num[i]!='0' && num[i]!='5')
            {
                num.erase(num.begin(),num.begin()+1);
                ans++;
            }
        }
        
        if(num1.size()>1 && num1[j]=='5')
        {
            j++;
            while(num1.size()>1 && num1[j]!='2' && num1[j]!='7')
            {
                num1.erase(num1.begin(),num1.begin()+1);
                ans1++;
            }
            
        }  
        
        if(num1.size()==1)
            ans1+=1;
        
        return ans1>ans?ans:ans1;
    }
};
