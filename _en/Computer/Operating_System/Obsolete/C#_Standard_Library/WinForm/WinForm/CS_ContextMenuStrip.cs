/* CS_ContextMenuStrip.cs
Author: BSS9395
Update: 2022-04-30T23:51:00+08@China-Shanghai+08
Design: C# Standard Library: ContextMenuStrip
*/


using System;
using System.Windows.Forms;

public partial class CS_ContextMenuStrip : Form {
    public CS_ContextMenuStrip() {
        InitializeComponent();

        tsmi_open.Click += (object sender, EventArgs e) => {
            cms_menu.Close();
            string caption = tsmi_open.Text;
            string message = "新的窗体";
            MessageBox.Show(message, caption, MessageBoxButtons.OK);
        };

        tsmi_close.Click += (object sender, EventArgs e) => {
            this.Close();
        };
    }
}
