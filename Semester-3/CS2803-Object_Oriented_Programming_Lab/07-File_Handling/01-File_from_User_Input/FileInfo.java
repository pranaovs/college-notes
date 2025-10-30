import java.io.File;

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
}

