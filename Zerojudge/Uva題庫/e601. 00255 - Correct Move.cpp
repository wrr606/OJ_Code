//e601. 00255 - Correct Move
#include<stdio.h>

int x[64]={};

void king(int k){
    x[k-8]=1;
    x[k+8]=1;
    x[k-1]=1;
    x[k+1]=1;
    x[k]=3;
}

bool stop(int k,int q2){
    if(k==0&&q2==9)
        return true;
    else if(k==7&&q2==14)
        return true;
    else if(k==56&&q2==49)
        return true;
    else if(k==63&&q2==54)
        return true;
    return false;
}

/*
0:空位、不可走的位置
1:國王旁
2:不合"legal"條件
3:國王
4:合法位置
*/
void queen(int q1){
    bool invited=false;
    for(int i=q1;i<q1/8*8+8;i++){
        if(invited){
            x[i]=2;
        }
        else if(x[i]==3){
            x[i]=2;
            invited=true;
        }
        else if(x[i]==0){
            x[i]=4;
        }
    }
    invited=false;
    for(int i=q1;i>=q1/8*8;i--){
        if(invited){
            x[i]=2;
        }
        else if(x[i]==3){
            x[i]=2;
            invited=true;
        }
        else if(x[i]==0){
            x[i]=4;
        }
    }
    invited=false;
    for(int i=q1;i>=0;i-=8){
        if(invited){
            x[i]=2;
        }
        else if(x[i]==3){
            x[i]=2;
            invited=true;
            //cout<<x[25]<<endl;
        }
        else if(x[i]==0){
            x[i]=4;
        }
    }
    invited=false;
    for(int i=q1;i<64;i+=8){
        if(invited){
            x[i]=2;
        }
        else if(x[i]==3){
            x[i]=2;
            invited=true;
        }
        else if(x[i]==0){
            x[i]=4;
        }
    }
}

int main(){
    int k,q1,q2;
    while(scanf("%d%d%d",&k,&q1,&q2)!=EOF){
        if(k==q1){
            printf("Illegal state\n");
            continue;
        }
        for(int i=0;i<64;i++){
            x[i]=0;
        }
        king(k);
        queen(q1);
        if(x[q2]==0||x[q2]==2||q1==q2){
            printf("Illegal move\n");
        }
        else if(x[q2]==1){
            printf("Move not allowed\n");
        }
        else if(stop(k,q2)){
            printf("Stop\n");
        }
        else if(x[q2]==4){
            printf("Continue\n");
        }
    }
}