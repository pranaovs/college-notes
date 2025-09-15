import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class StringOperations {
  
    public void appendString(ArrayList<String> list, Scanner scanner) {
        System.out.print("Enter the string to append: ");
        String str = scanner.nextLine();
        list.add(str);
        System.out.println("String appended successfully.");
    }

    public void insertString(ArrayList<String> list, Scanner scanner) {
        System.out.print("Enter the string to insert: ");
        String str = scanner.nextLine();
        System.out.print("Enter the index to insert at: ");
        int index = scanner.nextInt();
        scanner.nextLine(); // Consume newline

        if (index >= 0 && index <= list.size()) {
            list.add(index, str);
            System.out.println("String inserted successfully.");
        } else {
            System.out.println("Invalid index. Index should be between 0 and " + list.size());
        }
    }

    public void searchString(ArrayList<String> list, Scanner scanner) {
        System.out.print("Enter the string to search for: ");
        String str = scanner.nextLine();
        int index = list.indexOf(str);
        if (index != -1) {
            System.out.println("String '" + str + "' found at index: " + index);
        } else {
            System.out.println("String '" + str + "' not found in the list.");
        }
    }

    public void listByStartLetter(ArrayList<String> list, Scanner scanner) {
        System.out.print("Enter the starting letter to search for: ");
        String letter = scanner.nextLine();
        System.out.println("Strings starting with '" + letter + "':");
        boolean found = false;
        for (String str : list) {
            if (str.startsWith(letter)) {
                System.out.println("- " + str);
                found = true;
            }
        }
        if (!found) {
            System.out.println("No strings found starting with that letter.");
        }
    }

    public void sortAscending(ArrayList<String> list) {
        Collections.sort(list);
        System.out.println("List sorted in ascending order.");
        displayList(list);
    }

    public void sortDescending(ArrayList<String> list) {
        Collections.sort(list, Collections.reverseOrder());
        System.out.println("List sorted in descending order.");
        displayList(list);
    }

    public void displayList(ArrayList<String> list) {
        System.out.println("\nCurrent List:");
        if (list.isEmpty()) {
            System.out.println("The list is empty.");
        } else {
            for (int i = 0; i < list.size(); i++) {
                System.out.println(i + ": " + list.get(i));
            }
        }
    }
}
