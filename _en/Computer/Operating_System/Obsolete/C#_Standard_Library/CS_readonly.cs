/* CS_readonly.cs
Author: BSS9395
Update: 2022-05-12T20:34:00+08@China-Shanghai+08
Design: C# Keyword: readonly
*/
class CS_readonly {
    readonly double _pi = Math.PI;
    readonly string _id;
    public CS_readonly(double pi = 3.14, string id = "20220512") {
        _pi = pi;
        _id = id;
    }
    public static void Main(string[] args) {
        CS_readonly read = new CS_readonly();
        Console.WriteLine("_pi = {0}, _id = {1}", read._pi, read._id);
    }
}
