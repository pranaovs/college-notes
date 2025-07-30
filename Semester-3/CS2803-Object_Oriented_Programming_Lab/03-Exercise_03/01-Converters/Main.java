import java.util.Scanner;

public class Main {

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    System.out.println("Choose a converter type:");
    System.out.println("  1. Currency Converter (Dollar, Euro, Yen <=> INR)");
    System.out.println("  2. Distance Converter (KM, Meters, Miles)");
    System.out.println("  3. Time Converter (Hours, Minutes, Seconds)");
    System.out.print("Choice: ");

    int choice = scanner.nextInt();

    switch (choice) {
      case 1:
        handleCurrencyConversion(scanner);
        break;
      case 2:
        handleDistanceConversion(scanner);
        break;
      case 3:
        handleTimeConversion(scanner);
        break;
      default:
        System.out.println("Invalid choice. Please run the program again and select 1, 2, or 3.");
    }

    scanner.close(); // Close the opened scanner

  }

  /*
   * Handles the user interaction for all currency conversions.
   */
  private static void handleCurrencyConversion(Scanner scanner) {

    CurrencyConverter converter = new CurrencyConverter();

    System.out.println("    1. Dollar to INR");
    System.out.println("    2. INR to Dollar");
    System.out.println("    3. Euro to INR");
    System.out.println("    4. INR to Euro");
    System.out.println("    5. Yen to INR");
    System.out.println("    6. INR to Yen");
    System.out.print("Choice: ");

    int choice = scanner.nextInt();
    double amount;

    switch (choice) {
      case 1:
        System.out.print("Enter amount in US Dollars: ");
        amount = scanner.nextDouble();
        System.out.printf("%.2f USD is equal to %.2f INR\n", amount, converter.dollarToInr(amount));
        break;
      case 2:
        System.out.print("Enter amount in Indian Rupees: ");
        amount = scanner.nextDouble();
        System.out.printf("%.2f INR is equal to %.2f USD\n", amount, converter.inrToDollar(amount));
        break;
      case 3:
        System.out.print("Enter amount in Euros: ");
        amount = scanner.nextDouble();
        System.out.printf("%.2f EUR is equal to %.2f INR\n", amount, converter.euroToInr(amount));
        break;
      case 4:
        System.out.print("Enter amount in Indian Rupees: ");
        amount = scanner.nextDouble();
        System.out.printf("%.2f INR is equal to %.2f EUR\n", amount, converter.inrToEuro(amount));
        break;
      case 5:
        System.out.print("Enter amount in Japanese Yen: ");
        amount = scanner.nextDouble();
        System.out.printf("%.2f JPY is equal to %.2f INR\n", amount, converter.euroToInr(amount));
        break;
      case 6:
        System.out.print("Enter amount in Indian Rupees: ");
        amount = scanner.nextDouble();
        System.out.printf("%.2f INR is equal to %.2f JPY\n", amount, converter.inrToYen(amount));
        break;
      default:
        System.out.println("Invalid currency conversion choice.");
    }
  }

  /*
   * Handles the user interaction for all distance conversions.
   */
  private static void handleDistanceConversion(Scanner scanner) {

    DistanceConverter converter = new DistanceConverter();

    System.out.println("    1. Meters to Kilometers");
    System.out.println("    2. Kilometers to Meters");
    System.out.println("    3. Miles to Kilometers");
    System.out.println("    4. Kilometers to Miles");
    System.out.println("    5. Miles to Meter");
    System.out.println("    6. Meter to Miles");
    System.out.print("Choice: ");

    int choice = scanner.nextInt();
    double distance;

    switch (choice) {
      case 1:
        System.out.print("Enter distance in Meters: ");
        distance = scanner.nextDouble();
        System.out.printf("%.3f meters is equal to %.3f KM\n", distance, converter.meterToKM(distance));
        break;
      case 2:
        System.out.print("Enter distance in Kilometers: ");
        distance = scanner.nextDouble();
        System.out.printf("%.3f KM is equal to %.3f meters\n", distance, converter.kmToMeter(distance));
        break;
      case 3:
        System.out.print("Enter distance in Miles: ");
        distance = scanner.nextDouble();
        System.out.printf("%.3f miles is equal to %.3f KM\n", distance, converter.milesToKm(distance));
        break;
      case 4:
        System.out.print("Enter distance in Kilometers: ");
        distance = scanner.nextDouble();
        System.out.printf("%.3f KM is equal to %.3f miles\n", distance, converter.kmToMiles(distance));
        break;
      case 5:
        System.out.print("Enter distance in Miles: ");
        distance = scanner.nextDouble();
        System.out.printf("%.3f Miles is equal to %.3f meter\n", distance, converter.milesToMeter(distance));
        break;
      case 6:
        System.out.print("Enter distance in Meter: ");
        distance = scanner.nextDouble();
        System.out.printf("%.3f Meters is equal to %.3f miles\n", distance, converter.meterToMiles(distance));
        break;
      default:
        System.out.println("Invalid distance conversion choice.");
    }
  }

  /*
   * Handles the user interaction for all time conversions.
   */
  private static void handleTimeConversion(Scanner scanner) {

    TimeConverter converter = new TimeConverter();

    System.out.println("    1. Hours to Minutes");
    System.out.println("    2. Minutes to Hours");
    System.out.println("    3. Hours to Seconds");
    System.out.println("    4. Seconds to Hours");
    System.out.println("    5. Minutes to Seconds");
    System.out.println("    6. Seconds to Minutes");
    int choice = scanner.nextInt();
    double time;

    switch (choice) {
      case 1:
        System.out.print("Enter time in Hours: ");
        time = scanner.nextDouble();
        System.out.printf("%.2f hours is equal to %.2f minutes\n", time, converter.hoursToMinutes(time));
        break;
      case 2:
        System.out.print("Enter time in Minutes: ");
        time = scanner.nextDouble();
        System.out.printf("%.2f minutes is equal to %.2f hours\n", time, converter.minutesToHours(time));
        break;
      case 3:
        System.out.print("Enter time in Hours: ");
        time = scanner.nextDouble();
        System.out.printf("%.2f hours is equal to %.2f seconds\n", time, converter.hoursToSeconds(time));
        break;
      case 4:
        System.out.print("Enter time in Seconds: ");
        time = scanner.nextDouble();
        System.out.printf("%.2f seconds is equal to %.2f hours\n", time, converter.secondsToHours(time));
        break;
      case 5:
        System.out.print("Enter time in Minutes: ");
        time = scanner.nextDouble();
        System.out.printf("%.2f minutes is equal to %.2f seconds\n", time, converter.minutesToSeconds(time));
        break;
      case 6:
        System.out.print("Enter time in Seconds: ");
        time = scanner.nextDouble();
        System.out.printf("%.2f seconds is equal to %.2f minutes\n", time, converter.secondsToMinutes(time));
        break;
      default:
        System.out.println("Invalid time conversion choice.");
    }
  }
}