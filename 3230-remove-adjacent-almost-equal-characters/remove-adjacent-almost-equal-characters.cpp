class Solution {
public:
    bool almostEqual(int a, int b) {
        return abs(a - b) <= 1;
    }
    int removeAlmostEqualCharacters(string word) {
        int n = word.length();
        int ops = 0;
        
        int i = 0;
        for (i=1; i < n; i++) {
            if (almostEqual(word[i], word[i - 1])) {
                // word[i] = '#';
                ops++;
                i++;
            }

        }
       
        return ops;


        // int cnt = 0 ;
        // for(int i = 1 ; i< word.size(); i++){
        //     if(abs(word[i]-word[i-1]) <=1){
        //         cnt++;
        //         word[i]=(word[i]-'a'+2);
        //     }
        // }
        // return cnt ; 


    }
};