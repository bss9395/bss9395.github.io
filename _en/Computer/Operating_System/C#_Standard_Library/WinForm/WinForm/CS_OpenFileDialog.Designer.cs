
partial class CS_OpenFileDialog {
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
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.tsmi_open = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmi_save = new System.Windows.Forms.ToolStripMenuItem();
            this.tb_notebook = new System.Windows.Forms.TextBox();
            this.ofd_open = new System.Windows.Forms.OpenFileDialog();
            this.sfd_save = new System.Windows.Forms.SaveFileDialog();
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tsmi_open,
            this.tsmi_save});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(800, 24);
            this.menuStrip1.TabIndex = 0;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // tsmi_open
            // 
            this.tsmi_open.Name = "tsmi_open";
            this.tsmi_open.Size = new System.Drawing.Size(71, 20);
            this.tsmi_open.Text = "打开文件";
            // 
            // tsmi_save
            // 
            this.tsmi_save.Name = "tsmi_save";
            this.tsmi_save.Size = new System.Drawing.Size(71, 20);
            this.tsmi_save.Text = "保存文件";
            // 
            // tb_notebook
            // 
            this.tb_notebook.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tb_notebook.Location = new System.Drawing.Point(0, 24);
            this.tb_notebook.Multiline = true;
            this.tb_notebook.Name = "tb_notebook";
            this.tb_notebook.Size = new System.Drawing.Size(800, 426);
            this.tb_notebook.TabIndex = 1;
            // 
            // CS_OpenFileDialog
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.tb_notebook);
            this.Controls.Add(this.menuStrip1);
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "CS_OpenFileDialog";
            this.Text = "CS_OpenFileDialog";
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

    }

    #endregion

    private System.Windows.Forms.MenuStrip menuStrip1;
    private System.Windows.Forms.ToolStripMenuItem tsmi_open;
    private System.Windows.Forms.ToolStripMenuItem tsmi_save;
    private System.Windows.Forms.TextBox tb_notebook;
    private System.Windows.Forms.OpenFileDialog ofd_open;
    private System.Windows.Forms.SaveFileDialog sfd_save;
}
