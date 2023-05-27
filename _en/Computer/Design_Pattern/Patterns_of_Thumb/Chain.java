/* Chain.java
Author: BSS9395
Update: 2023-05-27T15:17:00+08@China-Guangdong-Zhanjiang+08
Design: Design Pattern: Chain
*/

class Receiver {
    public void _Receive() {
        System.out.println("This is Receive class!");
    }
}

abstract class ACommand {
    public Receiver _receiver = null;
    abstract public void _Execute();
}

class Command extends ACommand {
    public Command(Receiver receiver) {
        this._receiver = receiver;
    }

    public void _Execute() {
        _receiver._Receive();
    }
}

class Invoker {
    public ACommand _command = null;
    public void _Set_Command(ACommand command) {
        _command = command;
    }

    public void _Execute() {
        _command._Execute();
    }
}

public class Chain {
    static public void main(String[] args) {
        Invoker  invoker = new Invoker();
        invoker._Set_Command(new Command(new Receiver()));
        invoker._Execute();
    }
}