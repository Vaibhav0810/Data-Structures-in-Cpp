
int minDeletions(string str, int n) { 
    
    int dp[n+1][n+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<=n;j++){
            if(i==0 || j==0) dp[i][j]=0;
        }
    }
    string rev=str;
    reverse(rev.begin(),rev.end());
    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            if(str[i-1]==rev[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return n-dp[n][n];
