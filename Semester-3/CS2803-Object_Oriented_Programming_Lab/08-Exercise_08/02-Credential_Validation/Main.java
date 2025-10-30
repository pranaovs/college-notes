import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        if (args.length == 0) {
            System.out.println("No command-line arguments provided.");
            return;
        }

        Scanner sc = new Scanner(System.in);
        System.out.print("Enter username: ");
        String inputUser = sc.nextLine();
        System.out.print("Enter password: ");
        String inputPass = sc.nextLine();

        Authenticator auth = new Authenticator("credentials.txt");

        try {
            if (auth.validate(inputUser, inputPass)) {
                System.out.println("Login successful.");
                writeToFile("output.txt", args);
                System.out.println("Data written to output.txt");
            } else {
                System.out.println("Invalid username or password.");
            }
        } catch (IOException e) {
            System.out.println("Error: " + e.getMessage());
        }

        sc.close();
    }

    private static void writeToFile(String filename, String[] data) throws IOException {
        FileWriter fw = new FileWriter(filename);
        for (String s : data) {
            fw.write(s + " ");
        }
        fw.close();
    }
}

