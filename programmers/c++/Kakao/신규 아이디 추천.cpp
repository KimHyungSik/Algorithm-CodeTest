#include <string>
#include <vector>
#include <iostream>

using namespace std;

char chek[] = {'-','_','.'};
string eraseString(string);

string solution(string new_id) {
    
    int i = 0;
    
    while(new_id[i] != '\0'){
        // 1단계
        if(new_id[i] >= 65 && new_id[i] <= 90)
            new_id[i] += 32;
        //2단계
        else if(!((new_id[i] >=97 && new_id[i] <= 122)|| // 소문자가 아니거나
                (new_id[i] >= 48 && new_id[i] <= 57))   // 숫자가 아니라면
                )
        {
            for(int j = 0; j < 3; j++){
                if(new_id[i] == chek[j])
                    break;
                if(j == 2)
                    new_id[i] = ' ';
            }
        }
        i++;
    }
    
    new_id = eraseString(new_id);
    //cout << "1,2 : "  << new_id << endl;;
    // 3단계
    for(i = 0; i < new_id.length(); i++){
        if(new_id[i] == '.'){
            for(int j = i+1; i < new_id.length(); j++){
                if(new_id[j] == '.'){
                    new_id[j] = ' ';
                    continue;
                }
                if(new_id[j] != ' ') break;
            }
        }
    }
    
    new_id = eraseString(new_id);
    //cout << "3 : "  << new_id << endl;;
    // 4단계
    if(!new_id.empty()){
        if(new_id[0] == '.') new_id[0] = ' ';
        if(new_id[new_id.length()-1] == '.')new_id[new_id.length()-1] = ' ';
    }
    
    new_id = eraseString(new_id);
    //cout << "4 : "  << new_id << endl;;
    // 5단계
    if(new_id.empty()){
        new_id.append("a");
    }
    //cout << "5 : "  << new_id << endl;
    new_id = eraseString(new_id);
    // 6단계
    string tempStr = "";
    for(int j = 0; j < 15; j++){
        if(j > new_id.length() -1) break;
        //cout << j << " : " << new_id[j] << endl;
        tempStr += new_id[j];
    }
    new_id = tempStr;
    if(new_id[new_id.length()-1] == '.') new_id[new_id.length()-1] = ' ';
              
    new_id = eraseString(new_id);
    //cout << "6 :"  << new_id << endl;;
    
    // 7단계
    while(new_id.length() < 3){
        new_id += new_id[new_id.length()-1];
    }
    
    //cout << "7 : " << new_id << endl;;
    
    return new_id;
}

string eraseString(string str){
    int i = 0;
    while(str[i] != '\0'){
        if(str[i] == ' ') {str.erase(i, 1); continue;}
        i++;
    }
    return str;
}

int main(){
    cout << solution("...........................................................");
    return 0;
}
