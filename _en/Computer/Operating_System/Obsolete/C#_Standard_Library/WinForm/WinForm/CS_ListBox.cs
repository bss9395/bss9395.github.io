/* CS_ListBox.cs
Author: BSS9395
Update: 2022-04-30T23:51:00+08@China-Shanghai+08
Design: C# Standard Library: ListBox
*/

using System;
using System.Windows.Forms;

public partial class CS_ListBox : Form {
    public CS_ListBox() {
        InitializeComponent();

        b_add.Click += (object sender, EventArgs e) => {
            if (0 < tb_add.Text.Length) {
                lb_hobby.Items.Add(tb_add.Text);
            }
            tb_add.Clear();
        };

        b_submit.Click += (object sender, EventArgs e) => {
            string hobbies = "";
            for (int i = 0; i < lb_hobby.SelectedItems.Count; i += 1) {
                if (1 <= i) {
                    hobbies += ", ";
                }
                hobbies += lb_hobby.SelectedItems[i].ToString();
            }
            string caption = "你的爱好";
            MessageBox.Show(hobbies, caption, MessageBoxButtons.OK);
        };

        b_remove.Click += (object sender, EventArgs e) => {
            while (0 < lb_hobby.SelectedIndices.Count) {
                lb_hobby.Items.RemoveAt(lb_hobby.SelectedIndex);
            }
        };
    }
}
