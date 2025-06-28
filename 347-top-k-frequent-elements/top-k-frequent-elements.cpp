class Solution {
public:
    struct comparator {
        bool operator()(pair<int, int>& a, pair<int, int> &b) {
            return a.second < b.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hashTable;

        for (int i=0; i < nums.size(); i++) {
            hashTable[nums[i]] += 1;
        }

        priority_queue<pair<int,int>, vector<pair<int, int>>, comparator> pq;
        for (auto [key, value] : hashTable) {
            pq.push({key, value});
        }

        vector<int> answer;
        while (k > 0) {
            answer.push_back(pq.top().first);
            pq.pop();
            k--;
        }

        return answer;
    }
};