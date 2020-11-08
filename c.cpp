#include<bits/stdc++.h>
//#include<atcoder/all>
using namespace std;
using ll = long long;

int main()
{
	string s;
	cin >> s;
	int n = s.size();
	ll b=  atoll(s.c_str());
	int ans = n;
	if(b%3==0){
		ans = min(0,ans);
	}
	for(int i =0;i<n;i++)
	{
		if(n==1)continue;
		string t;
		for(int j = 0;j<n;j++){
			if(j==i)continue;
			t.push_back(s[j]);
		}
		ll c = atoll(t.c_str());
		if(c%3==0){
			ans = min(ans,1);
		}
		if(n==2)continue;
		for(int j = i+1;j<n;j++)
		{
			string t;
			for(int k = 0;k<n;k++){
				if(i==k||j==k)continue;
				t.push_back(s[k]);
			}
			ll a = atoll(t.c_str());
			if(a%3==0){
				ans = min(ans,2);
			}
		}
	}

	if(ans == n)cout<<-1<<endl;
	else cout<< ans << endl;
}
