
#include <iostream>
#include <string>
#include <tuple>
#include <fstream>
using namespace std;


struct flat
{
    int area;
    char name[40];
    char region[20];
    int cost;
};

tuple <flat*, int> massive()
{
    ifstream file;
    file.open("D:/flats.txt");
    int N = 0;
    char info[255];
    char* stat;
    while (file.getline(info, 255, '\n')) N++;
    flat *flats = new flat[N];
    file.close();
    file.open("D:/flats.txt");
    int i = 0;
    while (file.getline(info, 255, '\n'))
    {
        stat = strtok(info, "/");
        flats[i].area = stoi(stat);
        stat = strtok(NULL, "/");
        strcpy(flats[i].name, stat);
        stat = strtok(NULL, "/");
        strcpy(flats[i].region, stat);
        stat = strtok(NULL, "/");
        flats[i].area = stoi(stat);
        stat = strtok(NULL, "/");
        i++;
    }
    file.close();
    return make_tuple(flats,N);
}



int main()
{
	setlocale(LC_ALL, "Russian");

    ifstream file("D:/flats.txt");

    if (file.is_open()) // если файл не открыт
        cout << "Файл  открыт!\n";
    else
    {
        cout << "Файл не открыт!";
    }
    flat *flats;
    int N;
    tie(flats, N) = massive();





	return 0;

}
