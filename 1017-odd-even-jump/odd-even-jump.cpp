class Solution {
public:
    vector<int> next_greater(vector<int> &arr) {
        int n = arr.size();
        vector<int> ans(n, 0);
        stack<int> stk;

        for (int i=n - 1; i >=0; i--) {
            while ( !stk.empty() && arr[stk.top()] < arr[i] ) {
                stk.pop();
            }

            if ( stk.empty()) { 
                ans[i] = -1;           
            } else {
                ans[i] = stk.top();
            }
            stk.push(i);
        }

        for (int i=0; i < n; i++) {
            cout << ans[i] << " " ;
        }
        cout << endl;
        return ans;
    }

    vector<int> next_smaller(vector<int> &arr) {
        int n = arr.size();
        vector<int> ans(n, 0);
        stack<int> stk;

        for (int i=n - 1; i >=0; i--) {
            while ( !stk.empty() && arr[stk.top()] > arr[i] ) {
                stk.pop();
            }

            if ( stk.empty()) { 
                ans[i] = -1;           
            } else {
                ans[i] = stk.top();
            }
            stk.push(i);
        }

        for (int i=0; i < n; i++) {
            cout << ans[i] << " " ;
        }
        cout << endl;

        return ans;
    }
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();
        // vector<int> nge = next_greater(arr);
        // vector<int> nse = next_smaller(arr);

        vector<int> nge(n, -1), nse(n, -1);
        vector<pair<int, int>> sort_by_value;
        stack<int> st;
        for(int i = 0; i < n; i++){
            sort_by_value.push_back({arr[i], i});
        }
        sort(sort_by_value.begin(), sort_by_value.end());
        for(auto [a, i] : sort_by_value){
            while(!st.empty() && st.top() < i){
                nge[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        st = stack<int>();
        for(int i = 0; i < n; i++){
            sort_by_value[i] = {-arr[i], i};
        }
        sort(sort_by_value.begin(), sort_by_value.end());
        for(auto [a, i] : sort_by_value){
            while(!st.empty() && st.top() < i){
                nse[st.top()] = i;
                st.pop(); 
            }
            st.push(i);
        }

        
        vector<vector<int>> dp( n, vector<int> (2, 0) );
        dp[n - 1][0] = 1;
        dp[n - 1][1] = 1;


        for (int i=n - 2; i >= 0; i--) {
            for ( int j=0; j < 2; j++) {
                if (j == 0) {
                    // cout << nge[i] <<  " ";
                    if (nge[i] != -1) {
                        dp[i][j] = dp[nge[i]][1];
                    }
                } else if (j == 1) {
                    // cout << nse[i] << " ";
                    if (nse[i] != -1) {
                        dp[i][j] = dp[nse[i]][0];
                    }
                }
                // cout << endl;
            }
        }

        int cnt = 0;
        for (int i=0; i < n; i++) {
            cout << dp[i][0] << " " << dp[i][1] << endl;
            if (dp[i][0] == 1) {
                cnt++;
            } 
            // else if (nge[i] != -1)
            // for (int j=0; j < 2; j++) {
            //     if (dp)
            // }
        }


        return cnt;
    }
};