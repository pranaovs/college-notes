public class Main {
  public static void main(String[] args) {
    // Create an instance of the balance reader
    AccountFileReader reader = new AccountFileReader();

    // Try to read and display account balances
    reader.readAndDisplayBalances("account_balances.txt");
  }
}
