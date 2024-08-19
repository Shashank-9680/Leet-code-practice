class Solution {
public:
    int numberOfSubstrings(string s) {
     int arr[3]={-1,-1,-1};
        int i=0;
        int n=s.size();
        int count=0;
        while(i<n){
            arr[s[i]-'a']=i;
            if(arr[0]>=0&&arr[1]>=0&&arr[2]>=0){
                int index=min(arr[0],min(arr[1],arr[2]));
                count+=index+1;
                cout<<count;
            }
            i++;
        }
        return count;
    }
};