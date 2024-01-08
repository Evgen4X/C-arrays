#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <string>

using namespace std;

void print_menu(){
    cout<<"Menu"<<endl;
    cout<<"------------------------"<<endl;
    cout<<" [1] Dodaj element"<<endl;
    cout<<" [2] Wstaw element"<<endl;
    cout<<" [3] Usun element"<<endl;
    cout<<" [4] Wypisz tablice"<<endl;
    cout<<" [5] Zapis do pliku"<<endl;
    cout<<" [6] Odczyt z pliku"<<endl;
    cout<<" [0] Wyjdz"<<endl;
    cout<<"------------------------"<<endl;
}

int main()
{

    fstream fio;

    for(int i = 0; ++i < 100;) rand();
    string action = "-1";
    int n;
    cout<<"Podaj dlugosc tablicy: "<<endl;
    cin>>n;
    int* a = new int[n];
    int* b = NULL;
    int value, pos;
    for(int i = 0; i < n; ++i){
        a[i] = rand() % 10;
    }
    while(action != "0"){
        system("cls");
        print_menu();
        cin>>action;
        if(action == "1"){
            b = new int[n];
            for(int i = 0; i < n; ++i){
                b[i] = a[i];
            }
            cout<<"Podaj wartosc: ";
            cin>>value;

            delete[] a;
            a = new int[++n];
            for(int i = 0; i < n - 1; ++i){
                a[i] = b[i];
            }

            delete[] b;
            a[n - 1] = value;
            cout<<"Dodano element "<<value<<" na koniec tablicy"<<endl;
        } else if(action == "2"){
            b = new int[n];
            for(int i = 0; i < n; ++i){
                b[i] = a[i];
            }

            delete[] a;

            cout<<"Podaj wartosc: ";
            cin>>value;
            do{
                cout<<"Podaj miejsce dokad wstawic "<<value<<": ";
                cin>>pos;
            } while(pos > n);
            a = new int[++n];
            for(int i = 0; i < pos; ++i){
                a[i] = b[i];
            }

            a[pos] = value;
            for(int i = pos; i < n - 1; ++i){
                a[i + 1] = b[i];
            }

            cout<<"Dodano element "<<value<<" w pozycje "<<pos<<endl;

            delete[] b;

        } else if(action == "3"){
            b = new int[n];
            for(int i = 0; i < n; ++i){
                b[i] = a[i];
            }

            do{
                cout<<"Podaj miejsce gdzie usunac element: ";
                cin>>pos;
            } while(pos > n);

            delete[] a;
            a = new int[n - 1];
            bool flag = false;
            for(int i = 0; i < n; ++i){
                if(i != pos){
                    if (flag){
                        a[i - 1] = b[i];
                    } else {
                        a[i] = b[i];
                    }
                } else {
                    flag = true;
                }
            }

            cout<<"Usunieto element "<<b[pos]<<" z pozycji "<<pos<<endl;

            --n;

            delete[] b;
        } else if(action == "4"){
            for(int i = 0; i < n; ++i){
                cout<<a[i];
                if(i != n - 1){
                    cout<<",";
                }
                cout<<" ";
            }
            cout<<endl;
        } else if(action == "5"){
            fio.open("output.txt", ios::out | ios::trunc);
            if(fio.is_open()){
                for(int i = 0; i < n; ++i){
                    fio << a[i];
                    if(i != n - 1){
                        fio << endl;
                    }
                }
            } else {
                cout << "Nie udalo sie otworzyc plik "<<endl;
            }
        } else if(action == "6"){
            string filename, line;
            cout<<"Podaj nazwe pliku .txt (domyslna nazwa - input.txt) ";
            cin>>filename;
            if(filename.substr(filename.length() - 4, 4) != ".txt"){
                filename = "input.txt";
                cout<<"Uzyto pliku domyslnego"<<endl;
            }
            fio.open(filename.c_str(), ios::in);
            if(fio.is_open()){
                int length = 0;
                while(!fio.eof()){
                    getline(fio, line);
                    length++;
                }
                fio.close();
                fio.open(filename.c_str(), ios::in);
                if(fio.is_open()){
                    delete[] a;
                    a = new int[length];
                    n = length;
                    length = 0;
                    while(!fio.eof()){
                        getline(fio, line);
                        a[length++] = atoi(line.c_str());
                    }
                    fio.close();
                } else {
                    cout << "Nie udalo sie otworzyc plik "<<filename<<endl;
                }
            } else {
                cout<<"Nie udalo sie otworzyc plik "<<filename<<endl;
            }

        } else if(action == "0"){
            break;
        } else{
            cout<<"Nieprawidlowa opcja"<<endl;
        }
        system("pause");
    }

    return 0;
}
