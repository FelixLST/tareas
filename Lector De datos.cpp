#include <iostream>
#include <fstream>

using namespace std;
void Llenar(char v[][4],int r);
void Mostrar (char v[][4], int r);

int main()
{
    ifstream arch("C:\\datos\\Libro1.txt",ios::in);
    float res;
    char T1[60],T2[60];
    int v[4][4];
    arch.getline(T1,60,'\n');
    arch >> res;
    arch.get();
    arch.get();
    arch.getline(T2,60,'\n');
    arch.get();
    for(int i=0; i<4; i++)
    {
        for(int k=0; k<4; k++)
        {
            arch>>[i][k];
        }
    }
    cout << "Datos Leidos\n";
    cout << T1 << endl;
    cout << res << endl;

    for(int i=0; i<4; i++)
    {
        for(int k=0; k<4; k++)
        {
            cout << v[i][k] << ',';
        }
        cout << endl;
    }
    cout << T2 << endl;




    arch.close();
    return 0;
}
void Llenar(char v[][4], int r)
{
    int c=97;
    for(int i=0; i<r; i++)
    {
        for(int k=0; k<4; k++)
        {
            v[i][k]=c;
            c++;
        }
    }
}
void Mostrar(char v[][4],int r)
{
    for(int i=0; i<r; i++)
    {
        for(int k=0; k<4; k++)
        {
            cout << v[i][k] << ',';
        }
        cout << endl;
    }
}
