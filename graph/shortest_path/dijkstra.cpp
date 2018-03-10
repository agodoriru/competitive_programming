//s:始点
void dijkstra(int s){
	priority_queue<P,vector<P>, greater<P> > que;
	
	//初期化
	REP(i,V+1){
		dist[i]=INF;
	}

	dist[s]=0;

	que.push(P(0,s));

	while(!que.empty()){
		P p=que.top();
		que.pop();

		int v=p.second;
		if(dist[v]<p.first) continue;
		REP(i,G[v].size()){
			Edge e=G[v][i];

			if(dist[e.to]>dist[v]+e.cost){
				dist[e.to]=dist[v]+e.cost;
				que.push(P(dist[e.to],e.to));
			}
		}
	}
}