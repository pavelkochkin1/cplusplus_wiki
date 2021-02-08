#include <fstream>
using namespace std;

int** matrixCreation(int n); // память под матрицу
int* arrayCreation(int n); // память под массив
void matrixFilling(ifstream& fin, int** M, int n); // заполнение матрицы из файла
void output(ofstream& fout, int** M, int n); // вывод матрицы в файл
int* maxIndex(int** M, int n); // индексы максимального элемента матрицы в виде массива
void my_swap(int *a, int *b); // обмен элементов
void transposition(int** M, int n); // транспонирование
void nullLine(int** M, int n, int i); // обнуление строки
void mainTask(int** M, int n); // решение главной задачи
void clearMemory_matr(int** M, int n); // очистка памяти от матрицы

int main(){

    setlocale(LC_ALL, "RU");

    // открываются два файла входного и выходного потока
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n;
    int** M1; int** M2; int** M3;

    fin >> n; // размерность матриц в первой строчке файла
    fin.ignore(); // пропуск пустой строки

    //создание матриц, занимаем память
    M1 = matrixCreation(n);
    M2 = matrixCreation(n);
    M3 = matrixCreation(n); 

    // инициализация матриц значениями из файла
    matrixFilling(fin, M1, n);
    matrixFilling(fin, M2, n);
    matrixFilling(fin, M3, n);

    // выполнение задачи
    mainTask(M1, n);
    mainTask(M2, n);
    mainTask(M3, n);

    // вывод матриц
    output(fout, M1, n);
    output(fout, M2, n);
    output(fout, M3, n);

    // очистка памяти от матриц
    clearMemory_matr(M1, n);
    clearMemory_matr(M2, n);
    clearMemory_matr(M3, n);

    // закрытие файлов
    fin.close();
    fout.close();
}

int** matrixCreation(int n){
    //занятие памяти под квадратную матрицу
    int** M = new int* [n];
    for(int i = 0; i < n; i++){
        M[i] = new int [n];
    }
    return M;
}

int* arrayCreation(int n){
    // занятие памяти под массив
    int* A = new int [n];
    return A;
}

void matrixFilling(ifstream& fin, int** M, int n){
    // заполнение матрицы данными из файла 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            fin >> M[i][j];
        }
    }
    fin.ignore(); // пропускаем пустую строку в файле
}

void output(ofstream& fout, int** M, int n){
    // вывод конечной матрицы в файл
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            fout << M[i][j] << " ";
        }
        fout << "\n"; // переход на след. строку
    }
    fout << "\n"; // переход на след. строку
}

int* maxIndex(int** M, int n){
    int max = M[0][0]; // предполагаем что первый элемент и есть максимальный
    int* maxIndex = arrayCreation(2); // создание массива под индексы максимального элемента
    maxIndex[0] = 0; maxIndex[1] = 0; // инициализация массива индексами первого элемента 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(max < M[i][j]){
                // если найдет больший элемент, то переназначаем максимальное и индексы
                max = M[i][j];
                maxIndex[0] = i;
                maxIndex[1] = j;
            }
        }
    }
    // выводим массив с индексами максимального элемента 
    return maxIndex;
}

void my_swap(int *a, int *b) {
    // небольшое упрощение
    // обмен значений для двух переменных
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void transposition(int** M, int n){
    // функция транспонирования
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            my_swap(&M[i][j], &M[j][i]);
        }
    }
}

void nullLine(int** M, int n, int i){
    // функция обнуления i-ой строки
    for(int j = 0; j < n; j++){
        M[i][j] = 0;
    }
}

void mainTask(int** M, int n){
    int* A = maxIndex(M, n); // массив с индексами максимального элемента
    if(A[0] > A[1]){
    // проверка i > j т.е. находится ли максимальный элемент под главной
        transposition(M, n);
    }else{
    // если не под главной, то следовательно элемент на главной диагонали или над ней.
    // передаем в функцию индекс строки максимального элемента 
        nullLine(M, n, A[0]);
    }
    // очистка памяти от массива с индексами
    for (int i = 0; i < n; i++) {
        delete [] A;
    }    
}

void clearMemory_matr(int** M, int n){
    // очистка памяти от матрицы
    for (int i = 0; i < n; i++) {
        delete[] M[i];
    }
    delete [] M;        
}