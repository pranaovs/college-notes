public class InsufficientBalanceException extends Exception {
  public InsufficientBalanceException() {
    super("Insufficient balance: Balance is below minimum requirement of 1000 rupees");
  }

  public InsufficientBalanceException(String message) {
    super(message);
  }
}
