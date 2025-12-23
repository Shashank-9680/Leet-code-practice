class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int largest =arr[0];
        for(int i=0;i<arr.size();i++){
            if(arr[i]>largest){
                largest =arr[i];
            }
        }
        int sndlargest= -1;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>sndlargest && arr[i]<largest){
                sndlargest = arr[i];
            }
        }
        return sndlargest;
    }
};