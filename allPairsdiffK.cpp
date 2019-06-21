#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
    //cout << "Hello world!" << endl;
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll a[n+2];
        map<ll,ll>mp;
        for(ll i=0;i<n;i++)
        {
            cin>>a[i];
            mp[a[i]]++;
        }

        ll k;
        cin>>k;

        ll cnt=0;
        for(ll i=0;i<n;i++)
        {
            if(k==0)
            {
                ll x=mp[a[i]];
                ll sz=(x*(x-1))/2;
               // cout<<sz;
                if(sz!=0) cnt++;
                //for(ll j=0;j<sz;j++)
                  //  cout<<a[i]<<" "<<a[i]<<endl;
            }
            else{

               ll x1=mp[a[i]-k];
               ll x2=mp[a[i]+k];
               ll x3=mp[a[i]];

                if(x1*x3!=0) cnt++;
                if(x2*x3!=0) cnt++;

                //for(ll j=0;j<x1*x3;j++)
                  //  cout<<a[i]-k<<" "<<a[i]<<endl;

                //for(ll j=0;j<x3*x2;j++)
                  //  cout<<a[i]+k<<" "<<a[i]<<endl;
            }

            mp.erase(a[i]);
        }
        mp.clear();
        cout<<cnt<<endl;
    }


    return 0;
}
