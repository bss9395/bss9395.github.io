
partial class CS_Button {
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
            this.b_submit = new System.Windows.Forms.Button();
            this.b_cancel = new System.Windows.Forms.Button();
            this.l_username = new System.Windows.Forms.Label();
            this.l_password = new System.Windows.Forms.Label();
            this.tb_username = new System.Windows.Forms.TextBox();
            this.tb_password = new System.Windows.Forms.TextBox();
            this.tb_confirm = new System.Windows.Forms.TextBox();
            this.l_confirm = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // b_submit
            // 
            this.b_submit.AutoSize = true;
            this.b_submit.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.b_submit.Location = new System.Drawing.Point(241, 173);
            this.b_submit.Name = "b_submit";
            this.b_submit.Size = new System.Drawing.Size(39, 22);
            this.b_submit.TabIndex = 0;
            this.b_submit.Text = "提交";
            this.b_submit.UseVisualStyleBackColor = true;
            // 
            // b_cancel
            // 
            this.b_cancel.AutoSize = true;
            this.b_cancel.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.b_cancel.Location = new System.Drawing.Point(393, 173);
            this.b_cancel.Name = "b_cancel";
            this.b_cancel.Size = new System.Drawing.Size(39, 22);
            this.b_cancel.TabIndex = 1;
            this.b_cancel.Text = "取消";
            this.b_cancel.UseVisualStyleBackColor = true;
            // 
            // l_username
            // 
            this.l_username.AutoSize = true;
            this.l_username.Location = new System.Drawing.Point(240, 60);
            this.l_username.Name = "l_username";
            this.l_username.Size = new System.Drawing.Size(41, 12);
            this.l_username.TabIndex = 2;
            this.l_username.Text = "账户：";
            // 
            // l_password
            // 
            this.l_password.AutoSize = true;
            this.l_password.Location = new System.Drawing.Point(240, 105);
            this.l_password.Name = "l_password";
            this.l_password.Size = new System.Drawing.Size(41, 12);
            this.l_password.TabIndex = 3;
            this.l_password.Text = "密码：";
            // 
            // tb_username
            // 
            this.tb_username.Location = new System.Drawing.Point(362, 56);
            this.tb_username.Name = "tb_username";
            this.tb_username.Size = new System.Drawing.Size(100, 21);
            this.tb_username.TabIndex = 4;
            // 
            // tb_password
            // 
            this.tb_password.Location = new System.Drawing.Point(362, 101);
            this.tb_password.Name = "tb_password";
            this.tb_password.Size = new System.Drawing.Size(100, 21);
            this.tb_password.TabIndex = 5;
            this.tb_password.UseSystemPasswordChar = true;
            // 
            // tb_confirm
            // 
            this.tb_confirm.Location = new System.Drawing.Point(362, 144);
            this.tb_confirm.Name = "tb_confirm";
            this.tb_confirm.Size = new System.Drawing.Size(100, 21);
            this.tb_confirm.TabIndex = 6;
            this.tb_confirm.UseSystemPasswordChar = true;
            // 
            // l_confirm
            // 
            this.l_confirm.AutoSize = true;
            this.l_confirm.Location = new System.Drawing.Point(240, 148);
            this.l_confirm.Name = "l_confirm";
            this.l_confirm.Size = new System.Drawing.Size(41, 12);
            this.l_confirm.TabIndex = 7;
            this.l_confirm.Text = "确认：";
            // 
            // CS_Button
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.l_confirm);
            this.Controls.Add(this.tb_confirm);
            this.Controls.Add(this.tb_password);
            this.Controls.Add(this.tb_username);
            this.Controls.Add(this.l_password);
            this.Controls.Add(this.l_username);
            this.Controls.Add(this.b_cancel);
            this.Controls.Add(this.b_submit);
            this.Name = "CS_Button";
            this.Text = "CS_Button";
            this.ResumeLayout(false);
            this.PerformLayout();

    }

    #endregion

    private System.Windows.Forms.Button b_submit;
    private System.Windows.Forms.Button b_cancel;
    private System.Windows.Forms.Label l_username;
    private System.Windows.Forms.Label l_password;
    private System.Windows.Forms.TextBox tb_username;
    private System.Windows.Forms.TextBox tb_password;
    private System.Windows.Forms.TextBox tb_confirm;
    private System.Windows.Forms.Label l_confirm;
}
