import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter file name: ");
        String filename = sc.nextLine();

        FileInfo fileInfo = new FileInfo(filename);
        fileInfo.displayInfo();

        sc.close();
    }
}

