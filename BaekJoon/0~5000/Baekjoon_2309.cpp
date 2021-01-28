#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
  int arr[9];
  int total = 0;
  int fake_1, fake_2;

  for(int i = 0; i < 9;i++){
    scanf("%d", arr+i);
    total += *(arr +i);
  }

  sort(arr, arr+9);
  int temp;
  for(int i = 0; i < 9; i++){
    for(int j = 0; j < 9; j++){
      if(j != i){
        temp = arr[i] + arr[j];
        if(total - temp == 100){
          fake_1 = i;
          fake_2 = j;
          break;
        }
      }
    }
  }

  for(int i = 0; i < 9; i++){
    if(i != fake_1 && i != fake_2)
      printf("%d\n", arr[i]);
  }

  return 0;
}