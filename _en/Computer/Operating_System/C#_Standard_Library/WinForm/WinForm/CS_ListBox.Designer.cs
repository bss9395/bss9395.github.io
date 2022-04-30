
partial class CS_ListBox {
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
            this.lb_hobby = new System.Windows.Forms.ListBox();
            this.b_submit = new System.Windows.Forms.Button();
            this.tb_add = new System.Windows.Forms.TextBox();
            this.b_add = new System.Windows.Forms.Button();
            this.b_remove = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // lb_hobby
            // 
            this.lb_hobby.FormattingEnabled = true;
            this.lb_hobby.ItemHeight = 12;
            this.lb_hobby.Items.AddRange(new object[] {
            "篮球",
            "排球",
            "羽毛球",
            "乒乓球",
            "游泳",
            "阅读",
            "写作"});
            this.lb_hobby.Location = new System.Drawing.Point(280, 53);
            this.lb_hobby.Name = "lb_hobby";
            this.lb_hobby.SelectionMode = System.Windows.Forms.SelectionMode.MultiSimple;
            this.lb_hobby.Size = new System.Drawing.Size(241, 160);
            this.lb_hobby.TabIndex = 0;
            // 
            // b_submit
            // 
            this.b_submit.AutoSize = true;
            this.b_submit.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.b_submit.Location = new System.Drawing.Point(320, 218);
            this.b_submit.Name = "b_submit";
            this.b_submit.Size = new System.Drawing.Size(39, 22);
            this.b_submit.TabIndex = 1;
            this.b_submit.Text = "提交";
            this.b_submit.UseVisualStyleBackColor = true;
            // 
            // tb_add
            // 
            this.tb_add.Location = new System.Drawing.Point(280, 26);
            this.tb_add.Name = "tb_add";
            this.tb_add.Size = new System.Drawing.Size(196, 21);
            this.tb_add.TabIndex = 2;
            // 
            // b_add
            // 
            this.b_add.AutoSize = true;
            this.b_add.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.b_add.Location = new System.Drawing.Point(482, 24);
            this.b_add.Name = "b_add";
            this.b_add.Size = new System.Drawing.Size(39, 22);
            this.b_add.TabIndex = 3;
            this.b_add.Text = "添加";
            this.b_add.UseVisualStyleBackColor = true;
            // 
            // b_remove
            // 
            this.b_remove.AutoSize = true;
            this.b_remove.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.b_remove.Location = new System.Drawing.Point(410, 218);
            this.b_remove.Name = "b_remove";
            this.b_remove.Size = new System.Drawing.Size(39, 22);
            this.b_remove.TabIndex = 4;
            this.b_remove.Text = "移除";
            this.b_remove.UseVisualStyleBackColor = true;
            // 
            // CS_ListBox
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.b_remove);
            this.Controls.Add(this.b_add);
            this.Controls.Add(this.tb_add);
            this.Controls.Add(this.b_submit);
            this.Controls.Add(this.lb_hobby);
            this.Name = "CS_ListBox";
            this.Text = "CS_ListBox";
            this.ResumeLayout(false);
            this.PerformLayout();

    }

    #endregion

    private System.Windows.Forms.ListBox lb_hobby;
    private System.Windows.Forms.Button b_submit;
    private System.Windows.Forms.TextBox tb_add;
    private System.Windows.Forms.Button b_add;
    private System.Windows.Forms.Button b_remove;
}
