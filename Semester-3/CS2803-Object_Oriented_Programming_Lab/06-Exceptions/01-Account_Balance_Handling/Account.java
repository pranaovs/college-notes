public class Account {
  private double balance;
  private static final double MIN_BALANCE = 1000.0;

  public Account(double initialBalance)
      throws InsufficientBalanceException {
    this.balance = initialBalance;

    // Check initial balance
    validateBalance();
  }

  public void deposit(double amount) {
    balance += amount;
    System.out.println("Deposited: " + amount);
    System.out.println("New Balance: " + balance);
  }

  public void withdraw(double amount) throws InsufficientBalanceException {
    if (balance - amount < MIN_BALANCE) {
      throw new InsufficientBalanceException(
          "Cannot withdraw " + amount + ". Balance would fall below minimum requirement.");
    }
    balance -= amount;
    System.out.println("Withdrawn: " + amount);
    System.out.println("New Balance: " + balance);
  }

  private void validateBalance() throws InsufficientBalanceException {
    if (balance < MIN_BALANCE) {
      throw new InsufficientBalanceException();
    }
  }
}
