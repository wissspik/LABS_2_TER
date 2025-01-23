#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;
int main(){
    unordered_map<string,vector<string>> dict; // 
    vector<string> dictions;
    ifstream file("2.txt");
    if (!file){
        cout << "File is not defined";
        return 1;
    }
    string line;
    while (getline(file,line)){
        istringstream stream(line); // Поток для разделения строки на слова
        string word;
        while (stream >> word){// Считываем слова
            dictions.push_back(word);// Добавляем слово в массив        
        }
    }
    string target;
    string pop;
    
    int len_pop = 0;
    int Max = 0;

    for (int i = 0; i < dictions.size(); i++) {
        int count = 0;
        for (int j = 0; j < dictions.size(); j++) {
            if ((dictions[j].substr(0, dictions[i].size()) == dictions[i]) && (dictions[i] != dictions[j])) { // {**}
                if (dict.find(dictions[i]) != dict.end()){
                    dict[dictions[i]].push_back(dictions[j]);
                }
                else{
                    dict[dictions[i]] = {dictions[j]};
                }
                count++;
            }
        }
        if ((dictions[i].size() > len_pop) && (count >= 1)){
            pop = dictions[i];
            len_pop = dictions[i].size();
        }
        if (count > Max) {
            Max = count;
            target = dictions[i];
        }
        
    }
    if (Max == 0){
        cout << "NO";
        return 0;
    }
    else{
    cout << pop << " ";         // 1. КОРНЕВОЕ СЛОВО
    for (const auto& value : dict[pop]){
        cout << value << " ";
    }
    cout << endl;               // 2. ВАЖНОЕ СЛОВО
    cout << target << " " <<  Max << endl;
    file.close();
    return 0;
    }
}