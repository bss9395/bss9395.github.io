/* CS_Indexer.cs
Author: BSS9395
Update: 2022-05-12T23:43:00+08@China-Shanghai+08
Design: C# Language Feature: Indexer
*/
class CS_Indexer {
    public string _id = "";
    public string _name = "";
    public string _gender = "";
    public string this[int index] {
        set {
            if (index == 0) {
                _id = value;
            } else if (index == 1) {
                _name = value;
            } else if (index == 2) {
                _gender = value;
            } else {
                throw new ArgumentOutOfRangeException(String.Format("index = {0}", index));
            }
        }
        get {
            if (index == 0) {
                return _id;
            } else if (index == 1) {
                return _name;
            } else if (index == 2) {
                return _gender;
            } else {
                throw new ArgumentOutOfRangeException(String.Format("index = {0}", index));
            }
        }
    }
    public static void Main(String[] args) {
        CS_Indexer indexer = new CS_Indexer();
        indexer[0] = "20220512";
        indexer[1] = "Brilliant";
        indexer[2] = "male";

        Console.WriteLine("indexer[0] = {0}", indexer[0]);
        Console.WriteLine("indexer[1] = {0}", indexer[1]);
        Console.WriteLine("indexer[2] = {0}", indexer[2]);
    }
}
