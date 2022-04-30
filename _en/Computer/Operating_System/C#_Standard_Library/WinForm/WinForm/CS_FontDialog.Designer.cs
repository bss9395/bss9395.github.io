
partial class CS_FontDialog {
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
            this.b_font = new System.Windows.Forms.Button();
            this.fd_font = new System.Windows.Forms.FontDialog();
            this.SuspendLayout();
            // 
            // tb_notebook
            // 
            this.tb_notebook.Location = new System.Drawing.Point(117, 70);
            this.tb_notebook.Multiline = true;
            this.tb_notebook.Name = "tb_notebook";
            this.tb_notebook.Size = new System.Drawing.Size(210, 130);
            this.tb_notebook.TabIndex = 0;
            // 
            // b_font
            // 
            this.b_font.AutoSize = true;
            this.b_font.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.b_font.Location = new System.Drawing.Point(184, 206);
            this.b_font.Name = "b_font";
            this.b_font.Size = new System.Drawing.Size(63, 22);
            this.b_font.TabIndex = 1;
            this.b_font.Text = "文本字体";
            this.b_font.UseVisualStyleBackColor = true;
            // 
            // CS_FontDialog
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.b_font);
            this.Controls.Add(this.tb_notebook);
            this.Name = "CS_FontDialog";
            this.Text = "CS_FontDialog";
            this.ResumeLayout(false);
            this.PerformLayout();

    }

    #endregion

    private System.Windows.Forms.TextBox tb_notebook;
    private System.Windows.Forms.Button b_font;
    private System.Windows.Forms.FontDialog fd_font;
}
