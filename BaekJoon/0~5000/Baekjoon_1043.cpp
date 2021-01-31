#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int N, k;
char str[50][16];
bool alpah[26];
int result = 0;

void dfs(int x, int start){
  //��� �ܾ �� �������
  if(!x){
    int count = 0;
    for(int i = 0; i < N; i++){
      int temp = 0;
      while(str[i][temp] != '\0'){//���� �ܾ� Ȯ��
        if(!alpah[str[i][temp] - 'a']){//����� ���� ���
          break;
        }
        temp++;
      }
      if(str[i][temp] == '\0'){//������ ������ �� ���
        count++;
      }
    }
    result  = result > count ? result : count;
  }else{//�ܾ �� �������
    for(int i = start; i < 26; i++){
      if(!alpah[i]){//����� ���� �ܾ�
        alpah[i] = true;
        dfs(x-1, i);
        alpah[i] = false;
      }
    }
  }
}

int main() {

  scanf("%d %d", &N, &k);
  
  if(k < 5){
    printf("0");
    return 0;
  }
  if(k > 25){
    printf("%d", N);
    return 0;
  }

  char temp_ptr[25];

//���� �Է�
  for(int i = 0; i < N; i++){
    scanf("%s", temp_ptr);
    int len = strlen(temp_ptr);
    copy(temp_ptr+3, temp_ptr+len, str[i]);//���� �յ� �ڸ���
  }

  //�ʼ� �ܾ� �Է�
  alpah['a' - 'a'] = true;
  alpah['t' - 'a'] = true;
  alpah['c' - 'a'] = true;
  alpah['n' - 'a'] = true;
  alpah['i' - 'a'] = true;

  dfs(k-5, 0);

  printf("%d", result);
  return 0;
}