// class Solution {
// public:
//     int totalhours(vector<int>&v,int hourly){
//         int n=v.size();
//         long long totalhour=0;
//         for(int i=0;i<n;i++){
//             // totalhour+=ceil((double)(v[i])/(double)(hourly));
//          totalhour += (v[i] + hourly - 1) / hourly;

//         }
//     return totalhour;
//     }
//     int minEatingSpeed(vector<int>& piles, int h) {
//         long long low=1,high= *max_element(piles.begin(), piles.end());
//         long ans=high;
//                 // apply binary search 
//         while(low<=high){
//            long long  mid=low + (high - low) / 2;

//             long long totalH=totalhours(piles,mid);
//             if(totalH<=h){
//             ans=mid;
//             high=mid-1;
//             }
//             else{
//                 low=mid+1;
//             }
            

//         }
        
//     return ans;
//     }
// };




class Solution {
public:
    // Function to calculate total hours required to finish all piles at a given speed
    long long totalhours(const vector<int>& piles, long long hourly) {
        long long totalhour = 0;
        for (int pile : piles) {
            // Calculate hours required to finish this pile at 'hourly' speed
            totalhour += (pile + hourly - 1) / hourly;  // Equivalent to ceil(pile / hourly)
        }
        return totalhour;
    }

    // Function to find the minimum eating speed
    int minEatingSpeed(vector<int>& piles, int h) {
        // Initialize binary search range
        long long low = 1;
        long long high = *max_element(piles.begin(), piles.end());
        long long ans = high;  // Start with the maximum possible speed (largest pile size)

        // Perform binary search
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long totalH = totalhours(piles, mid);

            if (totalH <= h) {
                ans = mid;  // Found a valid speed, but try to minimize it
                high = mid - 1;  // We try smaller speeds
            } else {
                low = mid + 1;  // Speed is too slow, try larger speeds
            }
        }

        return ans;
    }
};
