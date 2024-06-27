#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <string>

using namespace std;

void print_menu(){
    cout<<"Menu"<<endl;
    cout<<"------------------------"<<endl;
    cout<<" [1] Add element"<<endl;
    cout<<" [2] Insert element"<<endl;
    cout<<" [3] Delete element"<<endl;
    cout<<" [4] Print data"<<endl;
    cout<<" [5] Dump into file"<<endl;
    cout<<" [6] Read from file"<<endl;
    cout<<" [0] Exit"<<endl;
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
            cout<<"Enter value: ";
            cin>>value;

            delete[] a;
            a = new int[++n];
            for(int i = 0; i < n - 1; ++i){
                a[i] = b[i];
            }

            delete[] b;
            a[n - 1] = value;
            cout<<"Added element "<<value<<" at the end of the array"<<endl;
        } else if(action == "2"){
            b = new int[n];
            for(int i = 0; i < n; ++i){
                b[i] = a[i];
            }

            delete[] a;

            cout<<"Enter value: ";
            cin>>value;
            do{
                cout<<"Enter desired position of new element "<<value<<": ";
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

            cout<<"Added element "<<value<<" at position "<<pos<<endl;

            delete[] b;

        } else if(action == "3"){
            b = new int[n];
            for(int i = 0; i < n; ++i){
                b[i] = a[i];
            }

            do{
                cout<<"Enter position of element to be deleted: ";
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

            cout<<"Deleted element "<<b[pos]<<" at position "<<pos<<endl;

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
                cout << "Unnable to open the file "<<endl;
            }
        } else if(action == "6"){
            string filename, line;
            cout<<"Enter filename .txt (default - input.txt) ";
            cin>>filename;
            if(filename.substr(filename.length() - 4, 4) != ".txt"){
                filename = "input.txt";
                cout<<"Used default file"<<endl;
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
                    cout << "Unnable to open file "<<filename<<endl;
                }
            } else {
                cout<<"Unnable to open file "<<filename<<endl;
            }

        } else if(action == "0"){
            break;
        } else{
            cout<<"Imcorrect option"<<endl;
        }
        system("pause");
    }

    return 0;
}
