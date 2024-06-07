class Solution {
    public String replaceWords(List<String> dictionary, String sentence) {
        HashSet<String> dict = new HashSet<String>();
        for (int i=0; i < dictionary.size(); i++) {
            dict.add(dictionary.get(i));
        }
        String currWord = "";
        String ans = "";
        int i=0; 

        while (i < sentence.length()) {
            if (sentence.charAt(i) == ' ') {
                ans += currWord + " ";
                currWord = "";
                i++;
            } else {
                currWord += sentence.charAt(i);
                if (dict.contains(currWord)) {
                
                    while (i < sentence.length() && sentence.charAt(i) != ' ' ) {
                        i++;
                    }
                } else {
                    i++;
                }
            }
        }

        ans += currWord;

        return ans;


        // for (int i=0; i < sentence.length(); i++) {
        // }
    }
}