#include<bits/stdc++.h>
using namespace std;
int main()
{
    
    vector<int>v;
    while(true)
    {
        int val;
        cin>>val;
        if(val==-1) break;
        v.push_back(val);
    }
  
    sort(v.begin(),v.end());
    auto it =unique(v.begin(),v.end());
    v.erase(it , v.end());
   

    for(int x: v)
    {
        cout<<x<<" ";
    }
      
    return 0;
}