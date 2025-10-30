import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter input file name: ");
        String inputFile = sc.nextLine();

        FileInfo fileInfo = new FileInfo(inputFile);
        fileInfo.displayInfo();

        if (fileInfo.exists()) {
            fileInfo.removeSpacesAndWrite("output.txt");
            System.out.println("Spaces removed. Output written to output.txt");
        }

        sc.close();
    }
}

