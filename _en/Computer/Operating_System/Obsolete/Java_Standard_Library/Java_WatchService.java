/* Java_WatchService.java
Author: BSS9395
Update: 2023-02-12T22:00:00+08@China-Shanghai+08
Design: Java Standard Library: WatchService
*/

import java.io.IOException;
import java.nio.file.*;

public class Java_WatchService {
    static public void main(String[] args) {
        _WatchService();
    }
    static public void _WatchService() {
        try {
            WatchService service = FileSystems.getDefault().newWatchService();
            Path path = Paths.get(".").toAbsolutePath();
            System.out.println(path);
            path.register(service,
                StandardWatchEventKinds.ENTRY_CREATE,
                StandardWatchEventKinds.ENTRY_MODIFY,
                StandardWatchEventKinds.ENTRY_DELETE
            );
            while(true) {
                WatchKey key = service.take();
                for(WatchEvent<?> event : key.pollEvents()) {
                    System.out.printf("%s: %s%n", event.kind(), event.context());
                }
                if(key.reset() == false) {
                    break;
                }
            }
        } catch (IOException exception) {
            exception.printStackTrace();
        } catch(InterruptedException exception) {
            exception.printStackTrace();
        }
    }
}
