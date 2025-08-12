public class Main {
  public static void main(String[] args) {
    // Create shapes
    Rectangle rectangle = new Rectangle(5, 4);
    Triangle triangle = new Triangle(6, 3);
    Circle circle = new Circle(5);

    // Print areas
    System.out.println("Demonstrating different shape areas:");
    rectangle.printArea();
    triangle.printArea();
    circle.printArea();
  }
}
