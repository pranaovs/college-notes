public class MaximumFinder {

  public static <T extends Comparable<T>> T findMaximum(T[] array) {
    if (array == null || array.length == 0) {
      throw new IllegalArgumentException("Array cannot be null or empty");
    }

    T max = array[0];
    for (int i = 1; i < array.length; i++) {
      if (array[i].compareTo(max) > 0) {
        max = array[i];
      }
    }
    return max;
  }

  public static <T extends Comparable<T>> T findMaximum(T first, T second, T third) {
    T max = first;
    if (second.compareTo(max) > 0) {
      max = second;
    }
    if (third.compareTo(max) > 0) {
      max = third;
    }
    return max;
  }
}
