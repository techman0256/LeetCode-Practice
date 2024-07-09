class Solution {
public:
    static bool compare(vector<int> a, vector<int> b) {
        if (a[0] == b[0]) {
            return a[1] < b[1];
        }

        return a[0] < b[0];
    }
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();

        // sort(customers.begin(), customers.end(), compare);

        long time = customers[0][0];
        long waitTime = 0;
        for (int i=0; i < n; i++) {
            if (time < customers[i][0]) {
                time += (customers[i][0] - time);
            }
             time += customers[i][1];
            // cout << time << endl;
            waitTime += time - customers[i][0];
            cout << waitTime << endl;


            
        }

        cout << waitTime << endl;

        return (double)(waitTime) / n;



    }
};