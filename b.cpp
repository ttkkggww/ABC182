#include<bits/stdc++.h>
//#include<atcoder/all>
using namespace std;
using ll = long long;

int main()
{
	int n;cin >> n;
	vector<int> a(n);
	for(auto &i:a)cin >> i;
	ll ans = 0;
	ll cnt = 0;
	for(ll i = 2;i<= 1000;i++){
		int now = 0;
		for(auto &j:a)if(j%i==0)now++;
		if(now>cnt)ans = i,cnt = now;
	}
	cout<<ans<<endl;
}
