public class Main {
  public static void main(String[] args) {
    System.out.println("=== Finding Maximum Values Using Generics ===\n");

    Integer[] intArray = { 5, 2, 9, 1, 7, 3 };
    System.out.println("Integer Array: ");
    printArray(intArray);
    System.out.println("Maximum: " + MaximumFinder.findMaximum(intArray));

    System.out.println("\n---");

    Double[] doubleArray = { 3.14, 2.71, 9.81, 1.41, 6.28 };
    System.out.println("Double Array: ");
    printArray(doubleArray);
    System.out.println("Maximum: " + MaximumFinder.findMaximum(doubleArray));

    System.out.println("\n---");

    String[] stringArray = { "apple", "zebra", "mango", "banana", "orange" };
    System.out.println("String Array: ");
    printArray(stringArray);
    System.out.println("Maximum: " + MaximumFinder.findMaximum(stringArray));

    System.out.println("\n---");

    Character[] charArray = { 'a', 'z', 'm', 'b', 'x' };
    System.out.println("Character Array: ");
    printArray(charArray);
    System.out.println("Maximum: " + MaximumFinder.findMaximum(charArray));

    System.out.println("\n=== Finding Maximum of Three Values ===\n");

    System.out.println("Max of (10, 25, 15): " + MaximumFinder.findMaximum(10, 25, 15));
    System.out.println("Max of (3.5, 2.1, 8.9): " + MaximumFinder.findMaximum(3.5, 2.1, 8.9));
    System.out.println("Max of ('x', 'a', 'z'): " + MaximumFinder.findMaximum('x', 'a', 'z'));
    System.out.println("Max of (\"cat\", \"dog\", \"ant\"): " + MaximumFinder.findMaximum("cat", "dog", "ant"));
  }

  private static <T> void printArray(T[] array) {
    for (T element : array) {
      System.out.print(element + " ");
    }
    System.out.println();
  }
}
