#include <iostream>
#include <bitset>
#include <string>
#include <stdexcept>

using namespace std;

const int BITS = 8; // Número de bits para las operaciones binarias

// Función para sumar dos números binarios
string addBinary(string a, string b) {
    bitset<BITS> num1(a);
    bitset<BITS> num2(b);
    bitset<BITS> result = num1.to_ulong() + num2.to_ulong();
    return result.to_string();
}

// Función para restar dos números binarios
string subtractBinary(string a, string b) {
    bitset<BITS> num1(a);
    bitset<BITS> num2(b);
    if (num1.to_ulong() < num2.to_ulong()) {
        throw underflow_error("Resultado negativo no soportado en binario sin signo.");
    }
    bitset<BITS> result = num1.to_ulong() - num2.to_ulong();
    return result.to_string();
}

// Función para multiplicar dos números binarios
string multiplyBinary(string a, string b) {
    bitset<BITS> num1(a);
    bitset<BITS> num2(b);
    bitset<BITS> result = num1.to_ulong() * num2.to_ulong();
    return result.to_string();
}

// Función para dividir dos números binarios
string divideBinary(string a, string b) {
    bitset<BITS> num1(a);
    bitset<BITS> num2(b);
    if (num2.to_ulong() == 0) {
        throw invalid_argument("Error: División por cero.");
    }
    bitset<BITS> result = num1.to_ulong() / num2.to_ulong();
    return result.to_string();
}

int main() {
    string bin1, bin2;
    char operation;

    cout << "Calculadora de números binarios (8 bits)" << endl;
    cout << "Ingrese el primer número binario: ";
    cin >> bin1;
    cout << "Ingrese el segundo número binario: ";
    cin >> bin2;

    cout << "Elija una operación (+, -, *, /): ";
    cin >> operation;

    try {
        if (operation == '+') {
            cout << "Resultado de la suma: " << addBinary(bin1, bin2) << endl;
        } else if (operation == '-') {
            cout << "Resultado de la resta: " << subtractBinary(bin1, bin2) << endl;
        } else if (operation == '*') {
            cout << "Resultado de la multiplicación: " << multiplyBinary(bin1, bin2) << endl;
        } else if (operation == '/') {
            cout << "Resultado de la división: " << divideBinary(bin1, bin2) << endl;
        } else {
            cout << "Operación no válida." << endl;
        }
    } catch (const exception &e) {
        cerr << e.what() << endl;
    }

    return 0;
}
