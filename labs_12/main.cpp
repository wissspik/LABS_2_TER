#include <iostream>
#include <vector>
using namespace std;
bool test_position(int row,vector<int> &board,int col,int N){ // тест
    for (int i = 0;i < row;i++){// перебор по строчкам
        if ((board[i] == col)  || (abs(board[i] - col) == abs(i - row))){// тест на то,чтобы не было одинаковых столбцов \
                                                                             и было всё ок по диагоналями
            return false;
        }
                                                         
    }          
    return true;    
}

void f(int row,int N,vector<int> &board,vector<vector<int>> &solutions){ // функция ставит ферзей
    if (row == N){ // выходит из рекурскии 
        solutions.push_back(board);
        return; 
    }
    for (int col = 0;col < N;col++){ // ставим ферзей 
        if (test_position(row,board,col,N)){ // проверка позиции
            board[row] = col; // отмечаю ферзя его стобцом.
            f(row + 1,N,board,solutions); // захожу в глубь 
        }
    }

}


int main() {
    int col_F;
    cin >> col_F;
    vector<int> board(col_F,-1);
    vector<vector<int>> solutions;
    f(0,col_F,board,solutions); // 
    cout << "Number of solutions: " << solutions.size() << endl;
    for (const auto& solution : solutions) {
        for (int i = 0; i < col_F; i++) {
            cout << "(" << i << ", " << solution[i] << ") ";
        }
        cout << endl;
    }
}
//  Сложность O(n!) вместо O(n**n)    :)