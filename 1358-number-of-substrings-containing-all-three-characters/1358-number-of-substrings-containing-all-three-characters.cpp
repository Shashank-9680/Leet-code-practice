class Solution {
public:
    int numberOfSubstrings(string s) {
        int i=0;
     int arr[3]={-1,-1,-1};
       int count=0;
        while(i<s.size()){
             arr[s[i]-'a']=i;
              
            if(arr[0]>-1&&arr[1]>-1&&arr[2]>-1){
               int minimum1=min(arr[0],arr[1]);
                int minimum=min(minimum1,arr[2]);
                // cout<<minimum;
                cout<<count;
                count=count+minimum+1;   
            }
              i++;
            
               
        }
        return count;
    }
};