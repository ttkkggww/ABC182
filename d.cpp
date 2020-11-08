#include<bits/stdc++.h>
//#include<atcoder/all>
using namespace std;
using ll = long long;

int main()
{
	int n;cin >> n;
	vector<ll> a(n),sum(n+1),summax(n+1,LLONG_MIN/2);
	for(int i = 0;i<n;i++)
	{
		cin >> a[i];
		sum[i+1]+= sum[i]+a[i];
		summax[i+1]=max(summax[i],sum[i+1]);
	}
	ll ans = 0;
	ll now = 0;
	for(int i = 0;i<n;i++){
		ans = max(ans,now+summax[i+1]);
		now += sum[i+1];
	}
	ans = max(ans,now);
	cout<<ans<<endl;
	
}
