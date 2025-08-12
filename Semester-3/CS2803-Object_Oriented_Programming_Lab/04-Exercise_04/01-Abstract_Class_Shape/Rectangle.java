class Rectangle extends Shape {
  public Rectangle(int length, int width) {
    super(length, width);
  }

  @Override
  void printArea() {
    System.out.println("Area of Rectangle: " + (dim1 * dim2));
  }
}
