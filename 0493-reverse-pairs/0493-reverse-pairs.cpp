// class Solution {
// public:
// void merge(vector<int>&arr,int s,int m,int e){
//     // merge the two sorted subarrays arr[s...m]  and arr[m+1...e]
//     //such that arr[s..e] becomes sorted  
//   vector<int>temp(e-s+1);
//    int i=s;
//    int j=m+1;
//    int k=0;

//    while(i<=m and j<=e){
//     if(arr[i]<arr[j]){
//         temp[k]=arr[i];
//         i++;
//         k++;
//     }
//     else{
//         temp[k]=arr[j];
//         j++;
//         k++;

//     }
//    }
//    while(i<=m){
//     temp[k]=arr[i];
//     i++;
//     k++;
//    }
//    while(j<=e){
//     temp[k]=arr[j];
//     j++;
//     k++;
//    }
//    for (int k = 0; k < temp.size(); k++) {
//             arr[s + k] = temp[k];
//         }
// }
// int countpairs(vector<int>&nums,int low,int mid,int high){
//     int count=0;
//     int right=mid+1;
//     for(int i=low;i<=mid;i++){
//         while(right<=high and nums[i]>2*nums[right]) right++;
//         count+=(right-(mid+1));
//     }
//     return count;
// }
//    int mergesort(vector<int>&nums,int st,int end){
//     int cnt=0;
//     int mid=st+(end-st)/2;
//     if(st==end){
//         return 0;
//     }
//     cnt+=mergesort(nums,st,mid);
//     cnt+=mergesort(nums,mid+1,end);
//     cnt+=countpairs(nums,st,mid,end);

//     merge(nums,st,mid,end);

//     return cnt;


//    }
//     int reversePairs(vector<int>& nums) {
//         int n=nums.size();
//        return mergesort(nums,0,n-1);
//     }
// };







class Solution {
public:
    void merge(vector<int>& arr, int s, int m, int e) {

        vector<int> temp(e - s + 1);
        int i = s;
        int j = m + 1;
        int k = 0;  // FIXED: temp index should start at 0

        while (i <= m && j <= e) {
            if (arr[i] < arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
            }
        }

        while (i <= m) temp[k++] = arr[i++];
        while (j <= e) temp[k++] = arr[j++];

        // copy back
        for (int t = 0; t < temp.size(); t++) {
            arr[s + t] = temp[t];
        }
    }

    int countpairs(vector<int>& nums, int low, int mid, int high) {
        int count = 0;
        int right = mid + 1;

        for (int i = low; i <= mid; i++) {
            while (right <= high && (long long)nums[i] > 2LL * nums[right])
                right++;
            count += (right - (mid + 1));
        }
        return count;
    }

    int mergesort(vector<int>& nums, int st, int end) {
        if (st == end) return 0;

        int mid = st + (end - st) / 2;
        int cnt = 0;

        cnt += mergesort(nums, st, mid);
        cnt += mergesort(nums, mid + 1, end);
        cnt += countpairs(nums, st, mid, end);
        merge(nums, st, mid, end);

        return cnt;
    }

    int reversePairs(vector<int>& nums) {
        return mergesort(nums, 0, nums.size() - 1);
    }
};
