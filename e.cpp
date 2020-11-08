#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using ll = long long;

ll G[1501][1501],GB[1501][1501];
vector<ll> yoko[1501],tate[1501];
vector<ll> A,B;

int main()
{
	ll h,w,n,m;
	cin >> h >> w >> n >> m;
	for(ll i = 0;i<n;i++)
	{
		ll x,y;
		cin >> x >> y;
		x--;y--;
		G[0][y]++;
		G[0][y+1]--;
		G[h][y]--;
		G[h][y+1]++;

		G[x][0]++;
		G[x+1][0]--;
		G[x][w]--;
		G[x+1][w]++;
		A.push_back(x);B.push_back(y);
		tate[y].push_back(x);
		yoko[x].push_back(y);
	}
	for(ll i = 0;i<h;i++)for(ll j = 0;j<w;j++)G[i+1][j]+=G[i][j];
	for(ll i = 0;i<h;i++)for(ll j = 0;j<w;j++)G[i][j+1]+=G[i][j];
	for(ll i = 0;i<h;i++)sort(tate[i].begin(),tate[i].end());
	for(ll i = 0;i<w;i++)sort(yoko[i].begin(),yoko[i].end());

	for(ll i = 0;i<n;i++)G[A[i]][B[i]]--;
	for(ll i = 0;i<h;i++){
		for(ll j = 0;j<w;j++){
			//cout<<G[i][j]<<' ';
		}
		//cout<<endl;
	}
	set<pair<ll,ll>> blocks;
	for(ll i = 0;i<m;i++){
		ll x,y;cin >> x >> y;
		x--;y--;
		ll left = lower_bound(yoko[x].begin(),yoko[x].end(),y)-yoko[x].begin();
		ll rigit = yoko[x].size()-left;
		GB[x][y+1]+=left;
		GB[x][w]-=left;
		GB[x+1][y+1]-=left;
		GB[x+1][w]+=left;

		GB[x][0] += rigit;
		GB[x][y] -= rigit;
		GB[x+1][0] -= rigit;
		GB[x+1][y] += rigit;

		ll up = lower_bound(tate[y].begin(),tate[y].end(),x)-tate[y].begin();
		ll down = tate[y].size()-up;
		GB[x+1][y]+=up;
		GB[x+1][y+1]-=up;
		GB[h][y]-=up;
		GB[h][y+1]+=up;

		GB[0][y]+=down;
		GB[0][y+1]-=down;
		GB[x][y]-=down;
		GB[x][y+1]+=down;
		blocks.insert(make_pair(x,y));
	}
	for(ll i = 0;i<h;i++)for(ll j = 0;j<w;j++)GB[i+1][j]+=GB[i][j];
	for(ll i = 0;i<h;i++)for(ll j = 0;j<w;j++)GB[i][j+1]+=GB[i][j];
	for(ll i = 0;i<h;i++){
		for(ll j = 0;j<w;j++){
			//cout<<GB[i][j]<<' ';
		}
		//cout<<endl;
	}
	ll ans = 0;
	for(ll i = 0;i<h;i++){
		for(ll j =0;j<w;j++){
			if(blocks.count(make_pair(i,j)))continue;
			if(G[i][j]-GB[i][j]>0)ans++;
		}
	}
	cout<<ans<<endl;
}
