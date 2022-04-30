partial class CS_ComboBox {
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
            this.cb_major = new System.Windows.Forms.ComboBox();
            this.tb_major = new System.Windows.Forms.TextBox();
            this.b_add = new System.Windows.Forms.Button();
            this.b_remove = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // cb_major
            // 
            this.cb_major.FormattingEnabled = true;
            this.cb_major.Location = new System.Drawing.Point(188, 183);
            this.cb_major.Name = "cb_major";
            this.cb_major.Size = new System.Drawing.Size(244, 20);
            this.cb_major.TabIndex = 0;
            // 
            // tb_major
            // 
            this.tb_major.Location = new System.Drawing.Point(188, 133);
            this.tb_major.Name = "tb_major";
            this.tb_major.Size = new System.Drawing.Size(154, 21);
            this.tb_major.TabIndex = 1;
            // 
            // b_add
            // 
            this.b_add.AutoSize = true;
            this.b_add.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.b_add.Location = new System.Drawing.Point(348, 133);
            this.b_add.Name = "b_add";
            this.b_add.Size = new System.Drawing.Size(39, 22);
            this.b_add.TabIndex = 2;
            this.b_add.Text = "添加";
            this.b_add.UseVisualStyleBackColor = true;
            // 
            // b_remove
            // 
            this.b_remove.AutoSize = true;
            this.b_remove.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.b_remove.Location = new System.Drawing.Point(393, 133);
            this.b_remove.Name = "b_remove";
            this.b_remove.Size = new System.Drawing.Size(39, 22);
            this.b_remove.TabIndex = 3;
            this.b_remove.Text = "删除";
            this.b_remove.UseVisualStyleBackColor = true;
            // 
            // CS_ComboBox
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.b_remove);
            this.Controls.Add(this.b_add);
            this.Controls.Add(this.tb_major);
            this.Controls.Add(this.cb_major);
            this.Name = "CS_ComboBox";
            this.Text = "CS_ComboBox";
            this.ResumeLayout(false);
            this.PerformLayout();

    }

    #endregion

    private System.Windows.Forms.ComboBox cb_major;
    private System.Windows.Forms.TextBox tb_major;
    private System.Windows.Forms.Button b_add;
    private System.Windows.Forms.Button b_remove;
}
