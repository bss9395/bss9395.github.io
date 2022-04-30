
partial class CS_ContextMenuStrip {
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
            this.components = new System.ComponentModel.Container();
            this.cms_menu = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.tsmi_open = new System.Windows.Forms.ToolStripMenuItem();
            this.tsmi_close = new System.Windows.Forms.ToolStripMenuItem();
            this.菜单项ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.cms_menu.SuspendLayout();
            this.SuspendLayout();
            // 
            // cms_menu
            // 
            this.cms_menu.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tsmi_open,
            this.tsmi_close});
            this.cms_menu.Name = "cms_menu";
            this.cms_menu.Size = new System.Drawing.Size(181, 70);
            // 
            // tsmi_open
            // 
            this.tsmi_open.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.菜单项ToolStripMenuItem});
            this.tsmi_open.Name = "tsmi_open";
            this.tsmi_open.Size = new System.Drawing.Size(180, 22);
            this.tsmi_open.Text = "打开窗体";
            // 
            // tsmi_close
            // 
            this.tsmi_close.Name = "tsmi_close";
            this.tsmi_close.Size = new System.Drawing.Size(180, 22);
            this.tsmi_close.Text = "关闭窗体";
            // 
            // 菜单项ToolStripMenuItem
            // 
            this.菜单项ToolStripMenuItem.Name = "菜单项ToolStripMenuItem";
            this.菜单项ToolStripMenuItem.Size = new System.Drawing.Size(180, 22);
            this.菜单项ToolStripMenuItem.Text = "菜单项";
            // 
            // CS_ContextMenuStrip
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.ContextMenuStrip = this.cms_menu;
            this.Name = "CS_ContextMenuStrip";
            this.Text = "CS_ContextMenuStrip";
            this.cms_menu.ResumeLayout(false);
            this.ResumeLayout(false);

    }

    #endregion

    private System.Windows.Forms.ContextMenuStrip cms_menu;
    private System.Windows.Forms.ToolStripMenuItem tsmi_open;
    private System.Windows.Forms.ToolStripMenuItem tsmi_close;
    private System.Windows.Forms.ToolStripMenuItem 菜单项ToolStripMenuItem;
}
