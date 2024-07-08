class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> circle;
        for (int i=1; i <= n; i++) {
            circle.push(i);
        }

        if ( circle.size() == 1 ) {
            return circle.front();
        }

        int i = 1;
        while ( true ) {
            int next = i;
            int cnt = 1;
            while (cnt != k) {
                next = circle.front();
                circle.pop();
                circle.push(next);
                // if ( next == i ) {
                //     continue;
                // } else {
                // }
                cnt++;
            }
            circle.pop();


            if (circle.size() == 1) {
                break;
            }
        }

        return circle.front();
    }
};