/* CS_ColorDialog.cs
Author: BSS9395
Update: 2022-04-30T23:51:00+08@China-Shanghai+08
Design: C# Standard Library: ColorDialog
*/


using System;
using System.Windows.Forms;

public partial class CS_ColorDialog : Form {
    public CS_ColorDialog() {
        InitializeComponent();

        b_change_color.Click += (object sender, EventArgs e) => {
            DialogResult result = cd_color.ShowDialog();
            if (result == DialogResult.OK) {
                tb_notebook.ForeColor = cd_color.Color;
            }
        };
    }
}
