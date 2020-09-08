void Create_Account(); //연결리스트로 통장 계설
void Allquest_Account(); //모든 통장 검색 
void diposit(int infdNo, int money); //입금
void withdraw(int findNo, int money); //출금
int findAccount(int findNo); // 통장 찾기 찾을경우 1 없을경우 0반환 그리고 tempNode가 그통장 을 가르킴
void sendTo(int fromNo, int toNo, int money); //이체
int checkPassword(int findNo); //비밀번호 확인
//종료시 모든 통장 메모리 제거
void exit();
