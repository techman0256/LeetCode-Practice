#define ll long long

class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();

        priority_queue<ll> pq;
        priority_queue<ll, vector<ll>, greater<ll>> pqm;
        for (int i=1; i < n; i++) {
            pq.push(weights[i] + weights[i - 1]);
            if (pq.size() > k - 1) {
                pq.pop();
            }
            pqm.push(weights[i] + weights[i - 1]);
            if (pqm.size() > k - 1) {
                pqm.pop();
            }
        }

        ll max = 0;
        ll min = 0;
        // ll cnt = 0;
        while ( !pq.empty() ) {
            max += pq.top();
            min += pqm.top();
            cout << pq.top() << " " << pqm.top() << endl;
            cout << min << " " << max << endl;
            pq.pop();
            pqm.pop();
            // cnt++;
        }

        return abs(min - max);
    }
};