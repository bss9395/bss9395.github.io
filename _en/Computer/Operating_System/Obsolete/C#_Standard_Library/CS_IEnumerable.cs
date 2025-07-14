/* CS_IEnumerable.cs
Author: BSS9395
Update: 2022-06-01T15:35:00+08@China-Shanghai+08
Design: C# Interface: IEnumerable
*/

using System;
using System.Collections;

class CS_IEnumberable {
    class Datum : IEnumerable {
        class Datum_Enumerator : IEnumerator {
            String[] _colors;
            int _position = -1;
            public Datum_Enumerator(String[] colors) {
                _colors = new String[colors.Length];
                for (int i = 0; i < colors.Length; i += 1) {
                    _colors[i] = colors[i];
                }
            }
            public object Current {
                get {
                    if (_position == -1) {
                        throw new InvalidOperationException();
                    }
                    if (_colors.Length <= _position) {
                        throw new InvalidOperationException();
                    }
                    return _colors[_position];
                }
            }
            public bool MoveNext() {
                if (_position < _colors.Length - 1) {
                    _position += 1;
                    return true;
                } else {
                    return false;
                }
            }
            public void Reset() {
                _position = -1;
            }
        }

        public String[] _colors = { "Red", "Yellow", "Blue" };
        public IEnumerator GetEnumerator() {
            return new Datum_Enumerator(_colors);
        }
    }
    public static void Main(String[] args) {
        Datum data = new Datum();
        foreach (String datum in data) {
            Console.WriteLine(datum);
        }
    }
}
