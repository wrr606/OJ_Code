//a249. 00679 - Dropping Balls
#include<stdio.h>

//這題須改為stdio.h並用C提交才會過
int main(){
    int n,d,l,index;
    scanf("%d",&n);
    while(n--){
        scanf("%d%d",&d,&l);
        index=1;
        for(int i=1;i<d;i++){
            if(l&1){
                index*=2;
                l++;
            }
            else{
                index=index*2+1;
            }
            l>>=1;
        }
        printf("%d\n",index);
    }
}