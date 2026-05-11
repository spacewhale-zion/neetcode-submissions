class Solution {
    private int helper(String s, int i, int j, int[][] dp){
        if(i>j)return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s.charAt(i)==s.charAt(j)){
            return dp[i][j]=helper(s,i+1,j-1,dp);
        }else return dp[i][j]=0;
    }
    public int countSubstrings(String s) {
        int m = s.length();
        int[][] dp = new int[m][m];
        for(int[] row : dp)Arrays.fill(row,-1);
        int cnt = 0;
        for(int i = 0; i<m; i++){
            for(int j = i; j<m;j++){
                cnt+=helper(s,i,j,dp);
            }
        }
        return cnt;
    }
}
