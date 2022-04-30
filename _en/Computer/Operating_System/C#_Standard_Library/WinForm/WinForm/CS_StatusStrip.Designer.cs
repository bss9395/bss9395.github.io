
partial class CS_StatusStrip {
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(CS_StatusStrip));
            this.ss_status = new System.Windows.Forms.StatusStrip();
            this.tssl_label = new System.Windows.Forms.ToolStripStatusLabel();
            this.tspb_progress = new System.Windows.Forms.ToolStripProgressBar();
            this.tsddb_drop = new System.Windows.Forms.ToolStripDropDownButton();
            this.tssb_split = new System.Windows.Forms.ToolStripSplitButton();
            this.dropDownToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.splitToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.ss_status.SuspendLayout();
            this.SuspendLayout();
            // 
            // ss_status
            // 
            this.ss_status.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tssl_label,
            this.tspb_progress,
            this.tsddb_drop,
            this.tssb_split});
            this.ss_status.Location = new System.Drawing.Point(0, 428);
            this.ss_status.Name = "ss_status";
            this.ss_status.Size = new System.Drawing.Size(800, 22);
            this.ss_status.TabIndex = 0;
            // 
            // tssl_label
            // 
            this.tssl_label.Name = "tssl_label";
            this.tssl_label.Size = new System.Drawing.Size(54, 17);
            this.tssl_label.Text = "tssl_label";
            // 
            // tspb_progress
            // 
            this.tspb_progress.Name = "tspb_progress";
            this.tspb_progress.Size = new System.Drawing.Size(100, 16);
            // 
            // tsddb_drop
            // 
            this.tsddb_drop.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsddb_drop.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.dropDownToolStripMenuItem});
            this.tsddb_drop.Image = ((System.Drawing.Image)(resources.GetObject("tsddb_drop.Image")));
            this.tsddb_drop.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsddb_drop.Name = "tsddb_drop";
            this.tsddb_drop.Size = new System.Drawing.Size(29, 20);
            // 
            // tssb_split
            // 
            this.tssb_split.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tssb_split.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.splitToolStripMenuItem});
            this.tssb_split.Image = ((System.Drawing.Image)(resources.GetObject("tssb_split.Image")));
            this.tssb_split.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tssb_split.Name = "tssb_split";
            this.tssb_split.Size = new System.Drawing.Size(32, 20);
            // 
            // dropDownToolStripMenuItem
            // 
            this.dropDownToolStripMenuItem.Name = "dropDownToolStripMenuItem";
            this.dropDownToolStripMenuItem.Size = new System.Drawing.Size(180, 22);
            this.dropDownToolStripMenuItem.Text = "DropDown";
            // 
            // splitToolStripMenuItem
            // 
            this.splitToolStripMenuItem.Name = "splitToolStripMenuItem";
            this.splitToolStripMenuItem.Size = new System.Drawing.Size(180, 22);
            this.splitToolStripMenuItem.Text = "Split";
            // 
            // CS_StatusStrip
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.ss_status);
            this.Name = "CS_StatusStrip";
            this.Text = "CS_StatusStrip";
            this.ss_status.ResumeLayout(false);
            this.ss_status.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

    }

    #endregion

    private System.Windows.Forms.StatusStrip ss_status;
    private System.Windows.Forms.ToolStripStatusLabel tssl_label;
    private System.Windows.Forms.ToolStripProgressBar tspb_progress;
    private System.Windows.Forms.ToolStripDropDownButton tsddb_drop;
    private System.Windows.Forms.ToolStripSplitButton tssb_split;
    private System.Windows.Forms.ToolStripMenuItem dropDownToolStripMenuItem;
    private System.Windows.Forms.ToolStripMenuItem splitToolStripMenuItem;
}
