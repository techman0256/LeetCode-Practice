class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> triangle  = new ArrayList<>();

        for (int i=0; i < numRows; i++) {
            long ele = 1;
            triangle.add(new ArrayList<Integer>());
            triangle.get(i).add(1);
            for (int j=1; j < i + 1; j++) {
                long num = i + 1 - j;
                long den =  j;
                ele = (ele * num) / den;
                triangle.get(i).add((int)ele);
            }
        }

       
        return triangle;

    }
    
}