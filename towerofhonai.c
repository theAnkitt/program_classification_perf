#include<stdio.h>
#include<stdlib.h>
void toh(int n, char a,char c,char b){               //tower of hanoi function.  
    if(n == 1){
        //printf("\nMove 1 from %c ----> %c",a,c);
        return;
    }
    toh(n-1, a,b,c);
    //printf("\nMove %d from %c ----> %c",n,a,c);
    toh(n-1,b,c,a);
}
int main(){
    int n;
    printf("Enter number of disk: ");
    scanf("%d",&n);
    toh(n,'a','c','b'); //A is the initial rod and C is the final rod B is the aux rod.
}