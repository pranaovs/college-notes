#include "shapes.h"
#include <iostream>

using namespace std;

void createSquare() {
  int side;
  cout << "Enter the side length of the square: ";
  cin >> side;
  Square *square = new Square(side);
  cout << "Area of the square of side " << side << " is " << square->area()
       << endl;
  delete square;
}

void createRectangle() {
  int length, width;
  cout << "Enter the length and width of the rectangle: ";
  cin >> length >> width;
  Rectangle *rectangle = new Rectangle(length, width);
  cout << "Area of the rectangle of length " << length << " and width " << width
       << " is " << rectangle->area() << endl;
  delete rectangle;
}

void createCube() {
  int side;
  cout << "Enter the side length of the cube: ";
  cin >> side;
  Cube *cube = new Cube(side);
  cout << "Surface area of the cube of side " << side << " is " << cube->area()
       << endl;
  delete cube;
}

void createCuboid() {
  int length, width, height;
  cout << "Enter the length, width, and height of the cuboid: ";
  cin >> length >> width >> height;
  Cuboid *cuboid = new Cuboid(length, width, height);
  cout << "Surface area of the cuboid of length " << length << ", width "
       << width << ", and height " << height << " is " << cuboid->area()
       << endl;
  delete cuboid;
}

int main() {
  int choice;

  while (true) {
    cout << "Menu:" << endl;
    cout << "1. Create Square" << endl;
    cout << "2. Create Rectangle" << endl;
    cout << "3. Create Cube" << endl;
    cout << "4. Create Cuboid" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
      createSquare();
      break;
    case 2:
      createRectangle();
      break;
    case 3:
      createCube();
      break;
    case 4:
      createCuboid();
      break;
    case 5:
      cout << "Exiting..." << endl;
      return 0;
    default:
      cout << "Invalid choice. Please try again." << endl;
    }
  }

  return 0;
}
