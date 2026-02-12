//111000011100011
for(int i=0;i<n;){
    int j = i;
    for(;i<n && s[i]==s[j];i++);
    //cout<<s[i]<<" "<<"長度 : "<<j-i+1<<endl;
}