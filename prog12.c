#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#define N 4 
int board[N];
void printSolution(){
    for(int i=0;i<N;i++){
     for(int j=0;j<N;j++){
        if(board[i]==j)
            printf("Q ");
        else
            printf(".");
    }printf("\n");
}
printf("\n");
}
bool isSafe(int row,int col){
    for(int i=0;i<row;i++){
        if(board[i]==col || abs(board[i]-col)==abs(i-row))
            return false;
    }
    return true;
}
void solveNQueens(int row){
    if(row==N){
        printSolution();
        return;
    }
    for(int col=0;col<N;col++){
        if(isSafe(row,col)){
            board[row]=col;
            solveNQueens(row+1);
        }
    }
}
int main(){
    printf("Solutions for %d-Queens problem:\n\n",N);
    solveNQueens(0);
    return 0;
}