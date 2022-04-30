partial class CS_RadioButton {
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
            this.rb_shadow = new System.Windows.Forms.RadioButton();
            this.rb_mediate = new System.Windows.Forms.RadioButton();
            this.rb_deep = new System.Windows.Forms.RadioButton();
            this.gb_copy_level = new System.Windows.Forms.GroupBox();
            this.b_submit = new System.Windows.Forms.Button();
            this.gb_copy_level.SuspendLayout();
            this.SuspendLayout();
            // 
            // rb_shadow
            // 
            this.rb_shadow.AutoSize = true;
            this.rb_shadow.Location = new System.Drawing.Point(71, 20);
            this.rb_shadow.Name = "rb_shadow";
            this.rb_shadow.Size = new System.Drawing.Size(59, 16);
            this.rb_shadow.TabIndex = 0;
            this.rb_shadow.TabStop = true;
            this.rb_shadow.Text = "浅拷贝";
            this.rb_shadow.UseVisualStyleBackColor = true;
            // 
            // rb_mediate
            // 
            this.rb_mediate.AutoSize = true;
            this.rb_mediate.Location = new System.Drawing.Point(71, 42);
            this.rb_mediate.Name = "rb_mediate";
            this.rb_mediate.Size = new System.Drawing.Size(59, 16);
            this.rb_mediate.TabIndex = 1;
            this.rb_mediate.TabStop = true;
            this.rb_mediate.Text = "中拷贝";
            this.rb_mediate.UseVisualStyleBackColor = true;
            // 
            // rb_deep
            // 
            this.rb_deep.AutoSize = true;
            this.rb_deep.Location = new System.Drawing.Point(71, 64);
            this.rb_deep.Name = "rb_deep";
            this.rb_deep.Size = new System.Drawing.Size(59, 16);
            this.rb_deep.TabIndex = 2;
            this.rb_deep.TabStop = true;
            this.rb_deep.Text = "深拷贝";
            this.rb_deep.UseVisualStyleBackColor = true;
            // 
            // gb_copy_level
            // 
            this.gb_copy_level.Controls.Add(this.b_submit);
            this.gb_copy_level.Controls.Add(this.rb_shadow);
            this.gb_copy_level.Controls.Add(this.rb_mediate);
            this.gb_copy_level.Controls.Add(this.rb_deep);
            this.gb_copy_level.Location = new System.Drawing.Point(199, 83);
            this.gb_copy_level.Name = "gb_copy_level";
            this.gb_copy_level.Size = new System.Drawing.Size(200, 138);
            this.gb_copy_level.TabIndex = 4;
            this.gb_copy_level.TabStop = false;
            this.gb_copy_level.Text = "拷贝层次";
            // 
            // b_submit
            // 
            this.b_submit.AutoSize = true;
            this.b_submit.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.b_submit.Location = new System.Drawing.Point(81, 86);
            this.b_submit.Name = "b_submit";
            this.b_submit.Size = new System.Drawing.Size(39, 22);
            this.b_submit.TabIndex = 3;
            this.b_submit.Text = "提交";
            this.b_submit.UseVisualStyleBackColor = true;
            // 
            // CS_RadioButton
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.gb_copy_level);
            this.Name = "CS_RadioButton";
            this.Text = "CS_RadioButton";
            this.gb_copy_level.ResumeLayout(false);
            this.gb_copy_level.PerformLayout();
            this.ResumeLayout(false);

    }

    #endregion

    private System.Windows.Forms.RadioButton rb_shadow;
    private System.Windows.Forms.RadioButton rb_mediate;
    private System.Windows.Forms.RadioButton rb_deep;
    private System.Windows.Forms.GroupBox gb_copy_level;
    private System.Windows.Forms.Button b_submit;
}