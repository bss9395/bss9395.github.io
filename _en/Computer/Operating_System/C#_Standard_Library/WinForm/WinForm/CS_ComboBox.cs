/* CS_ComboBox.cs
Author: BSS9395
Update: 2022-04-30T23:51:00+08@China-Shanghai+08
Design: C# Standard Library: ComboBox
*/


using System;
using System.Windows.Forms;

public partial class CS_ComboBox : Form {
    public CS_ComboBox() {
        InitializeComponent();

        cb_major.Items.Add("计算机应用");
        cb_major.Items.Add("英语");
        cb_major.Items.Add("会计");
        cb_major.Items.Add("软件工程");
        cb_major.Items.Add("网络工程");

        cb_major.SelectedIndexChanged += (object sender, EventArgs e) => {
            string caption = "你的专业";
            string major = cb_major.Text;
            MessageBox.Show(major, caption, MessageBoxButtons.OK);
        };

        b_add.Click += (object sender, EventArgs e) => {
            if (0 < tb_major.Text.Length) {
                cb_major.Items.Add(tb_major.Text);
            }
        };

        b_remove.Click += (object sender, EventArgs e) => {
            cb_major.Items.Remove(tb_major.Text);
        };
    }
}
