/* CS_SaveFileDialog.cs
Author: BSS9395
Update: 2022-04-30T23:51:00+08@China-Shanghai+08
Design: C# Standard Library: SaveFileDialog
*/

using System;
using System.IO;
using System.Text;
using System.Windows.Forms;

public partial class CS_SaveFileDialog : Form {
    public CS_SaveFileDialog() {
        InitializeComponent();

        tsmi_open.Click += (object sender, EventArgs e) => {
            DialogResult result = ofd_open.ShowDialog();
            string filename = ofd_open.FileName;
            if (result == DialogResult.OK && string.IsNullOrEmpty(filename) == false) {
                StreamReader reader = new StreamReader(filename);
                string text = reader.ReadToEnd();
                tb_notebook.Text = text.Replace("\n", "\r\n");
                reader.Close();
            }
        };

        tsmi_save.Click += (object sender, EventArgs e) => {
            DialogResult result = sfd_save.ShowDialog();
            string filename = sfd_save.FileName;
            if (result == DialogResult.OK && string.IsNullOrEmpty(filename) == false) {
                StreamWriter writer = new StreamWriter(filename, true, new UTF8Encoding(false));
                string text = tb_notebook.Text;
                writer.Write(text.Replace("\r\n", "\n"));
                writer.Close();
            }
        };
    }
}
