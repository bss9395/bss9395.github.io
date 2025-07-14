/* CS_RadioButton.cs
Author: BSS9395
Update: 2022-04-30T23:51:00+08@China-Shanghai+08
Design: C# Standard Library: RadioButton
*/

using System;
using System.Windows.Forms;

public partial class CS_RadioButton : Form {
    public CS_RadioButton() {
        InitializeComponent();

        b_submit.Click += (object sender, EventArgs e) => {
            string level = "";
            if (rb_shadow.Checked == true) {
                level = rb_shadow.Text;
            } else if (rb_mediate.Checked == true) {
                level = rb_mediate.Text;
            } else if (rb_deep.Checked == true) {
                level = rb_deep.Text;
            }
            string caption = "你的选择";
            MessageBox.Show(level, caption, MessageBoxButtons.OK);
        };
    }

}

