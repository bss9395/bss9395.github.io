
partial class CS_MDI {
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
        this.ms_menu = new System.Windows.Forms.MenuStrip();
        this.tsmi_file = new System.Windows.Forms.ToolStripMenuItem();
        this.tsmi_open = new System.Windows.Forms.ToolStripMenuItem();
        this.tsmi_save = new System.Windows.Forms.ToolStripMenuItem();
        this.ms_menu.SuspendLayout();
        this.SuspendLayout();
        // 
        // ms_menu
        // 
        this.ms_menu.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tsmi_file});
        this.ms_menu.Location = new System.Drawing.Point(0, 0);
        this.ms_menu.Name = "ms_menu";
        this.ms_menu.Size = new System.Drawing.Size(800, 24);
        this.ms_menu.TabIndex = 1;
        // 
        // tsmi_file
        // 
        this.tsmi_file.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tsmi_open,
            this.tsmi_save});
        this.tsmi_file.Name = "tsmi_file";
        this.tsmi_file.Size = new System.Drawing.Size(45, 20);
        this.tsmi_file.Text = "文件";
        // 
        // tsmi_open
        // 
        this.tsmi_open.Name = "tsmi_open";
        this.tsmi_open.Size = new System.Drawing.Size(180, 22);
        this.tsmi_open.Text = "打开文件";
        // 
        // tsmi_save
        // 
        this.tsmi_save.Name = "tsmi_save";
        this.tsmi_save.Size = new System.Drawing.Size(180, 22);
        this.tsmi_save.Text = "保存文件";
        // 
        // CS_MDI
        // 
        this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
        this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
        this.ClientSize = new System.Drawing.Size(800, 450);
        this.Controls.Add(this.ms_menu);
        this.IsMdiContainer = true;
        this.MainMenuStrip = this.ms_menu;
        this.Name = "CS_MDI";
        this.Text = "CS_MDI";
        this.ms_menu.ResumeLayout(false);
        this.ms_menu.PerformLayout();
        this.ResumeLayout(false);
        this.PerformLayout();

    }

    #endregion

    private System.Windows.Forms.MenuStrip ms_menu;
    private System.Windows.Forms.ToolStripMenuItem tsmi_file;
    private System.Windows.Forms.ToolStripMenuItem tsmi_open;
    private System.Windows.Forms.ToolStripMenuItem tsmi_save;
}
