//111000011100011
for(int i=0;i<n;){
    int j = i;
    for(;j<n && s[i]==s[j];j++);
    //cout<<s[i]<<" "<<"長度 : "<<j-i+1<<endl;
    i = j;
}