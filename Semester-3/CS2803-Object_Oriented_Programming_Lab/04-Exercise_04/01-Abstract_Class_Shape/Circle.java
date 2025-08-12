class Circle extends Shape {
  public Circle(int radius) {
    super(radius, 0); // Second dimension not used for circle
  }

  @Override
  void printArea() {
    System.out.println("Area of Circle: " + (Math.PI * dim1 * dim1));
  }
}
