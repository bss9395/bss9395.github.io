/* Handler.java
Author: BSS9395
Update: 2023-05-26T22:34:00+08@China-Guangdong-Zhanjiang+08
Design: Design Pattern: Handler
*/

abstract class ARequest {

}
class Request extends ARequest {

}
class Request_Resignation extends ARequest {

}
class Request_Salary extends ARequest {

}
class Request_Leave extends ARequest {

}


abstract class AHandler {
    public AHandler _senior = null;
    abstract public void _Handle(ARequest request);
}

class Handler_HR extends AHandler {
    @Override
    public void _Handle(ARequest request) {
        if (request instanceof Request_Resignation) {
            System.out.println("要离职，人事审批！");
        }
        System.out.println("请求完毕！");
    }
}

class Handler_PM extends AHandler {
    public Handler_PM(AHandler handler) {
        this._senior = handler;
    }
    @Override
    public void _Handle(ARequest request) {
        if (request instanceof Request_Salary) {
            System.out.println("要加薪，项目经理审批！");
        } else {
            _senior._Handle(request);
        }
    }
}

class Handler_TL extends AHandler {
    public Handler_TL(AHandler handler) {
        this._senior = handler;
    }
    @Override
    public void _Handle(ARequest request) {
        if (request instanceof Request_Leave) {
            System.out.println("要请假, 项目组长审批!");
        } else {
            _senior._Handle(request);
        }
    }
}

public class Handler {
    public static void main(String[] args) {
        AHandler handler_hr = new Handler_HR();
        AHandler handler_pm = new Handler_PM(handler_hr);
        AHandler handler_tl = new Handler_TL(handler_pm);

        handler_tl._Handle(new Request_Resignation());
        handler_tl._Handle(new Request_Salary());
        handler_pm._Handle(new Request_Resignation());
    }
}
