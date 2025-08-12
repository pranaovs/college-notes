class Triangle extends Shape {
  public Triangle(int base, int height) {
    super(base, height);
  }

  @Override
  void printArea() {
    System.out.println("Area of Triangle: " + (0.5 * dim1 * dim2));
  }
}
