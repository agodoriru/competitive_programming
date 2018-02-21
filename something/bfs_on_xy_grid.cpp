#include <iostream>
#include <queue>

using namespace std;

typedef std::pair<int, int> P;

#define REP(i, n) rep(i, 0, n)

const int INF = 1e9;

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

int grid[100][100];
char maze[100][100];
int w,h;

int bfs(int sx,int sy,int gx,int gy){
//sx -> スタートのx座標
//sy -> スタートのy座標
//gx -> ゴールのx座標
//gy -> ゴールのy座標

	queue<P> que;

	//grid内の初期化
	REP(y,h){
		REP(x,w){
			grid[y][x]=INF;
		}
	}

	//スタート地点の初期化
	que.push(P(sx,sy));
	grid[sy][sx]=0;


	while(que.size()){
		P p=que.front();
		que.pop();

		if(p.first==gx&&p.second==gy)break;

		REP(i,4){
			int nx=p.first+dx[i];
			int ny=p.second+dy[i];

			if(grid[ny][nx]!=INF)continue;
			if(nx<0||ny<0||nx>=w||ny>=h)continue;
			if(maze[ny][nx]=='#')continue;

			que.push(P(nx,ny));
			grid[ny][nx]=grid[p.second][p.first]+1;


		}
	}
	return grid[gy][gx];
}