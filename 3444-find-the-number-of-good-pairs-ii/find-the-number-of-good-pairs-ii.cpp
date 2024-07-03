class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();

        int maxi = *max_element(nums1.begin(), nums1.end());
        // sort(nums1.begin(), nums1.end());
        // sort(nums2.begin(), nums2.end());

        map<long long, long long> mpp;
        map<long long, long long> divs;
        for (int i=0; i < n; i++) {
            mpp[nums1[i]]++;
        }
        for (int i=0; i < m; i++) {
            divs[nums2[i]]++;
        }

        long long pairs = 0;

        for ( auto i = divs.begin(); i != divs.end(); i++) {
            long long cnt = i->second;
            long long div = i->first;
            long long checkTill = maxi / (div * k);
            // cout << c

            for (int j=1; j <= checkTill; j++) {
                long long x = div * j * k;
                if (mpp.find(x) != mpp.end()) {
                    pairs += mpp[x] * cnt;
                } 
            }
        }

        return pairs;
    }
};