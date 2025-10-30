import java.io.File;
import java.io.IOException;
import java.util.Scanner;

public class Authenticator {
    private final File credentialsFile;

    public Authenticator(String filename) {
        this.credentialsFile = new File(filename);
    }

    public boolean validate(String username, String password) throws IOException {
        if (!credentialsFile.exists()) {
            throw new IOException("Credentials file not found.");
        }

        Scanner fileScanner = new Scanner(credentialsFile);
        while (fileScanner.hasNextLine()) {
            String line = fileScanner.nextLine().trim();
            if (line.isEmpty() || !line.contains(":")) continue;
            String[] parts = line.split(":");
            if (parts.length == 2 && parts[0].equals(username) && parts[1].equals(password)) {
                fileScanner.close();
                return true;
            }
        }
        fileScanner.close();
        return false;
    }
}

