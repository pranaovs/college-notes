import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        ArrayList<String> stringList = new ArrayList<>();
        Scanner scanner = new Scanner(System.in);
        StringOperations operations = new StringOperations();
        int choice;

        do {
            System.out.println("\n--- String ArrayList Operations Menu ---");
            System.out.println("1. Append a string");
            System.out.println("2. Insert a string at a particular index");
            System.out.println("3. Search for a string");
            System.out.println("4. List all strings that start with a given letter");
            System.out.println("5. Sort strings in ascending order");
            System.out.println("6. Sort strings in descending order");
            System.out.println("7. Display all strings");
            System.out.println("8. Exit");
            System.out.print("Enter your choice: ");

            choice = scanner.nextInt();
            scanner.nextLine(); // Consume newline

            switch (choice) {
                case 1:
                    operations.appendString(stringList, scanner);
                    break;
                case 2:
                    operations.insertString(stringList, scanner);
                    break;
                case 3:
                    operations.searchString(stringList, scanner);
                    break;
                case 4:
                    operations.listByStartLetter(stringList, scanner);
                    break;
                case 5:
                    operations.sortAscending(stringList);
                    break;
                case 6:
                    operations.sortDescending(stringList);
                    break;
                case 7:
                    operations.displayList(stringList);
                    break;
                case 8:
                    System.out.println("Exiting program.");
                    break;
                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        } while (choice != 8);

        scanner.close();
    }
}
