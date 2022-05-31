/* CS_Flags.cs
Author: BSS9395
Update: 2022-05-31T16:33:00+08@China-Shanghai+08
Design: C# Attribute: Flags
*/

using System;

class CS_Flags {

    [Flags]
    enum Card : uint {
        _diamond = 0x01,
        _club = 0x02,
        _heart = 0x04,
        _spade = 0x08
    }
    public static void Main(String[] args) {
        // _Flags();
        _GetName();
    }
    public static void _Flags() {
        Card card = Card._diamond | Card._club;
        Console.WriteLine($"card._diamond == {card.HasFlag(Card._diamond)}");

        Console.WriteLine($"card._diamond == {(card & Card._diamond) == Card._diamond}");

        Console.WriteLine($"card == {card.ToString()}");
    }
    public static void _GetName() {
        Console.WriteLine($"0x01 member of Card: {Enum.GetName(typeof(Card), 1)}");

        foreach (var name in Enum.GetNames(typeof(Card))) {
            Console.WriteLine(name);
        }
    }
}
