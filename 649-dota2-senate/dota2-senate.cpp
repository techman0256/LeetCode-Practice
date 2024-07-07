class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        int R = 0;
        int D = 0;

        deque<int> radiant;
        deque<int> dire;
        vector<int> banned(n, 0);

        for ( int i=0; i < n; i++) {
            if (senate[i] == 'R') {
                R++;
                radiant.push_back(i);
            } else {
                D++;
                dire.push_back(i);
            }
        }
        int i = 0;
        // cout << R << " " << D << endl;
        while (R != 0 && D != 0) {
            // cout << " HI " << endl;
            if (senate[i % n] == 'R' && banned[i % n] == 0) {
                banned[dire.front() % n] = 1;
                dire.pop_front();

                radiant.pop_front();
                radiant.push_back(i + n);
                D--;
            } else if (senate[i % n] == 'D' && banned[i % n] == 0) {
                banned[radiant.front() % n] = 1;
                radiant.pop_front();

                dire.pop_front();
                dire.push_back(i + n);
                R--;
            }

            if  (R == 0 || D == 0) break;
            i = min(dire.front(), radiant.front());
        }

        if (R == 0) {
            return "Dire";
        } 
        return "Radiant";

    }
};