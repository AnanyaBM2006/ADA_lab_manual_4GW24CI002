#include<stdio.h>
//#include<conio.h>
int s[10],d,n,set[10],count=0;
void display(int);
int flag =0;
int subset(int,int);

void main(){
    int i;
    printf("ENTER THE NUMBER OF THE ELEMENTS IN THE SET:");
    scanf("%d",&n);
    printf("Enter the set of values:");
    for(int i=0;i<n;i++)
      scanf("%d",&s[i]);
    printf("Enter the sum:");
    scanf("%d",&d);
    printf("The program output is:");
    subset(0,0);
    if(flag==0)
       printf("there is no solution");

}
int subset(int sum,int i){
    if(sum==d){
        flag=1;
        display(count);
        return 0;
    }
    if(sum >d || i>=n)
       return 0;
    else{
        set[count]=s[i];
        count++;
        subset(sum+s[i],i+1);
        count--;
        subset(sum,i+1);
        }
}
void display(int count){
    int i;
    printf("\t{");
    for(i=0;i<count;i++)
         printf("%d",set[i]);
    printf("}");
}
