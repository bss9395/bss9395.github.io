/* CS_MessageBox.cs
Author: BSS9395
Update: 2022-04-30T23:51:00+08@China-Shanghai+08
Design: C# Standard Library: MessageBox
*/

using System;
using System.Windows.Forms;

public partial class CS_MessageBox : Form {
    public CS_MessageBox() {
        InitializeComponent();

        b_MessageBox.Click += (Object sender, EventArgs eve) => {
            string title = "MessageBox标题";
            string caption = "MessageBox内容";
            DialogResult result = MessageBox.Show(title, caption, MessageBoxButtons.YesNo, MessageBoxIcon.Information, MessageBoxDefaultButton.Button1);
            if (result == DialogResult.No) {
                this.Close();
            }
        };
    }
}

