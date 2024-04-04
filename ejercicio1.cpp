#include <iostream>
#include <string>

using namespace std;

class Student {
public:
    explicit Student(string n, int a) : name(n), age(a) {}

    string getName() const { return name; }
    void setName(string n) { name = n; }
    int getAge() const { return age; }
    void setAge(int a) { age = a; }

    bool isOlder() const {
        return age >= 18;
    }

private:
    string name;
    int age;
};

int main() {
    string name1, name2;
    int age1, age2;

    cout << "Ingrese el nombre del primer estudiante: ";
    cin >> name1;
    cout << "Ingrese la edad del primer estudiante: ";
    cin >> age1;

    cout << "Ingrese el nombre del segundo estudiante: ";
    cin >> name2;
    cout << "Ingrese la edad del segundo estudiante: ";
    cin >> age2;

    Student student1(name1, age1);
    Student student2(name2, age2);

    cout << "\nDatos del primer estudiante:" << endl;
    cout << "Nombre: " << student1.getName() << endl;
    cout << "Edad: " << student1.getAge() << endl;
    cout << "Es mayor de edad: " << (student1.isOlder() ? "Si" : "No") << endl;

    cout << "\nDatos del segundo estudiante:" << endl;
    cout << "Nombre: " << student2.getName() << endl;
    cout << "Edad: " << student2.getAge() << endl;
    cout << "Es mayor de edad: " << (student2.isOlder() ? "Si" : "No") << endl;

    return 0;
}