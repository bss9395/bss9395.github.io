/* CS_Document_Comment.cs
Author: BSS9395
Update: 2022-05-21T22:35:00+08@China-Shanghai+08
Design: C# Language Feature: Document Comment
*/

using System;

/// <summary>
/// This is class CS_Document_Comment.
/// </summary>
class CS_Document_Comment {
    /// <summary>
    /// This is Field _value.
    /// </summary>
    public static int _value = 0;

    /// <summary>
    /// This is Method Main.
    /// </summary>
    /// <param name="args"></param>
    public static void Main(String[] args) {
        Console.WriteLine($"{nameof(CS_Document_Comment)}.{nameof(Main)}");
    }
}
