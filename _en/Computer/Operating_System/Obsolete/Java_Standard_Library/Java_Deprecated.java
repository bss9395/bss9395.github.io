class Channel {
    @Deprecated                         // -Xlint:deprecation
    public void connect() {
        System.out.println("***** Channel *****");
    }
}

public class Java_Deprecated {
    @SuppressWarnings({"deprecation"})  // -Xlint:deprecation
    static public void main(String[] args) {
        new Channel().connect();
    }
}
