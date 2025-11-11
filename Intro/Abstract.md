# C++ Grundlagen – Zusammenfassung (Lectures 2–10)

Dieses Dokument fasst die wichtigsten Grundlagen aus den Vorlesungen 2–10 zusammen.  
Es dient als Lernhilfe für den Einstieg in C++.

---

## Lecture 2: Compiling and Linking

### Ablauf der Programmentwicklung
1. **Source Code (.cpp)** → geschrieben vom Programmierer
2. **Compiler**: übersetzt den Code (mit Headern .hpp) in **Objektcode (.o oder .obj)**
3. **Linker**: verbindet mehrere Objektdateien und Bibliotheken (.lib) zu einer **ausführbaren Datei (.exe oder .out)**

### Kompilierungsprozess
```bash
g++ main.cpp -o main
```
- g++: GNU C++ Compiler
- main.cpp: Quellcode
- -o main: Name der Ausgabedatei

### Mehrere Dateien
```bash
g++ file1.cpp file2.cpp -o program
```
→ Der Linker fügt beide Objektdateien zu einem Programm zusammen.

### Mehrere Dateien
Zwei Typen von Errors:
- Compiler-Error (static)
- Runtime-Error (dynamic)

---

## Lecture 3: Variable Declarations

### Grundlegende Datentypen
| Typ      | Beschreibung                        | Beispiel                 |
| -------- |:------------------------------------| ------------------------ |
| `int`    | Ganze Zahl                          | `int age = 25;`          |
| `double` | Gleitkommazahl                      | `double pi = 3.14;`      |
| `char`   | Einzelnes Zeichen                   | `char grade = 'A';`      |
| `bool`   | Wahrheitswert                       | `bool isReady = true;`   |
| `string` | Zeichenkette (erfordert `<string>`) | `string name = "Jonas";` |

### Konstanten
```c++
const double PI = 3.14159;
```

### Gültigkeitsbereich (Scope)
- Lokal: innerhalb einer Funktion oder eines Blocks `{ }`
- Global: außerhalb aller Funktionen definiert

---

## Lecture 4: Expressions

### Operatoren
- Arithmetisch: `+`, `-`, `*`, `/`, `%`
- Zuweisung: `=`, `+=`, `-=`, `*=`, `/=`
- Vergleich: `==`, `!=`, `<`, `>`, `<=`, `>=`
- Logisch: `&&` (und), `||` (oder), `!` (nicht)
- Inkrement/Dekrement: `++`, `--`

### Beispiel
```c++
int a = 5, b = 3;
int result = a * b + 10;  // 25
```

Operatoren haben einen unterschiedlichen Vorrang (presedence)
```c++
std::cout << a + b << std:endl;
```
Hier wird zuerst a + b berechnet bevor was in die Konsole kommt. 
Hier können logikfehler entstehen. Bei gleicher Presedence ist associativity relevant (Klammer setzen bspw.).
https://en.cppreference.com/w/cpp/language/operator_precedence.html

---

## Lecture 5: If Statement

### Syntax
```c++
if (condition) {
    // Code wenn Bedingung wahr
} else if (other_condition) {
    // Alternative Bedingung
} else {
    // Wenn keine Bedingung zutrifft
}
```

### Beispiel
```c++
int age = 18;
if (age >= 18) {
    cout << "Erwachsen";
} else {
    cout << "Minderjährig";
}
```

---

## Lecture 6: While and For Loops

### While-Schleife
```c++
int i = 0;
while (i < 5) {
    cout << i << endl;
    i++;
}
```

### For-Schleife
```c++
for (int i = 0; i < 5; i++) {
    cout << i << endl;
}
```

### Do-While-Schleife
```c++
int x = 0;
do {
    cout << x << endl;
    x++;
} while (x < 5);
```

---

## Lecture 7: Arrays and Strings

### Arrays
```c++
int numbers[3] = {1, 2, 3};
cout << numbers[0];  // 1
```
- Indizes beginnen bei 0
- Feste Größe nach der Deklaration

### Strings
```c++
#include <string>
string name = "Jonas";
cout << name.length();
cout << name[0];  // 'J'
```

---

## Lecture 8: Pointers and References

### Zeiger (Pointer)
Speichern Adressen von Variablen
```c++
int x = 10;
int* ptr = &x;
cout << *ptr;   // Zugriff auf den Wert (10)
```

### Referenzen
Aliasname für eine Variable
```c++
int a = 5;
int& ref = a;
ref = 10;  // a ist jetzt 10
```

### Unterschied
| Pointer                    | Reference                   |
| -------------------------- | --------------------------- |
| Kann `nullptr` sein        | Muss immer auf etwas zeigen |
| Kann neu zugewiesen werden | Nicht neu zuweisbar         |

---

## Lecture 9: Functions

### Syntax
```c++
Rückgabetyp Funktionsname(Parameter) {
    // Code
    return Wert;
}
```

### Beispiel
```c++
int add(int a, int b) {
    return a + b;
}

int main() {
    cout << add(2, 3);
}
```

### Parameterübergabe
- By Value: Kopie des Wertes (Standard)
- By Reference: Originalwert wird verändert
```c++
void increase(int& num) {
    num++;
}
```

---

## Lecture 10: File Input and Output

### Header
```c++
#include <fstream>
```

### Schreiben in Datei
```c++
ofstream file("data.txt");
file << "Hallo Welt!" << endl;
file.close();
```

### Lesen aus Datei
```c++
ifstream file("data.txt");
string line;
while (getline(file, line)) {
    cout << line << endl;
}
file.close();
```

---

## Nützliche Tipps

- Verwende `#include <iostream>` und `using namespace std;` für Ein-/Ausgabe mit `cout` und `cin`.
- Immer `return 0;` am Ende von `main()`.
- Teste kleine Codebeispiele regelmäßig mit einem Online-Compiler oder lokal über `g++`.