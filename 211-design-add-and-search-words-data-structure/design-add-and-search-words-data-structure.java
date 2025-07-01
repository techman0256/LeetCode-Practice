class TrieNode {
    TrieNode links[] = new TrieNode[26];
    boolean flag = false;

    boolean containsKey(char ch) {
        return links[ch - 'a'] != null;  
    }

    void put(char ch, TrieNode node) {
        links[ch - 'a'] = node;
    }

    TrieNode get(char ch) {
        return links[ch - 'a'];
    }

    void setEnd() {this.flag = true;}
    boolean isEnd() {return flag;}
}
class WordDictionary {
    private static TrieNode root;
    public WordDictionary() {
        root = new TrieNode();
    }
    
    public void addWord(String word) {
        TrieNode node = root;
        for (int i=0; i < word.length(); i++) {
            if (!node.containsKey(word.charAt(i))) {
                node.put(word.charAt(i), new TrieNode());
            }
            node = node.get(word.charAt(i));
        }

        node.setEnd();
    }
    
    public boolean search(String word) {
        return search(word, WordDictionary.root);
    }
    public boolean search(String word, TrieNode node) {
        if (word == "*") return true;

        for (int i=0; i < word.length(); i++) {
            if (word.charAt(i) == '.') {
                boolean match = false;
                for (int ch=0; ch < 26; ch++) {
                    if (node.links[ch] != null) {
                        match = match || search(word.substring(i + 1), node.links[ch]);
                        if (match == true) return match;
                    }
                }
                return match;
            } else if (node.containsKey(word.charAt(i))) {
                node = node.get(word.charAt(i));
            } else {
                return false;
            }
        }

        return node.isEnd();
    }
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * boolean param_2 = obj.search(word);
 */