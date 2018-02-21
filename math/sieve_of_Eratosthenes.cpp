#define N 1000000
int arr[N];

void eratosthenes(){
    REP(i,N){
        arr[i]=1;
    }
    for(int i=2;i<sqrt(N);i++){
        if(arr[i]){
            for(int j=0;i*(j+2)<N;j++){
                arr[i*(j+2)]=0;
            }
        }
    }
    arr[0]=0;
    arr[1]=0;
}