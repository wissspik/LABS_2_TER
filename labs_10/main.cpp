#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

class cypher {
public:
    int len_array;
    vector<int> array_1;
    vector<int>* point_array_1;  // Указатель на вектор

    void coding(int len_array);
    void decoding(vector<int>* j);  // Принимает указатель на вектор
};

void cypher::coding(int len_array) {
    srand(time(nullptr)); // случайность чисел от времени 


    array_1.resize(len_array); // инициализируем длину вектора
    for (int i = 0; i < len_array; i++) {
        array_1[i] = rand() % 18;  // задаем элементы от 0 до 17
    }

    point_array_1 = &array_1;  // Копируем указатель на array_1

}

void cypher::decoding(vector<int>* j) {
    if (j == nullptr) {  // Проверка, что указатель не нулевой
        cout << "Pointer is null" << endl;
        return;
    }

    for (int val : *j) {  // Разыменовываем указатель и проходим по элементам вектора
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    int len_array;
    cout << "Enter the length of the array not greater 10_000: " << endl;
    cin >> len_array;
    if (len_array >= 1000 || len_array < 1) {
        cout << "ERROR LEN ARRAY" << endl;
        return 0;
    }
    cypher vector_result; // объект класса 
    vector_result.coding(len_array);  // Кодируем массив длиной 10

    vector_result.decoding(vector_result.point_array_1);  // Передаем указатель в функцию decoding
    return 0;
}
