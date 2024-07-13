#define ll long long
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> copy(n, 0);
        map<int, int> mpp;

        for (int i=0; i < n; i++) {
            mpp[positions[i]] = i;
            copy[i] = positions[i];
        }
        sort(positions.begin(), positions.end());

        stack<int> stk;
        for ( auto pos : positions) {
            if ( directions[mpp[pos]] == 'R' ) {
                stk.push( pos );
                // cout << stk.top().first << " " << stk.top().second << endl;
            } else {

                while ( !stk.empty() && healths[mpp[pos]] > healths[mpp[stk.top()]]) {
                    healths[mpp[pos]]--;
                    healths[mpp[stk.top()]] = 0;
                    stk.pop();
                }

                if ( !stk.empty() && healths[mpp[pos]] < healths[mpp[stk.top()]] ) {
                    healths[mpp[pos]] = 0;
                    healths[mpp[stk.top()]]--;
                }
                else if ( !stk.empty() && healths[mpp[pos]] == healths[mpp[stk.top()]] ) {
                    healths[mpp[pos]] = 0;
                    healths[mpp[stk.top()]] = 0;
                    stk.pop();
                }
            }
        }
        // vector<pair, 
        vector<int> ans;
        for ( int i=0; i < n; i++ ) {
            // cout << pos << endl;
            if ( healths[i] > 0 ) {
                ans.push_back(healths[i]);
                // cout << copy[i] << endl;
            }
        }

        return ans;
    }
};