class Solution {
    public String reverseWords(String s) {
        String answer = "";

        // int start = s.length();
        int end = s.length() - 1;
        int i=s.length() - 1;
        while (i >= 0) {
            if (s.charAt(i) == ' ') {
                if (answer.length() != 0) {
                    answer += " ";
                }
                answer += s.substring(i + 1, end + 1);
                System.out.println(i + 1 + " " + end);
                while (i >= 0 && s.charAt(i) == ' ') {
                    i--;
                }
                end = i;
                i++;
            }
            i--;
        }
        // end = i;
        System.out.println(end);
        if (end >= 0 && answer.length() != 0) {
            answer += " ";
        }
        answer += s.substring(i + 1, end + 1);

        return answer;
    }
}