// Este ejemplo hace un trabajo similar al anterior, la diferencia esta en que el nombre del archivo se lo ingresa por consola.

#include <fstream>
#include <iostream>
// #include <string>

using namespace std;

void create_file(const string &filename)
{
    ofstream file(filename);

    if (!file) {
        cerr << "Error opening file" << endl;
        return;
    }

    file << "Hello, World!" << endl;
    file.close();
}

int main()
{
    string filename;
    cout << "Enter the name of the file to create: ";
    cin >> filename;

    create_file(filename);

    return 0;
}
