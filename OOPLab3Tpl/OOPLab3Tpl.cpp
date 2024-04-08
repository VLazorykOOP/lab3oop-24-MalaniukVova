#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>

class Square {
private:
    double side;
    std::string color;

public:
    // Конструктор за замовчуванням
    Square() : side(0), color("White") {}

    // Конструктор з параметрами
    Square(double s, const std::string& c) : side(s), color(c) {}

    // Функція-член для обчислення площі квадрата
    double area() const {
        return side * side;
    }

    // Функція-член для обчислення периметру квадрата
    double perimeter() const {
        return 4 * side;
    }

    // Функція-член для обчислення радіусу описаного кола
    double circumscribedCircleRadius() const {
        return side * sqrt(2) / 2;
    }

    // Функція-член для обчислення радіусу вписаного кола
    double inscribedCircleRadius() const {
        return side / 2;
    }

    // Функція-член для встановлення значення сторони та кольору
    void setSide(double s) {
        if (s > 0) {
            side = s;
        }
        else {
            std::cerr << "Error: Side must be a positive number.\n";
        }
    }

    void setColor(const std::string& c) {
        color = c;
    }

    // Функції-члени для повернення значень полів
    double getSide() const {
        return side;
    }

    std::string getColor() const {
        return color;
    }

    // Функція-член для друку даних про квадрат
    void print() const {
        std::cout << "Square: Side = " << side << ", Color = " << color << "\n";
    }
};

class Vector {
private:
    unsigned int* data;
    int size;
    int& state;

public:
    // Конструктор без параметрів
    Vector() : data(new unsigned int[1]), size(1), state(size) {
        data[0] = 0;
    }

    // Конструктор з одним параметром - розмір вектора
    Vector(int size) : data(new unsigned int[size]), size(size), state(size) {
        for (int i = 0; i < size; i++) {
            data[i] = 0;
        }
    }

    // Конструктор з двома параметрами - розмір вектора та значення ініціалізації
    Vector(int size, unsigned int init_value) : data(new unsigned int[size]), size(size), state(size) {
        for (int i = 0; i < size; i++) {
            data[i] = init_value;
        }
    }

    // Конструктор копій
    Vector(const Vector& other) : data(new unsigned int[other.size]), size(other.size), state(other.state) {
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }

    // Операція присвоєння
    Vector& operator=(const Vector& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            state = other.state;
            data = new unsigned int[size];
            for (int i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    // Деструктор
    ~Vector() {
        if(data!=nullptr    ) delete[] data;
    }

    // Функція, яка присвоює елементу масиву деяке значення (параметр за замовчуванням)
    void setValue(unsigned int value, int index = 0) {
        if (index >= 0 && index < size) {
            data[index] = value;
        }
        else {
            state = -1; // Код помилки: вихід за межі масиву
        }
    }

    // Функція яка одержує деякий елемент масиву
    unsigned int getValue(int index) const {
        if (index >= 0 && index < size) {
            return data[index];
        }
        else {
            state = -1; // Код помилки: вихід за межі масиву
            return 0;
        }
    }

    // Функція друку
    void print() const {
        for (int i = 0; i < size; i++) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }

    // Операції додавання, віднімання
    Vector operator+(const Vector& other) const {
        Vector result(size < other.size ? other.size : size);
        for (int i = 0; i < result.size; i++) {
            if (i < size && i < other.size) {
                result.data[i] = data[i] + other.data[i];
            }
            else if (i < size) {
                result.data[i] = data[i];
            }
            else {
                result.data[i] = other.data[i];
            }
        }
        return result;
    }

    Vector operator-(const Vector& other) const {
        Vector result(size < other.size ? other.size : size);
        for (int i = 0; i < result.size; i++) {
            if (i < size && i < other.size) {
                result.data[i] = data[i] - other.data[i];
            }
            else if (i < size) {
                result.data[i] = data[i];
            }
            else {
                result.data[i] = -other.data[i];
            }
        }
        return result;
    }

    // Операція множення на ціле типу unsigned short
    Vector operator*(unsigned short factor) const {
        Vector result(size);
        for (int i = 0; i < size; i++) {
            result.data[i] = data[i] * factor;
        }
        return result;
    }

    // Функції порівняння
    bool operator>(const Vector& other) const {
        return size > other.size;
    }

    bool operator<(const Vector& other) const {
        return size < other.size;
    }

    bool operator==(const Vector& other) const {
        if (size != other.size) {
            return false;
        }
        for (int i = 0; i < size; i++) {
            if (data[i] != other.data[i]) {
                return false;
            }
        }
        return true;
    }

    bool operator!=(const Vector& other) const {
        return !(*this == other);
    }

    // Підрахунок числа об'єктів даного типу
    static int countObjects;

    static int getCountObjects() {
        return countObjects;
    }
};

int Vector::countObjects = 0;

auto Task1()
{
        int main() {
        double height, width;
        std::string color;

        std::cout << "Enter the height of the square: ";
        std::cin >> height;

        std::cout << "Enter the width of the square: ";
        std::cin >> width;

        std::cin.ignore(); // Clear the newline character from the input buffer

        std::cout << "Enter the color of the square: ";
        std::getline(std::cin, color);

        Square mySquare(height, color); // Створення об'єкта квадрата з заданими параметрами
        mySquare.print(); // Друкуємо інформацію про квадрат

        // Використання функцій-членів для обчислення та виведення додаткової інформації
        std::cout << "Area: " << mySquare.area() << "\n";
        std::cout << "Perimeter: " << mySquare.perimeter() << "\n";
        std::cout << "Circumscribed Circle Radius: " << mySquare.circumscribedCircleRadius() << "\n";
        std::cout << "Inscribed Circle Radius: " << mySquare.inscribedCircleRadius() << "\n";

        return 0;
    }

}
auto Task2()
{
    int main() {
        Vector::countObjects++;

        // Тестування класу Vector
        Vector v1; // Конструктор без параметрів
        Vector v2(5); // Конструктор з одним параметром
        Vector v3(3, 10); // Конструктор з двома параметрами
        Vector v4 = v3; // Конструктор копій
        Vector v5;
        v5 = v4; // Операція присвоєння

        v1.setValue(5); // Присвоюємо значення першому елементу v1
        v2.setValue(7, 1); // Присвоюємо значення другому елементу v2

        std::cout << "v1: ";
        v1.print();
        std::cout << "v2: ";
        v2.print();
        std::cout << "v3: ";
        v3.print();
        std::cout << "v4: ";
        v4.print();
        std::cout << "v5: ";
        v5.print();

        std::cout << "v1 + v2: ";
        (v1 + v2).print(); // Операція додавання

        std::cout << "v1 * 3: ";
        (v1 * 3).print(); // Операція множення на ціле число

        std::cout << "v1 > v2: " << (v1 > v2) << std::endl; // Операція порівняння

        std::cout << "Число об'єктів Vector: " << Vector::getCountObjects() << std::endl;

        return 0;
    }


}
int main()
{
    int x;
    cout << "Choose Task!" << endl;
    cout << "1.Task1" << "\n";
    cout << "2.Task2" << "\n";
    cout << "3.Task3" << "\n";
    cout << "4.Exit!" << "\n";

    cin >> x;

    switch (x) {
    case 1:
        Task1();
        break;

    case 2:
        Task2();
        break;
    case 3:
        Task3();
        break;
    case 4:
        cout << "Well goodbye!" << endl;
        break;

    }

}
