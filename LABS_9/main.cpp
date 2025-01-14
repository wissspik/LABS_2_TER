#include <iostream>
#include <cstring>
using namespace std;
int main(){
    char word_1[100];                     // PART 1
    char word_2[100];
    cin >> word_1;    
    // 1. длина слова
    cout <<"1)Word Length: " <<  strlen(word_1) << endl; 

    // 2. копирование строк
    strcpy(word_2,word_1);
    cout <<"2)copied word: " << word_2 << endl;

    // 3. равенство слов
    int res = strcmp(word_1,word_2);
    if (res == 0){
        cout << "3)word_1 == word_2" << endl;
    }
    else{
        cout << "3)word_1 <> word_2" << endl;
    }


    string dictionary[20];               //PART 2
    for (int x = 0;x < 20;x++){
        cin >> dictionary[x];
        if (dictionary[x].length() > 10){
            cout << "Write a word less than 10 long";
            return 0;
        } 
    }
    for (int x = 0;x < 20;x++){
        if (x % 2 == 0){
            cout << dictionary[x] << ' ';
        }
    }
    return 0;

}