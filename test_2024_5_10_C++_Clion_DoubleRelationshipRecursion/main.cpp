#include <iostream>
#include <cstdio>

int main(int argc, const char * argv[]) {

    long long m[10001];     // 数组：从小到大保存的集合M的元素
    int n;                  // 查询第n项
    int p2;                 // F2(x)=2x+1的索引指针
    int p5;                  // F5(x)=5x-1的索引指针
    scanf("%d",&n);
    m[1]=1;
    p2=1;
    p5=1;
    // 请在这里补充代码，完成本关任务
    /********* Begin *********/

    //int sum = m[1];
	for (int i=2;i<=n;i++){
       int temp2 = 2*m[p2]+1;
       int temp5 = 5*m[p5]-1;

       if(temp2 < temp5){
            m[i] = temp2;
            p2++;}
        else if(temp2 > temp5){
            m[i] = temp5;
            p5++;
        }
        else{
            m[i] = temp2;
            p2++;
            p5++;
        }
    }

    /********* End *********/


    printf("%d\n",m[n]);

    return 0;
}