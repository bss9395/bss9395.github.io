/* CS_FontDialog.cs
Author: BSS9395
Update: 2022-04-30T23:51:00+08@China-Shanghai+08
Design: C# Standard Library: FontDialog
*/

using System;
using System.Windows.Forms;

public partial class CS_FontDialog : Form {
    public CS_FontDialog() {
        InitializeComponent();

        b_font.Click += (object sender, EventArgs e) => {
            DialogResult result = fd_font.ShowDialog();
            if (result == DialogResult.OK) {
                tb_notebook.Font = fd_font.Font;
            }
        };
    }
}
