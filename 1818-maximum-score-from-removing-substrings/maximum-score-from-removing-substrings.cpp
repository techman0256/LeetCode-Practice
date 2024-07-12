class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int n = s.length();
        vector<int> vis(n, 0);

        string ans;
        int score = 0;
        if (x > y) {
            // remove as many ab's
            stack<pair<char, int>> stk;
            for (int i=0; i < n; i++) {
                if (s[i] != 'a' && s[i] != 'b') {
                    // cout <<  i << " le khali" << endl;
                    while ( !stk.empty() ) {
                        stk.pop();
                    }
                } else {
                    // cout << stk.size() << endl;
                    // cout << i << " " << (bool)( !stk.empty() ) << (bool)(s[i] == 'b') << (bool)(vis[i] == 0) << endl;
                    if (s[i] == 'a' && vis[i] == 0) {
                        stk.push( {s[i], i} );
                    } else if ( !stk.empty() && s[i] == 'b' && vis[i] == 0 ) {
                        // cout << " HI " << endl;
                        vis[stk.top().second] = 1;
                        score += x;
                        vis[i] = 1;
                        stk.pop();
                    }
                }
            }
            while ( !stk.empty() ) {
                stk.pop();
            }

            for (int i=0; i < n; i++) {
                if (s[i] != 'a' && s[i] != 'b') {
                    // stk.clear();
                    while ( !stk.empty() ) {
                        stk.pop();
                    }
                } else {
                    if (s[i] == 'b' && vis[i] == 0) {
                        stk.push( {s[i], i} );
                    } else if ( !stk.empty() && s[i] == 'a' && vis[i] == 0) {
                        vis[stk.top().second] = 1;
                        score += y;
                        vis[i] = 1;
                        stk.pop();
                    }
                }
            }
            
        } else {
            stack<pair<char, int>> stk;
            for (int i=0; i < n; i++) {
                if (s[i] != 'a' && s[i] != 'b') {
                    // stk.clear();
                    while ( !stk.empty() ) {
                        stk.pop();
                    }
                } else {
                    if (s[i] == 'b' && vis[i] == 0) {
                        stk.push( {s[i], i} );
                    } else if ( !stk.empty() && s[i] == 'a' && vis[i] == 0) {
                        vis[stk.top().second] = 1;
                        score += y;
                        vis[i] = 1;
                        stk.pop();
                    }
                }
            }

            while ( !stk.empty() ) {
                stk.pop();
            }

            // stack<pair<char, int>> stk;
            for (int i=0; i < n; i++) {
                if (s[i] != 'a' && s[i] != 'b') {
                    // cout <<  i << " le khali" << endl;
                    while ( !stk.empty() ) {
                        stk.pop();
                    }
                } else {
                    // cout << stk.size() << endl;
                    // cout << i << " " << (bool)( !stk.empty() ) << (bool)(s[i] == 'b') << (bool)(vis[i] == 0) << endl;
                    if (s[i] == 'a' && vis[i] == 0) {
                        stk.push( {s[i], i} );
                    } else if ( !stk.empty() && s[i] == 'b' && vis[i] == 0 ) {
                        // cout << " HI " << endl;
                        vis[stk.top().second] = 1;
                        score += x;
                        vis[i] = 1;
                        stk.pop();
                    }
                }
            }



        }


        cout << score << endl;
        return score;
    }
};