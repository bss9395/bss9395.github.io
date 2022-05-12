/* CS_Initializer.cs
Author: BSS9395
Update: 2022-05-12T20:15:00+08@China-Shanghai+08
Design: C# Language Feature: Initializer
*/
class CS_Initializer {
    public string _id = "";
    public CS_Initializer() {
        _id = "20220512";
    }
    public static void Main(string[] args) {
        CS_Initializer init = new CS_Initializer { _id = "20220601" };
        Console.WriteLine("_id = {0}", init._id);
    }
}
