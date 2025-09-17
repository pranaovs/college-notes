import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    Account account = null;

    try {
      System.out.print("Enter initial balance: ");
      double initialBalance = scanner.nextDouble();

      account = new Account(initialBalance);
      System.out.println("Account created successfully!");

      // Menu
      boolean exit = false;
      while (!exit && account != null) {
        System.out.println("\n1. Deposit");
        System.out.println("2. Withdraw");
        System.out.println("3. Exit");
        System.out.print("Choose an option: ");

        int choice = scanner.nextInt();

        switch (choice) {
          case 1:
            System.out.print("Enter amount to deposit: ");
            account.deposit(scanner.nextDouble());
            break;
          case 2:
            try {
              System.out.print("Enter amount to withdraw: ");
              account.withdraw(scanner.nextDouble());
            } catch (InsufficientBalanceException e) {
              System.out.println("Error: " + e.getMessage());
            }
            break;
          case 3:
            exit = true;
            break;
          default:
            System.out.println("Invalid option!");
        }
      }

    } catch (InsufficientBalanceException e) {
      System.out.println("Account creation failed: " + e.getMessage());
    } finally {
      scanner.close();
    }
  }
}
