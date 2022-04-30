/* CS_RichTextBox.cs
Author: BSS9395
Update: 2022-04-30T23:51:00+08@China-Shanghai+08
Design: C# Standard Library: RichTextBox
*/

using System;
using System.Windows.Forms;

public partial class CS_RichTextBox : Form {
    public CS_RichTextBox() {
        InitializeComponent();

        tsmi_open.Click += (object sender, EventArgs e) => {
            DialogResult result = ofd_open.ShowDialog();
            string filename = ofd_open.FileName;
            if (result == DialogResult.OK && string.IsNullOrEmpty(filename) == false) {
                rtb_notebook.LoadFile(filename, RichTextBoxStreamType.PlainText);
            }
        };

        tsmi_save.Click += (object sender, EventArgs e) => {
            DialogResult result = sfd_save.ShowDialog();
            string filename = sfd_save.FileName;
            if (result == DialogResult.OK && string.IsNullOrEmpty(filename) == false) {
                rtb_notebook.SaveFile(filename, RichTextBoxStreamType.PlainText);
            }
        };
    }

}

