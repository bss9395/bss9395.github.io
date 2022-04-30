/* CS_Label.cs
Author: BSS9395
Update: 2022-04-30T23:51:00+08@China-Shanghai+08
Design: C# Standard Library: Label
*/

using System.Windows.Forms;

public partial class CS_Label : Form {
    public CS_Label() {
        InitializeComponent();

        ll_link_label.LinkClicked += (object sender, LinkLabelLinkClickedEventArgs e) => {
            string title = "MessageBox标题";
            string caption = "MessageBox内容";
            DialogResult result = MessageBox.Show(title, caption, MessageBoxButtons.YesNo, MessageBoxIcon.Information, MessageBoxDefaultButton.Button1);
            if (result == DialogResult.No) {
                this.Close();
            }
        };
    }
}
