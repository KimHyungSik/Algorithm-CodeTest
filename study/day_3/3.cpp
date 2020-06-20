#include <stdio.h>

int H_print(int(*arr)[5],int,int,int);
int V_print(int(*arr)[5],int,int,int);

int main(){
  int arr[5][5] = { 0 };
  H_print(arr,0,0,0);
  for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (arr[i][j] == 0)
				printf("   ");
			else printf("%3d",arr[i][j]);
		}
		printf("\n");
	}
}

int H_print(int(*arr)[5], int row, int col, int cnt){
  printf("H = %d\nrow = %d  col = %d\n", cnt,row,col);
  static int R_row=0,L_row=0;
  if(cnt >= 25){
    return 0;
  }
  if(col == 0){
    for(;col<5;col++){
      if(arr[row+R_row][col] == 0){
        cnt++;
        arr[row+R_row][col] = cnt;
      }
    }
    R_row++;
  }else if(col == 4){
    for(;col>0;col--){
      if(arr[row-L_row][col] == 0){
        cnt++;
        arr[row-L_row][col] = cnt;
      }
    }
    L_row++;
  }

  if(col==-1) col++;
  if(col==5) col--;
  return V_print(arr,row,col,cnt);
}
int V_print(int(*arr)[5], int row, int col, int cnt){
  printf("V = %d\nrow = %d  col = %d\n", cnt,row,col);
  static int R_col=0,L_col=0;
  if(cnt >= 25){
    return 0;
  }
  if(row == 0){
    for(;row<5;row++){
      if(arr[row][col-R_col] == 0){
        cnt++;
        arr[row][col-R_col] = cnt;
      }
    }
    R_col++;
  }else if(row == 4){
    for(;row>0;row--){
      if(arr[row][col+L_col] == 0){
        cnt++;
        arr[row][col+L_col] = cnt;
      }
    }
    L_col++;
  }

  if(row==-1) row++;
  if(row==5) row--;
  return H_print(arr,row,col,cnt);
}