public class Main {
  public static void main(String[] args) {

    // Calculator class with overloaded methods
    Calculator calculator = new Calculator();

    System.out.println("Calculator demonstrations: ");
    System.out.println("add(5, 3): " + calculator.add(5, 3));
    System.out.println("add(5, 3, 2): " + calculator.add(5, 3, 2));
    System.out.println("add(5.5, 3.2): " + calculator.add(5.5, 3.2));
    System.out.println("add(5, 3.2): " + calculator.add(5, 3.2));
    System.out.println("add(5.5, 3): " + calculator.add(5.5, 3));
  }
}
