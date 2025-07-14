/* CS_LinkLabel.cs
Author: BSS9395
Update: 2022-04-30T23:51:00+08@China-Shanghai+08
Design: C# Standard Library: LinkLabel
*/

using System.Windows.Forms;

public partial class CS_LinkLabel : Form {
    public CS_LinkLabel() {
        InitializeComponent();

        ll_link_label.LinkClicked += (object sender, LinkLabelLinkClickedEventArgs e) => {
            string temp = l_label_1.Text;
            l_label_1.Text = l_label_2.Text;
            l_label_2.Text = temp;
        };
    }
}
