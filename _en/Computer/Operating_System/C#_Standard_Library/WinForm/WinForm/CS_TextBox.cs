/* CS_TextBox.cs
Author: BSS9395
Update: 2022-04-30T23:51:00+08@China-Shanghai+08
Design: C# Standard Library: TextBox
*/

using System.Windows.Forms;

public partial class CS_TextBox : Form {
    public CS_TextBox() {
        InitializeComponent();

        ll_Login.LinkClicked += (object sender, LinkLabelLinkClickedEventArgs e) => {
            string username = tb_username.Text;
            string password = tb_password.Text;
            if (username.Equals("bss9395") && password.Equals("123456")) {
                string caption = "消息";
                string message = "登录成功！";
                MessageBox.Show(message, caption, MessageBoxButtons.OK);
            } else {
                string caption = "消息";
                string message = "登录失败！";
                MessageBox.Show(message, caption, MessageBoxButtons.OK);
            }
        };
    }
}

