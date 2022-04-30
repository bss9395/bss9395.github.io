
partial class CS_ColorDialog {
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
            this.tb_notebook = new System.Windows.Forms.TextBox();
            this.b_change_color = new System.Windows.Forms.Button();
            this.cd_color = new System.Windows.Forms.ColorDialog();
            this.SuspendLayout();
            // 
            // tb_notebook
            // 
            this.tb_notebook.Location = new System.Drawing.Point(66, 38);
            this.tb_notebook.Multiline = true;
            this.tb_notebook.Name = "tb_notebook";
            this.tb_notebook.Size = new System.Drawing.Size(356, 254);
            this.tb_notebook.TabIndex = 0;
            // 
            // b_change_color
            // 
            this.b_change_color.AutoSize = true;
            this.b_change_color.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.b_change_color.Location = new System.Drawing.Point(225, 315);
            this.b_change_color.Name = "b_change_color";
            this.b_change_color.Size = new System.Drawing.Size(63, 22);
            this.b_change_color.TabIndex = 1;
            this.b_change_color.Text = "文本颜色";
            this.b_change_color.UseVisualStyleBackColor = true;
            // 
            // CS_ColorDialog
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.b_change_color);
            this.Controls.Add(this.tb_notebook);
            this.Name = "CS_ColorDialog";
            this.Text = "CS_ColorDialog";
            this.ResumeLayout(false);
            this.PerformLayout();

    }

    #endregion

    private System.Windows.Forms.TextBox tb_notebook;
    private System.Windows.Forms.Button b_change_color;
    private System.Windows.Forms.ColorDialog cd_color;
}
