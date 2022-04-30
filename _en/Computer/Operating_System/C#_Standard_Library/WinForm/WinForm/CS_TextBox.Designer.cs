partial class CS_TextBox {
    /// <summary>
    /// Required designer variable.
    /// </summary>
    private System.ComponentModel.IContainer components = null;

    /// <summary>
    /// Clean up any resources being used.
    /// </summary>
    /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
    protected override void Dispose(bool disposing) {
        if (disposing && (components != null)) {
            components.Dispose();
        }
        base.Dispose(disposing);
    }

    #region Windows Form Designer generated code

    /// <summary>
    /// Required method for Designer support - do not modify
    /// the contents of this method with the code editor.
    /// </summary>
    private void InitializeComponent() {
            this.l_username = new System.Windows.Forms.Label();
            this.tb_username = new System.Windows.Forms.TextBox();
            this.l_password = new System.Windows.Forms.Label();
            this.tb_password = new System.Windows.Forms.TextBox();
            this.ll_Login = new System.Windows.Forms.LinkLabel();
            this.SuspendLayout();
            // 
            // l_username
            // 
            this.l_username.AutoSize = true;
            this.l_username.Location = new System.Drawing.Point(218, 116);
            this.l_username.Name = "l_username";
            this.l_username.Size = new System.Drawing.Size(41, 12);
            this.l_username.TabIndex = 0;
            this.l_username.Text = "账号：";
            // 
            // tb_username
            // 
            this.tb_username.Location = new System.Drawing.Point(350, 112);
            this.tb_username.Name = "tb_username";
            this.tb_username.Size = new System.Drawing.Size(100, 21);
            this.tb_username.TabIndex = 1;
            // 
            // l_password
            // 
            this.l_password.AutoSize = true;
            this.l_password.Location = new System.Drawing.Point(218, 142);
            this.l_password.Name = "l_password";
            this.l_password.Size = new System.Drawing.Size(41, 12);
            this.l_password.TabIndex = 2;
            this.l_password.Text = "密码：";
            // 
            // tb_password
            // 
            this.tb_password.Location = new System.Drawing.Point(350, 138);
            this.tb_password.Name = "tb_password";
            this.tb_password.Size = new System.Drawing.Size(100, 21);
            this.tb_password.TabIndex = 3;
            // 
            // ll_Login
            // 
            this.ll_Login.AutoSize = true;
            this.ll_Login.Location = new System.Drawing.Point(284, 192);
            this.ll_Login.Name = "ll_Login";
            this.ll_Login.Size = new System.Drawing.Size(29, 12);
            this.ll_Login.TabIndex = 4;
            this.ll_Login.TabStop = true;
            this.ll_Login.Text = "登录";
            // 
            // CS_TextBox
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.ll_Login);
            this.Controls.Add(this.tb_password);
            this.Controls.Add(this.l_password);
            this.Controls.Add(this.tb_username);
            this.Controls.Add(this.l_username);
            this.Name = "CS_TextBox";
            this.Text = "CS_TextBox";
            this.ResumeLayout(false);
            this.PerformLayout();

    }

    #endregion

    private System.Windows.Forms.Label l_username;
    private System.Windows.Forms.TextBox tb_username;
    private System.Windows.Forms.Label l_password;
    private System.Windows.Forms.TextBox tb_password;
    private System.Windows.Forms.LinkLabel ll_Login;
}
