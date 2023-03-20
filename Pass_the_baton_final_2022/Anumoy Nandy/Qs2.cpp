#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int n;
    cin>>n;
    
    vector<int>a(n);
    
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    int maxLen=0;
    
    for(int i=0;i<n;i++){
        
        unordered_map<int,int>mp;
        
        for(int j=0;j<i;j++){
            mp[a[j]]++;
        }
        
             bool flag=true;
            
            int prev=-1;
            
        
            for(auto itr:mp){
                if(itr.second!=0){
                    prev=itr.second;
                    break;
                }
            }
            
            for(auto itr:mp){
                if(itr.second!=prev){
                    flag=false;
                    break;
                }
            }
            
            if(flag==true && prev!=-1){
                maxLen=max(maxLen,i+1);
            }
        
        for(int j=i+1;j<n;j++){
            
            mp[a[j]]++;
            
            bool flag=true;
            
            int prev=-1;
            
            for(auto itr:mp){
                if(itr.second!=0){
                    prev=itr.second;
                    break;
                }
            }
            
            for(auto itr:mp){
                if(itr.second!=prev){
                    flag=false;
                    break;
                }
            }
            
            if(flag==true){
                maxLen=max(maxLen,j+1);
            }
            
        }
        
        
    }
    
    cout<<maxLen<<endl;
        
    
    return 0;
    
}
