//*****************************************************************************************************
//
//		This program reads in information about testers from a text file "Testers.txt" and writes the
//      information into a binary file "Testers.dat". The information includes the tester's name,
//      score, and the date the test was taken. The program makes use of a struct called "Person" to
//      store the information of each tester and two functions, "readTesters" and "writeTesters", to
//      handle reading from the text file and writing to the binary file, respectively.
//
//*****************************************************************************************************

#include <fstream>     //library for input and output operations with files
#include <iostream>
#include <string>
using namespace std;

//*****************************************************************************************************

const int NAME_SIZE = 20;

struct Date {
    int month;
    int day;
    int year;
};
struct Person {
    char name[NAME_SIZE];
    double score;
    Date testTaken;
};

Person *readTesters(const string &fileName, int &num);
void writeTesters(const string &fileName, Person people[], int numP);

//*****************************************************************************************************

int main() {
    int numP = 0;
    string fileName;
    Person *people = nullptr;

    people = readTesters("Testers.txt", numP);     // read from text file and store in array of structs
    writeTesters("Testers.dat", people, numP);     // write from array of structs to binary file

    delete[] people;
    people = nullptr;

    return 0;
}

//*****************************************************************************************************

Person *readTesters(const string &fileName, int &num) {
    Person *p = nullptr;
    ifstream f(fileName);

    if (f.is_open()) {
        f >> num;
        f.ignore();

        p = new Person[num];
        
        for (int i = 0; i < num; ++i) {
            f.getline(p[i].name, NAME_SIZE);
            f >> p[i].score;
            f.ignore();
            f >> p[i].testTaken.month;
            f.ignore();
            f >> p[i].testTaken.day;
            f.ignore();
            f >> p[i].testTaken.year;
            f.ignore();
        }
        f.close();
    } else {
        cerr << "Error: Unable to open file" << endl;     // cerr is unbuffered and best for error handling
    }

    return p;
}

//*****************************************************************************************************

void writeTesters(const string &fileName, Person people[], int numP) {
    ofstream f(fileName, ios::binary);     // ios::binary is used to write binary data to a file instead of text
                                           // ofstream_object_(file_opened, open_mode) is used to write to files
    f.write(reinterpret_cast<char *>(&numP), sizeof(int));
    f.write(reinterpret_cast<char *>(people), sizeof(Person) * numP);
    f.close();
}

//*****************************************************************************************************

/*
reinterpret_cast<new_type>(expression)
C++ type cast operator used to cast an expression to a different type, regardless of the relationship
between the original type and the new type.

f.write(reinterpret_cast<char*>(&numP), sizeof(int));
(&numP) - casts it to a char* pointer, allowing it to be written to the binary file
sizeof(int) - specifies the size of the data being written is an int type

f.write(reinterpret_cast<char*>(people), sizeof(Person) * numP);
(people) - casts it to a char* pointer, allowing it to be written to the binary file.
sizeof(Person) * numP - specifies the size of the data being written is an array of Person structs with
                       numP number of elements.


*/