#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>

#define N 10
#define M 10

int move[8][2] = { {1,0},{0,1},{1,1},{-1,0},{0,-1},{-1,-1},{1,-1},{-1,1} };

int middle(int x);
void random_Walk(int(*arr)[M]);
void print(int(*arr)[M],int x, int y);

int main() {
    srand(time(NULL));
    int arr[N][M] = { 0, };
    int middle_N = middle(N);
    int middle_M = middle(N);

    random_Walk(arr);
    return 0;
}

int middle(int x) {
    if (x % 2) {
        return x / 2 - 1;
    }
    else {
        return x / 2;
    }
}

void random_Walk(int(*arr)[M]) {
    int y = middle(N);
    int x = middle(M);

    arr[y][x] = 1;
    print(arr, y, x);
    for (int i = 0; i < 50; ) {
        int temp_X = move[rand() % 8][0];
        int temp_Y = move[rand() % 8][1];
        if (x + temp_X >= N || y + temp_Y >= M || x + temp_X < 0 || y + temp_Y < 0) {
            continue;
        }
        x += temp_X;
        y += temp_Y;
        arr[y][x] = 1;
        system("cls");
        print(arr,y,x);
        Sleep(500);
        i++;
    }
    system("cls");
    print(arr,y,x);
};

void print(int(*arr)[M],int x, int y) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if(i == x && j == y){
                printf(" B");
            }else if (arr[i][j]) {
                printf("бр");
            }
            else if(!arr[i][j]){
                printf("бс");
            }
        }
        printf("\n");
    }
}
