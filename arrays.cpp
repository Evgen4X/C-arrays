#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

void print_menu(){
    cout<<"Menu"<<endl;
    cout<<"------------------------"<<endl;
    cout<<" [1] Dodaj element"<<endl;
    cout<<" [2] Wstaw element"<<endl;
    cout<<" [3] Usun element"<<endl;
    cout<<" [4] Wypisz tablice"<<endl;
    cout<<" [5] Wyjdz"<<endl;
}

int main()
{
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

            delete[] a;
            a = new int[--n];
            for(int i = 0; i < n; ++i){
                a[i] = b[i];
            }

            cout<<"Usunieto element "<<b[n]<<" z konca tablicy"<<endl;

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
            break;
        } else{
            cout<<"Nieprawidlowa opcja"<<endl;
        }
        system("pause");
    }

    return 0;
}
