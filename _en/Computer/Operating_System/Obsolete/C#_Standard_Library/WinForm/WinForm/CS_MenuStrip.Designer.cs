
partial class CS_MenuStrip {
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
        this.tsmi_edit = new System.Windows.Forms.ToolStripMenuItem();
        this.tsmi_view = new System.Windows.Forms.ToolStripMenuItem();
        this.tsmi_new = new System.Windows.Forms.ToolStripMenuItem();
        this.tsmi_open = new System.Windows.Forms.ToolStripMenuItem();
        this.tsmi_close = new System.Windows.Forms.ToolStripMenuItem();
        this.ms_menu.SuspendLayout();
        this.SuspendLayout();
        // 
        // ms_menu
        // 
        this.ms_menu.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tsmi_file,
            this.tsmi_edit,
            this.tsmi_view});
        this.ms_menu.Location = new System.Drawing.Point(0, 0);
        this.ms_menu.Name = "ms_menu";
        this.ms_menu.Size = new System.Drawing.Size(800, 24);
        this.ms_menu.TabIndex = 0;
        this.ms_menu.Text = "menuStrip1";
        // 
        // tsmi_file
        // 
        this.tsmi_file.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tsmi_new,
            this.tsmi_open,
            this.tsmi_close});
        this.tsmi_file.Name = "tsmi_file";
        this.tsmi_file.Size = new System.Drawing.Size(45, 20);
        this.tsmi_file.Text = "文件";
        // 
        // tsmi_edit
        // 
        this.tsmi_edit.Name = "tsmi_edit";
        this.tsmi_edit.Size = new System.Drawing.Size(45, 20);
        this.tsmi_edit.Text = "编辑";
        // 
        // tsmi_view
        // 
        this.tsmi_view.Name = "tsmi_view";
        this.tsmi_view.Size = new System.Drawing.Size(45, 20);
        this.tsmi_view.Text = "视图";
        // 
        // tsmi_new
        // 
        this.tsmi_new.Name = "tsmi_new";
        this.tsmi_new.Size = new System.Drawing.Size(180, 22);
        this.tsmi_new.Text = "新建";
        // 
        // tsmi_open
        // 
        this.tsmi_open.Name = "tsmi_open";
        this.tsmi_open.Size = new System.Drawing.Size(180, 22);
        this.tsmi_open.Text = "打开";
        // 
        // tsmi_close
        // 
        this.tsmi_close.Name = "tsmi_close";
        this.tsmi_close.Size = new System.Drawing.Size(180, 22);
        this.tsmi_close.Text = "关闭";
        // 
        // CS_MenuStrip
        // 
        this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
        this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
        this.ClientSize = new System.Drawing.Size(800, 450);
        this.Controls.Add(this.ms_menu);
        this.MainMenuStrip = this.ms_menu;
        this.Name = "CS_MenuStrip";
        this.Text = "CS_MenuStrip";
        this.ms_menu.ResumeLayout(false);
        this.ms_menu.PerformLayout();
        this.ResumeLayout(false);
        this.PerformLayout();

    }

    #endregion

    private System.Windows.Forms.MenuStrip ms_menu;
    private System.Windows.Forms.ToolStripMenuItem tsmi_file;
    private System.Windows.Forms.ToolStripMenuItem tsmi_new;
    private System.Windows.Forms.ToolStripMenuItem tsmi_open;
    private System.Windows.Forms.ToolStripMenuItem tsmi_close;
    private System.Windows.Forms.ToolStripMenuItem tsmi_edit;
    private System.Windows.Forms.ToolStripMenuItem tsmi_view;
}
