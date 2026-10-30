#include "house.h"
using namespace std;

bool House::validChar(char c) const {
    return (c >= 33 && c <= 126);
}

House::House(int s, char b, char f) {
    if (s < 3) size = 3;
    else if (s > 37) size = 37;
    else size = s;

    border = validChar(b) ? b : 'X';
    fill = validChar(f) ? f : '*';
}

int House::GetSize() const {
    return size;
}

int House::Perimeter() const {
   
    int triSide = size + 2;
    return (4 * size) + (3 * triSide) - (triSide);
}

double House::Area() const {
    double baseArea = size * size;
    double triSide = size + 2;
    double triArea = (sqrt(3.0) / 4.0) * triSide * triSide;
    return baseArea + triArea;
}

void House::Grow() {
    if (size < 37) size++;
}

void House::Shrink() {
    if (size > 3) size--;
}

void House::SetBorder(char b) {
    border = validChar(b) ? b : 'X';
}

void House::SetFill(char f) {
    fill = validChar(f) ? f : '*';
}

void House::Draw() const {
    int roofRows = size + 1; 

    //  Draw roof 
    for (int row = 0; row < roofRows; row++) {
        
        for (int s = 0; s < roofRows - row - 0; s++) cout << " ";

        
        for (int col = 0; col <= row; col++) {
            if (col == 0 || col == row) cout << border << " ";
            else cout << fill << " ";
        }
        cout << endl;
    }

    // Shared line 
    cout << border << " " << border << " ";
    for (int i = 0; i < size - 2; i++) cout << fill << " ";
    cout << border << " " << border << endl;

    //Base interior 
    for (int r = 0; r < size - 2; r++) {
        cout << "  " << border << " ";     
        for (int c = 0; c < size - 2; c++) cout << fill << " ";
        cout << border << endl;
    }

    // Bottom 
    cout << "  ";
    for (int i = 0; i < size; i++) cout << border << " ";
    cout << endl;
}

void House::Summary() const {
    cout << "House width and height base to roof = " << size << " units." << endl;
    cout << "Perimeter of house = " << Perimeter() << " units." << endl;
    cout << fixed << setprecision(2);
    cout << "Area of house = " << Area() << " units." << endl;
    cout << "House looks like:" << endl;
    Draw();
}
