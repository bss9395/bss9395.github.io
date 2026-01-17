import java.io.IOException;
import java.nio.ByteBuffer;
import java.nio.charset.Charset;
import java.nio.file.FileSystems;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.attribute.*;
import java.util.List;

public class Java_FileAttributeView {
    static public void main(String[] args) {
        // _BasicFileAttributeView();
        // _FileOwnerAttributeView();
        // _UserDefinedFileAttributeView();
        _DosFileAttributeView();
    }
    static public void _BasicFileAttributeView() {
        try {
            Path path = Paths.get(".").toAbsolutePath();
            System.out.println(path);
            BasicFileAttributes attributes = Files.getFileAttributeView(path, BasicFileAttributeView.class).readAttributes();
            System.out.println(attributes.creationTime());
            System.out.println(attributes.lastModifiedTime());
            System.out.println(attributes.lastAccessTime());
            System.out.println(attributes.size());
        } catch(IOException exception) {
            exception.printStackTrace();
        }
    }
    static public void _FileOwnerAttributeView() {
        try {
            Path path = Paths.get(".").toAbsolutePath();
            System.out.println(path);
            FileOwnerAttributeView attributeView = Files.getFileAttributeView(path, FileOwnerAttributeView.class);
            System.out.println(attributeView.getOwner());

            UserPrincipal user = FileSystems.getDefault().getUserPrincipalLookupService().lookupPrincipalByName("guest");
            System.out.println(user);
            // attributeView.setOwner(user);
        } catch(IOException exception) {
            exception.printStackTrace();
        }
    }
    static public void _UserDefinedFileAttributeView() {
        try {
            Path path = Paths.get("src/Java_FileAttributeView.java").toAbsolutePath();
            System.out.println(path);
            UserDefinedFileAttributeView attributeView = Files.getFileAttributeView(path, UserDefinedFileAttributeView.class);
            List<String> attributes = attributeView.list();

            attributeView.write("maker", Charset.forName("UTF-8").encode("Brilliant"));
            for(String attribute: attributes) {
                ByteBuffer buff = ByteBuffer.allocate(attributeView.size(attribute));
                attributeView.read(attribute, buff);
                buff.flip();
                String value = Charset.forName("UTF-8").decode(buff).toString();
                System.out.printf("%20s: %s%n", attribute, value);
            }
        } catch(IOException exception) {
            exception.printStackTrace();
        }
    }
    static public void _DosFileAttributeView() {
        try {
            Path path = Paths.get("src/Java_FileAttributeView.java").toAbsolutePath();
            System.out.println(path);
            DosFileAttributeView attributeView = Files.getFileAttributeView(path, DosFileAttributeView.class);
            attributeView.setHidden(true);
            attributeView.setReadOnly(true);
        } catch(IOException exception) {
            exception.printStackTrace();
        }
    }
}
