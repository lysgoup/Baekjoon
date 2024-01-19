#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int *visited;
int *stack;
int top;

void backtracking(int N, int M){
    if(top==M){
        for(int i=0;i<M;i++){
            printf("%d ",stack[i]+1);
        }
        printf("\n");
        top--;
        visited[stack[top]] = 0;
        return;
    }
    for(int i=0;i<N;i++){
        if(visited[i] == 0){
            visited[i] = 1;
            stack[top] = i;
            top++;
            backtracking(N,M);
        }
    }
    top--;
    visited[stack[top]] = 0;
    return;
}

int main(int argc, char *argv[]){
    int M; //* M개
    int N; //* 1~N
    scanf("%d %d",&N,&M);

    stack = (int *)malloc(sizeof(int)*M);
    visited = (int *)malloc(sizeof(int)*N);
    top = 0;
    
    for(int i=0;i<N;i++){
        memset(visited,0,N*sizeof(int));
        memset(stack,0,M*sizeof(int));
        stack[top] = i;
        top++;
        visited[i] = 1;
        backtracking(N,M);
        top = 0;
    }
}