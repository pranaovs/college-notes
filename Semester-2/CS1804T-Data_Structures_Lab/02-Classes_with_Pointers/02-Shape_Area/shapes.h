// C++ class definitions for various shapes

class Cube {

private:
  int side;

public:
  /* Constructor to initialize the side of the cube
   * Arguments:
   * int side: side length of the cube
   */
  Cube(int side) { this->side = side; }

  /* Function to calculate the surface area of a cube
   * Arguments:
   * None
   * Returns:
   * int: surface area of the cube
   */
  int area() { return 6 * side * side; }
};

class Rectangle {
private:
  int length;
  int width;

public:
  /* Constructor to initialize the length and width of the rectangle
   * Arguments:
   * int length: length of the rectangle
   * int width: width of the rectangle
   */
  Rectangle(int length, int width) {
    this->length = length;
    this->width = width;
  }

  /* Function to calculate the area of a rectangle
   * Arguments:
   * None
   * Returns:
   * int: area of the rectangle
   */
  int area() { return length * width; }
};

class Square {
private:
  int side;

public:
  /* Constructor to initialize the side of the square
   * Arguments:
   * int side: side length of the square
   */
  Square(int side) { this->side = side; }

  /* Function to calculate the area of a square
   * Arguments:
   * None
   * Returns:
   * int: area of the square
   */
  int area() { return side * side; }
};

class Cuboid {

private:
  int length;
  int width;
  int height;

public:
  /* Constructor to initialize the dimensions of the cuboid
   * Arguments:
   * int length: length of the cuboid
   * int width: width of the cuboid
   * int height: height of the cuboid
   */
  Cuboid(int length, int width, int height) {
    this->length = length;
    this->width = width;
    this->height = height;
  }

  /* Function to calculate the surface area of a cuboid
   * Arguments:
   * None
   * Returns:
   * int: surface area of the cuboid
   */
  int area() { return 2 * (length * width + width * height + height * length); }
};

// class Areas {
//
// public:
//   /* Function to calculate the area of a square
//    * Arguments:
//    * int side: side of the square
//    * Returns:
//    * int: area of the square
//    */
//   int square(int side) { return side * side; }
//
//   /* Function to calculate the surface area of a cube
//    * Arguments:
//    * int side: side length of the cube
//    * Returns:
//    * int: surface area of the cube
//    */
//   int cube(int side) { return 6 * side * side; }
//
//   /* Function to calculate the area of a rectangle
//    * Arguments:
//    * int length: length of the rectangle
//    * int breadth: breadth of the rectangle
//    * Returns:
//    * int: area of the rectangle
//    */
//   int rectangle(int length, int breadth) { return length * breadth; }
//
//   /* Function to calculate the surface area of a cuboid
//    * Arguments:
//    * int length: length of the cuboid
//    * int breadth: breadth of the cuboid
//    * int height: height of the cuboid
//    * Returns:
//    * int: surface area of the cuboid
//    */
//   int cuboid(int length, int breadth, int height) {
//     return 2 * (length * breadth + breadth * height + height * length);
//   }
// };
