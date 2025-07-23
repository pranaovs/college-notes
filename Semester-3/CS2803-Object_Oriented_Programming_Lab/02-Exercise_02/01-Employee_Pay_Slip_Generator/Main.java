
import java.util.Scanner;

class Employee {
  String empName;
  String empId;
  String address;
  String mailId;
  String mobileNo;

  public void getDetails(Scanner sc) {
    System.out.print("Enter Name: ");
    empName = sc.nextLine();
    System.out.print("Enter ID: ");
    empId = sc.nextLine();
    System.out.print("Enter Address: ");
    address = sc.nextLine();
    System.out.print("Enter Mail ID: ");
    mailId = sc.nextLine();
    System.out.print("Enter Mobile No: ");
    mobileNo = sc.nextLine();
  }

  public void printDetails() {
    System.out.println("Name: " + empName);
    System.out.println("ID: " + empId);
    System.out.println("Address: " + address);
    System.out.println("Mail ID: " + mailId);
    System.out.println("Mobile No: " + mobileNo);
  }
}

class Programmer extends Employee {
  double bp;

  Programmer(double bp) {
    this.bp = bp;
  }

  public void generatePaySlip() {
    double da = 0.97 * bp;
    double hra = 0.10 * bp;
    double pf = 0.12 * bp;
    double staffClubFund = 0.001 * bp;
    double gross = bp + da + hra;
    double net = gross - (pf + staffClubFund);

    System.out.println("\n--- PAY SLIP: Programmer ---");
    printDetails();
    System.out.printf("Basic Pay: %.2f\n", bp);
    System.out.printf("DA: %.2f\n", da);
    System.out.printf("HRA: %.2f\n", hra);
    System.out.printf("PF: %.2f\n", pf);
    System.out.printf("Staff Club Fund: %.2f\n", staffClubFund);
    System.out.printf("Gross Salary: %.2f\n", gross);
    System.out.printf("Net Salary: %.2f\n", net);
  }
}

class AssistantProfessor extends Employee {
  double bp;

  AssistantProfessor(double bp) {
    this.bp = bp;
  }

  public void generatePaySlip() {
    double da = 0.97 * bp;
    double hra = 0.10 * bp;
    double pf = 0.12 * bp;
    double staffClubFund = 0.001 * bp;
    double gross = bp + da + hra;
    double net = gross - (pf + staffClubFund);

    System.out.println("\n--- PAY SLIP: Assistant Professor ---");
    printDetails();
    System.out.printf("Basic Pay: %.2f\n", bp);
    System.out.printf("DA: %.2f\n", da);
    System.out.printf("HRA: %.2f\n", hra);
    System.out.printf("PF: %.2f\n", pf);
    System.out.printf("Staff Club Fund: %.2f\n", staffClubFund);
    System.out.printf("Gross Salary: %.2f\n", gross);
    System.out.printf("Net Salary: %.2f\n", net);
  }
}

class AssociateProfessor extends Employee {
  double bp;

  AssociateProfessor(double bp) {
    this.bp = bp;
  }

  public void generatePaySlip() {
    double da = 0.97 * bp;
    double hra = 0.10 * bp;
    double pf = 0.12 * bp;
    double staffClubFund = 0.001 * bp;
    double gross = bp + da + hra;
    double net = gross - (pf + staffClubFund);

    System.out.println("\n--- PAY SLIP: Associate Professor ---");
    printDetails();
    System.out.printf("Basic Pay: %.2f\n", bp);
    System.out.printf("DA: %.2f\n", da);
    System.out.printf("HRA: %.2f\n", hra);
    System.out.printf("PF: %.2f\n", pf);
    System.out.printf("Staff Club Fund: %.2f\n", staffClubFund);
    System.out.printf("Gross Salary: %.2f\n", gross);
    System.out.printf("Net Salary: %.2f\n", net);
  }
}

class Professor extends Employee {
  double bp;

  Professor(double bp) {
    this.bp = bp;
  }

  public void generatePaySlip() {
    double da = 0.97 * bp;
    double hra = 0.10 * bp;
    double pf = 0.12 * bp;
    double staffClubFund = 0.001 * bp;
    double gross = bp + da + hra;
    double net = gross - (pf + staffClubFund);

    System.out.println("\n--- PAY SLIP: Professor ---");
    printDetails();
    System.out.printf("Basic Pay: %.2f\n", bp);
    System.out.printf("DA: %.2f\n", da);
    System.out.printf("HRA: %.2f\n", hra);
    System.out.printf("PF: %.2f\n", pf);
    System.out.printf("Staff Club Fund: %.2f\n", staffClubFund);
    System.out.printf("Gross Salary: %.2f\n", gross);
    System.out.printf("Net Salary: %.2f\n", net);
  }
}

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    System.out.println("Select Role: ");
    System.out.println("1. Programmer");
    System.out.println("2. Assistant Professor");
    System.out.println("3. Associate Professor");
    System.out.println("4. Professor");
    System.out.print("Enter your choice: ");
    int choice = sc.nextInt();

    System.out.print("Enter Basic Pay: ");
    double bp = sc.nextDouble();
    sc.nextLine(); // consume newline

    switch (choice) {
      case 1:
        Programmer prog = new Programmer(bp);
        prog.getDetails(sc);
        prog.generatePaySlip();
        break;
      case 2:
        AssistantProfessor asst = new AssistantProfessor(bp);
        asst.getDetails(sc);
        asst.generatePaySlip();
        break;
      case 3:
        AssociateProfessor assoc = new AssociateProfessor(bp);
        assoc.getDetails(sc);
        assoc.generatePaySlip();
        break;
      case 4:
        Professor prof = new Professor(bp);
        prof.getDetails(sc);
        prof.generatePaySlip();
        break;
      default:
        System.out.println("Invalid choice.");
    }

    sc.close();
  }
}
