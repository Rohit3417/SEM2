#include <iostream>
class Rectangle {
    int length, width;
public:
    Rectangle(int l, int w) : length(l), width(w) {}
    int area() { return length * width; }
};

int main() {
    Rectangle rect(5, 3);
    std::cout << rect.area();
    return 0;
}