class Solution {
public:
    set<int> primes;
    void checkPrimes() {
        vector<int> nums(101, 0);
        for (int i=2; i * i < 101; i++) {
            if (nums[i] == 0) {
                for (int j=i*i; j < 101; j+=i) {
                    nums[j] = 1;
                }
            }
        }

        for (int i=2; i < 101; i++) {
            if (nums[i] == 0) {
                primes.insert(i);
            }
        }

        for ( auto prime : primes) {
            cout << prime << " " << endl;
        }
        cout << endl;
    }
    int maximumPrimeDifference(vector<int>& nums) {
        checkPrimes();
        int n = nums.size();
        vector<int> idx;
        for (int i=0; i < n; i++) {
            if (primes.find(nums[i]) != primes.end()) {
                idx.push_back(i);
                // cout << i << endl;
            }
        }

        // return 0;
        int s = idx.size();
        return idx[s - 1] - idx[0];
    }
};