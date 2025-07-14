/* CS_CheckedListBox.cs
Author: BSS9395
Update: 2022-04-30T23:51:00+08@China-Shanghai+08
Design: C# Standard Library: CheckedListBox
*/


using System;
using System.Windows.Forms;

public partial class CS_CheckedListBox : Form {
    public CS_CheckedListBox() {
        InitializeComponent();

        b_submit.Click += (object sender, EventArgs e) => {
            string fruits = "";
            for (int i = 0; i < clb_fruit.CheckedItems.Count; i += 1) {
                if (1 <= i) {
                    fruits += ", ";
                }
                fruits += clb_fruit.CheckedItems[i].ToString();
            }
            string caption = "你的水果";
            MessageBox.Show(fruits, caption, MessageBoxButtons.OK);
        };
    }

}

