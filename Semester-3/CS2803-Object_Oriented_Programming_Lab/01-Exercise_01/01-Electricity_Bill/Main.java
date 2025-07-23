import java.util.Scanner;

class ElectricityBill {
  int consumerNo;
  String consumerName;
  int prevReading;
  int currReading;
  String ebConnectionType;
  double amount;

  ElectricityBill(int consumerNo, String consumerName, int prevReading, int currReading, String ebConnectionType) {
    this.consumerNo = consumerNo;
    this.consumerName = consumerName;
    this.prevReading = prevReading;
    this.currReading = currReading;
    this.ebConnectionType = ebConnectionType.toLowerCase();
    this.amount = 0.0;
  }

  public void calculateBill() {
    int units = currReading - prevReading;

    if (units < 0) {
      System.out.println("Error: Current reading should be greater than or equal to previous reading.");
      return;
    }

    if (ebConnectionType.equals("domestic")) {
      if (units <= 100)
        amount = units * 1;
      else if (units <= 200)
        amount = 100 * 1 + (units - 100) * 2.5;
      else if (units <= 500)
        amount = 100 * 1 + 100 * 2.5 + (units - 200) * 4;
      else
        amount = 100 * 1 + 100 * 2.5 + 300 * 4 + (units - 500) * 6;
    } else if (ebConnectionType.equals("commercial")) {
      if (units <= 100)
        amount = units * 2;
      else if (units <= 200)
        amount = 100 * 2 + (units - 100) * 4.5;
      else if (units <= 500)
        amount = 100 * 2 + 100 * 4.5 + (units - 200) * 6;
      else
        amount = 100 * 2 + 100 * 4.5 + 300 * 6 + (units - 500) * 7;
    } else {
      System.out.println("Invalid EB connection type. Should be either 'domestic' or 'commercial'.");
    }
  }

  public void printBill() {
    System.out.println("\n-------- Electricity Bill --------");
    System.out.println("Consumer No.: " + consumerNo);
    System.out.println("Consumer Name: " + consumerName);
    System.out.println("Previous Reading: " + prevReading);
    System.out.println("Current Reading: " + currReading);
    System.out.println("Connection Type: " + ebConnectionType);
    System.out.println("Units Consumed: " + (currReading - prevReading));
    System.out.printf("Total Amount to Pay: Rs. %.2f%n", amount);
    System.out.println("----------------------------------");
  }
}

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    System.out.print("Enter Consumer Number: ");
    int consumerNo = sc.nextInt();

    sc.nextLine(); // consume newline

    System.out.print("Enter Consumer Name: ");
    String consumerName = sc.nextLine();

    System.out.print("Enter Previous Month Reading: ");
    int prevReading = sc.nextInt();

    System.out.print("Enter Current Month Reading: ");
    int currReading = sc.nextInt();

    sc.nextLine(); // consume newline

    System.out.print("Enter Connection Type (domestic/commercial): ");
    String type = sc.nextLine();

    ElectricityBill bill = new ElectricityBill(consumerNo, consumerName, prevReading, currReading, type);

    bill.calculateBill();
    bill.printBill();

    sc.close();
  }
}
