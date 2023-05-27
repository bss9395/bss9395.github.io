/* Observer.java
Author: BSS9395
Update: 2023-05-27T14:28:00+08@China-Guangdong-Zhanjiang+08
Design: Design Pattern: Observer
*/

abstract class ACitizen {
    String _district = "";
    abstract void _Send_Message(APoliceman policeman, String help);
}

class Citizen_HuangPu extends ACitizen {
    public Citizen_HuangPu() {
        this._district = "黄埔区";
    }
    @Override
    public void _Send_Message(APoliceman policeman, String help) {
        if(policeman instanceof Policeman_HuangPu) {
            policeman._Action(this, help);
        }
    }
}

class Citizen_TianHe extends ACitizen {
    public Citizen_TianHe() {
        this._district = "天河区";
    }
    @Override
    public void _Send_Message(APoliceman policeman, String help) {
        if(policeman instanceof Policeman_TianHe) {
            policeman._Action(this, help);
        }
    }
}

abstract class APoliceman {
    abstract public void _Action(ACitizen citizen, String help);
}

class Policeman_HuangPu extends APoliceman {
    @Override
    public void _Action(ACitizen citizen, String help) {
        if (help.equals("normal")) {
            System.out.println("一切正常，不用出警！");
        }
        else if (help.equals("unnormal")) {
            System.out.println("有犯罪行为，, 黄埔警察出动！");
        }
    }
}

class Policeman_TianHe extends APoliceman {
    public void _Action(ACitizen citizen, String help) {
        if (help.equals("normal")) {
            System.out.println("一切正常，不用出动！");
        }
        else if (help.equals("unnormal")) {
            System.out.println("有犯罪行为，天河警察出动！");
        }
    }
}

public class Observer {
    public static void main(String[] args) {
        APoliceman policeman_huangpu = new Policeman_HuangPu();
        APoliceman policeman_tianhe  = new Policeman_TianHe();
        ACitizen citizen_huangpu     = new Citizen_HuangPu();
        ACitizen citizen_tianhe      = new Citizen_TianHe();

        citizen_huangpu._Send_Message(policeman_huangpu, "normal");
        citizen_huangpu._Send_Message(policeman_huangpu, "unnormal");
        citizen_huangpu._Send_Message(policeman_tianhe , "normal");
        citizen_huangpu._Send_Message(policeman_tianhe , "unnormal");
        citizen_tianhe._Send_Message(policeman_huangpu , "normal");
        citizen_tianhe._Send_Message(policeman_huangpu , "unnormal");
        citizen_tianhe._Send_Message(policeman_tianhe  , "normal");
        citizen_tianhe._Send_Message(policeman_tianhe  , "unnormal");
    }
}
