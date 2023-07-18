char * countAndSay(int n){
    char ans[100000];
    ans[0]='1';
    for(int i=1;i<n;i++) {
        char temp[100000];
        int index=0,count=1;
        for(int j=0;j<strlen(ans);j++) {
            if(ans[j]==ans[j+1]) count++;
            else {
                temp[index]=count+'0';
                temp[index+1]=ans[j];
                count=1;
                index+=2;
            }
        }
        strcpy(ans,temp);
    }
    for(int i=0;i<strlen(ans);i++) printf("%c",ans[i]);
    return ans;
}
