/* CS_Button.cs
Author: BSS9395
Update: 2022-04-30T23:51:00+08@China-Shanghai+08
Design: C# Standard Library: Button
*/

using System;
using System.Windows.Forms;

public partial class CS_Button : Form {
    public CS_Button() {
        InitializeComponent();

        b_submit.Click += (object sender, EventArgs e) => {
            string username = tb_username.Text;
            string password = tb_password.Text;
            string confirm = tb_confirm.Text;
            if (string.IsNullOrEmpty(username) == true) {
                string caption = "消息";
                string message = "账户不可为空！";
                MessageBox.Show(message, caption, MessageBoxButtons.OK);
                return;
            }
            if (string.IsNullOrEmpty(password) == true) {
                string caption = "消息";
                string message = "账户不可为空！";
                MessageBox.Show(message, caption, MessageBoxButtons.OK);
                return;
            }
            if (password.Equals(confirm) == false) {
                string caption = "消息";
                string message = "密码前后不一致！";
                MessageBox.Show(message, caption, MessageBoxButtons.OK);
                return;
            }
        };

        b_cancel.Click += (object sender, EventArgs e) => {
            this.Close();
        };
    }
}

