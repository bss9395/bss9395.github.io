/* Interpreter.java
Author: BSS9395
Update: 2023-05-26T23:13:00+08@China-Guangdong-Zhanjiang+08
Design: Design Pattern: Interpreter
*/

import java.util.ArrayList;
import java.util.List;

class Context {
    public String             _content      = null;
    public List<AInterpreter> _interpreters = new ArrayList<AInterpreter>();

    public void _Add_Interpreter(AInterpreter interpreter) {
        _interpreters.add(interpreter);
    }

    public List<AInterpreter> _Get_Interpreters() {
        return _interpreters;
    }
}

abstract class AInterpreter {
    abstract public void _Interpret(Context context);
}

class Interpreter_Simple extends AInterpreter {
    @Override
    public void _Interpret(Context context) {
        System.out.println("这是普通解析器!");
    }
}

class Interpreter_Advance extends AInterpreter {
    @Override
    public void _Interpret(Context context) {
        System.out.println("这是高级解析器!");
    }
}

public class Interpreter {
    public static void main(String[] args) {
        Context context = new Context();
        context._Add_Interpreter(new Interpreter_Simple());
        context._Add_Interpreter(new Interpreter_Advance());
        context._Add_Interpreter(new Interpreter_Simple());

        for (AInterpreter interpreter : context._Get_Interpreters()) {
            interpreter._Interpret(context);
        }
    }
}
