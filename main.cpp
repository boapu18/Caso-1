#include <iostream>
#include <string>
#include <cstring>

using namespace std;
/*
    Analisis de Algoritmos
    Caso #1
    María Paula Bolaños Apú
    2021026046
*/

void Triplets1(int a[], int b[]){
    //Esta es la primera versión, hay muchas más variables
    //se utilizan más comparaciones y el código es más largo
    int result[2];
    int x = 0;
    int y = 0;
    for(int i=0; i<3; i++){
        if (a[i] > b[i])
            x++;
        if (a[i] < b[i])
            y++;
    }
    result[0] = x;
    result[1] = y;
    cout <<  "Ouput: " << result[0] << ", " << result[1] << endl;
}

void Triplets2(int a[], int b[]){
    //En esta segunda version más optimizada se usan 2
    //variables menos, menos lineas y se hacen 3 comparaciones menos
    int result[2] = {0, 0};
    result[0] += ((a[0] > b[0]) ? 1:0);
    result[0] += ((a[1] > b[1]) ? 1:0);
    result[0] += ((a[2] > b[2]) ? 1:0);
    result[1] += ((a[0] < b[0]) ? 1:0);
    result[1] += ((a[1] < b[1]) ? 1:0);
    result[1] += ((a[2] < b[2]) ? 1:0);
    cout <<  "Ouput: " << result[0] << ", " << result[1] << endl;
}

void TimeConversion1 (string time){
    //Primera versión hay 3 variables que
    //se pueden elminar y 1 comparacion que no
    //se necesita
    string pmoram = time.substr(8, 9);
    string result;
    if (pmoram == "PM"){
        if (time.substr(0, 2) == "12"){
            result = "00" + time.substr(2, 6);
        }else{
            string newTime = time.substr(0, 2);
            int newTimwInt = atoi(newTime.c_str());
            if (newTimwInt != 12){
                newTimwInt = newTimwInt + 12;
            }else{
                newTimwInt = 0;
            }
            result = (std::to_string(newTimwInt))+ time.substr(2, 6);
        }
    }else{
        result = time.substr(0, 8);
    }
    cout <<  "Ouput: " << result << endl;
}

void TimeConversion2 (string time){
    //En esta segunda version se eliminan
    //las varables incesarias y se elimina
    //una de las compareciones
    string result;
    if (time.substr(8, 9) == "PM"){
        result =  ((time.substr(0, 2) == "12") ? "00" + time.substr(2, 6):
            (std::to_string(atoi(time.substr(0, 2).c_str())+12))+ time.substr(2, 6));
    }else{
        result = time.substr(0, 8);
    }
    cout <<  "Ouput: "<< result << endl;;
}

void SubarrayDivision1(int squares, int chocolat[], int d, int m){
    //Se usan más variables y se usa while en lugar de for
    int total = 0;
    int i = 0;
    while (i < squares){
        int sum = 0;
        int x = 0;
        while (x = 0){
            int y = i+x;
            if (y < squares)
            sum = sum + chocolat[y];
            x++;
        }
        if (sum == d)
            total++;
        i++;
    }
    cout <<  "Ouput: " << "Total: " << total << endl;
}

void SubarrayDivision2(int squares, int chocolat[], int d, int m){
    //Se utilizan menos variables y se usa for en lugar de while
    int total = 0;
    for (int i = 0; i < squares; i++){
        int sum = 0;
        for (int x = 0; x < m; x++){
            if (i+x < squares)
            sum = sum + chocolat[i+x];
        }
        if (sum == d)
            total++;
    }
    cout <<  "Ouput: " << "Total: " << total << endl;
}

void MinionGame(string word){
    string vowels = "AEIOU";
    int kevin = 0;
    int stuart = 0;
    for (int i = 0; i < word.length(); i++){
        if (vowels.find(word[i])){
            kevin = kevin + word.length() - i;
        }else{
            stuart = stuart + word.length() - i;
        }
    }
    if (kevin > stuart)
        cout << "Kevin " << kevin << endl;
    if (kevin < stuart)
        cout << "Stuart " << stuart << endl;
    if (kevin == stuart)
        cout << "Draw";
}


void Pairs(int n, int k, int list[]){
    int result = 0;
    for (int i = 0; i < n; i++){
        for (int y = 0; y < n; y++)
            result += ((list[i] - list[y] == k) ? 1 : 0);
    }
    cout << result << endl;
}

int main(){
    cout << "Triplets version 1: " << endl;
    cout << "Input: " << "a[17, 28, 30] b[99, 16, 8]" << endl;
    int a[3] = {17, 28, 30};
    int b[3] = {99, 16, 8};
    Triplets1(a, b);

    cout << "Input: " << "a[71, 94, 20] b[99, 16, 81]" << endl;
    int a1[3] = {71, 94, 20};
    int b1[3] = {99, 16, 81};
    Triplets1(a1, b1);

    cout << endl;

    cout << "Triplets version 2: " << endl;
    cout << "Input: " << "a[5, 6, 7] b[3, 6, 10]" << endl;
    int a2[3] = {5, 6, 7};
    int b2[3] = {3, 6, 10};
    Triplets2(a2, b2);

    cout << "Input: " << "a[54, 60, 77] b[31, 60, 14]" << endl;
    int a3[3] = {54, 60, 77};
    int b3[3] = {31, 60, 14};
    Triplets2(a3, b3);

    cout << endl;

    cout << "Time Conversion 1: " << endl;
    cout << "Input: " << "08:41:15AM" << endl;
    string time = "08:41:15AM";
    TimeConversion1(time);

    cout << "Input: " << "10:59:15PM" << endl;
    string time1 = "10:59:15PM";
    TimeConversion1(time1);

    cout << endl;

    cout << "Time Conversion 2: " << endl;
    cout << "Input: " << "08:35:16PM" << endl;
    string time2 = "08:35:16PM";
    TimeConversion2(time2);

    cout << "Input: " << "12:04:00PM" << endl;
    string time3 = "12:04:00PM";
    TimeConversion2(time3);

    cout << endl;

    cout << "Subarray Division 1: " << endl;
    cout << "Input: " << "1 " << endl;
    cout  << "4" << endl;
    cout <<  "1 4" << endl;
    int squares = 1;
    int d = 4;
    int m = 1;
    int chocolat[] = {4};
    SubarrayDivision1(squares, chocolat, d, m);

    cout << "Input: " << "1 " << endl;
    cout << "4" << endl;
    cout << "1 4" << endl;
    int squares1 = 5;
    int d1 = 3;
    int m1 = 2;
    int chocolat1[] = {1, 2,1, 3, 2};
    SubarrayDivision1(squares1, chocolat1, d1, m1);

    cout << endl;

    cout << "Subarray Division 2: " << endl;
    cout << "Input: " << "4 " << endl;
    cout  << "2 2 1 3 2" << endl;
    cout <<  "4 2" << endl;
    int squares2 = 4;
    int d2 = 4;
    int m2 = 2;
    int chocolat2[] = {2,2,1,3,2};
    SubarrayDivision2(squares2, chocolat2, d2, m2);

    cout << "Input: " << "3 " << endl;
    cout  << "4" << endl;
    cout <<  "1 4" << endl;
    int squares3 = 3;
    int d3 = 3;
    int m3 = 2;
    int chocolat3[] = {1, 2, 1, 3 ,2};
    SubarrayDivision2(squares3, chocolat3, d3, m3);

    cout << endl;

    cout << "Minion Game: " << endl;
    cout << "Input: " << "BANANA " << endl;
    string word = "BANANA";
    MinionGame(word);

    cout << "Input: " << "CHOCOLAT" << endl;
    string word1 = "CHOCOLAT";
    MinionGame(word1);

    cout << endl;

    cout << "Pairs: " << endl;
    cout << "Input: 4 1 " << endl << "1 2 7 4";
    int n = 4;
    int list[] =  {1, 2, 7, 4};
    int k = 1;
    Pairs(n,k, list);

    cout << "Input: 5 1 " << endl << "1 5 3 4 2";
    int n1 = 5;
    int list1[] =  {1, 5, 3, 4, 2};
    int k1 = 1;
    Pairs(n1,k1, list1);

    return 0;
}