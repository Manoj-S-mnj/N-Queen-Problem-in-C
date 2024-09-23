
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isSafe(int **arr, int row, int col, int n){
    //To check the left side
    for(int j = 0; j < col; j ++){
        if(arr[row][j] == 1){
            return false;
        }
    }
    
    //to Check left upper side  
    for(int i = row - 1, j = col - 1;  i >= 0 && j >= 0; i --, j --){
        if(arr[i][j] == 1){
            return false;
        }
    }
    
    //To Check left lower side    
    for(int i = row + 1, j = col - 1;  i < n && j >= 0; i ++, j --){
        if(arr[i][j] == 1){
            return false;
        }
    }
    
    return true;
    
}

bool nQueensProblem(int **arr, int col, int n){
    if(col >= n){
        return true;
    }
    for(int i = 0; i < n; i ++){
        if(isSafe(arr, i, col, n)){
            arr[i][col] = 1;
            if(nQueensProblem(arr, col + 1, n)){
                return true;
            }
            arr[i][col] = 0;
        }
    }
    return false;
}

int main()
{
    int n;
    scanf("%d", &n);
    int **arr = (int **)malloc(n * sizeof(int*));
    for(int i = 0; i < n; i ++){
        arr[i] = (int *)malloc(n * sizeof(int));
        for(int j = 0; j < n; j ++){
            arr[i][j] = 0;
        }
    }
    
    bool ans = nQueensProblem(arr, 0, n);
    if(ans){
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < n; j ++){
                if(arr[i][j] == 1)
                    printf("Q ");
                else
                    printf(". ");
            }
             printf("\n");
        }
    }
    
    return 0;
}
