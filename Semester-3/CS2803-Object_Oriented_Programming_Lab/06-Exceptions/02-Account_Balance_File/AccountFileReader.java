import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class AccountFileReader {

  public void readAndDisplayBalances(String filename) {
    try {
      // Attempt to open and read the file
      File file = new File(filename);
      Scanner scanner = new Scanner(file);

      System.out.println("Account Balances:");
      System.out.println("-----------------");

      // Read each line of the file
      while (scanner.hasNextLine()) {
        String line = scanner.nextLine();
        System.out.println(line);
      }

      scanner.close();

    } catch (FileNotFoundException e) {
      // Handle the case where the file doesn't exist
      System.out.println("Error: File '" + filename + "' not found.");
      System.out.println("Please ensure the file exists in the correct location.");
    }
  }
}
