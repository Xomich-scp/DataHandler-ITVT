// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "DataHandler.h"



using namespace std;
int main() {
    // tests go here
    
    
    DataManager< map <Key,Value> > myDM_map;
    DataManager< vector <Value> > myDM_vec;

    DataVisualizer myDV_map(myDM_map, myDM_map);
    cout << "\nMap OK\n";
    DataVisualizer myDV_vec(myDM_vec, myDM_vec);
    cout << "\nVector OK\n";
    return 0;
}
