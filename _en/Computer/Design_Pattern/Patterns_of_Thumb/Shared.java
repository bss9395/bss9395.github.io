/* Shared.java
Author: BSS9395
Update: 2023-05-27T15:17:00+08@China-Guangdong-Zhanjiang+08
Design: Design Pattern: Shared
*/

class Weather {
    public String _weather = "";
}

class District {
    public String _district = null;
    public Weather _weather = null;
    public District(String district) {
        _district = district;
    }

    public void _Set_Weather(Weather weather) {
        _weather = weather;
    }
    public Weather _Get_Weather() {
        return _weather;
    }

    public void _Print_Weather() {
        System.out.printf("[%s：%s]%n", _district, _weather._weather);
    }
}

public class Shared {
    public static void main(String[] args) {
        Weather weather = new Weather();
        District huangpu = new District("黄浦区");
        District tianhe  = new District("天河区");
        huangpu._Set_Weather(weather);
        tianhe._Set_Weather(weather);

        weather._weather = "晴天";
        huangpu._Print_Weather();
        tianhe._Print_Weather();

        weather._weather = "雨天";
        huangpu._Print_Weather();
        tianhe._Print_Weather();
    }
}
