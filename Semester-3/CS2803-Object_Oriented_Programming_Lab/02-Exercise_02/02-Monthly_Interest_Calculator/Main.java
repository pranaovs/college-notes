
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Get inputs
        System.out.print("Enter Loan Amount: ");
        double loanAmount = sc.nextDouble();

        System.out.print("Enter Number of Years: ");
        int years = sc.nextInt();

        System.out.print("Enter Annual Interest Rate (in %): ");
        double annualInterestRate = sc.nextDouble();

        // Calculations
        double monthlyInterestRate = annualInterestRate / 1200;
        int numberOfPayments = years * 12;

        double monthlyPayment = loanAmount * monthlyInterestRate /
                (1 - Math.pow(1 + monthlyInterestRate, -numberOfPayments));

        double totalPayment = monthlyPayment * numberOfPayments;

        System.out.printf("\nMonthly Payment: %.2f\n", monthlyPayment);
        System.out.printf("Total Payment: %.2f\n\n", totalPayment);

        System.out.printf("%-10s%-12s%-12s%-12s\n", "Payment#", "Interest", "Principal", "Balance");

        double balance = loanAmount;

        for (int i = 1; i <= numberOfPayments; i++) {
            double interest = monthlyInterestRate * balance;
            double principal = monthlyPayment - interest;
            balance -= principal;

            System.out.printf("%-10d%-12.2f%-12.2f%-12.2f\n", i, interest, principal, balance);
        }

        sc.close();
    }
}
