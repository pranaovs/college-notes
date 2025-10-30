import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;

public class FileInfo {
    private final File file;

    public FileInfo(String filename) {
        this.file = new File(filename);
    }

    public void displayInfo() {
        if (!file.exists()) {
            System.out.println("File does not exist.");
            return;
        }

        System.out.println("File exists: " + file.exists());
        System.out.println("Readable: " + file.canRead());
        System.out.println("Writable: " + file.canWrite());
        System.out.println("Type: " + (file.isDirectory() ? "Directory" : "File"));
        System.out.println("Length (bytes): " + file.length());
    }

    public boolean exists() {
        return file.exists();
    }

    public void removeSpacesAndWrite(String outputFilename) {
        if (!file.exists() || file.isDirectory()) {
            System.out.println("Cannot process: not a valid file.");
            return;
        }

        try {
            String content = new String(Files.readAllBytes(Paths.get(file.getPath())));
            String noSpaces = content.replaceAll("\\s+", "");
            FileWriter writer = new FileWriter(outputFilename);
            writer.write(noSpaces);
            writer.close();
        } catch (IOException e) {
            System.out.println("Error processing file: " + e.getMessage());
        }
    }
}

