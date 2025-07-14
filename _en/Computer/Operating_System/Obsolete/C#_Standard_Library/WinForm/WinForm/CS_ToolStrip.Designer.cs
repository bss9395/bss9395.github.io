
partial class CS_ToolStrip {
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(CS_ToolStrip));
            this.ts_tool = new System.Windows.Forms.ToolStrip();
            this.tsb_button = new System.Windows.Forms.ToolStripButton();
            this.tsl_label = new System.Windows.Forms.ToolStripLabel();
            this.ts_tool.SuspendLayout();
            this.SuspendLayout();
            // 
            // ts_tool
            // 
            this.ts_tool.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tsb_button,
            this.tsl_label});
            this.ts_tool.Location = new System.Drawing.Point(0, 0);
            this.ts_tool.Name = "ts_tool";
            this.ts_tool.Size = new System.Drawing.Size(800, 25);
            this.ts_tool.TabIndex = 0;
            // 
            // tsb_button
            // 
            this.tsb_button.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.tsb_button.Image = ((System.Drawing.Image)(resources.GetObject("tsb_button.Image")));
            this.tsb_button.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.tsb_button.Name = "tsb_button";
            this.tsb_button.Size = new System.Drawing.Size(23, 22);
            // 
            // tsl_label
            // 
            this.tsl_label.Name = "tsl_label";
            this.tsl_label.Size = new System.Drawing.Size(32, 22);
            this.tsl_label.Text = "label";
            // 
            // CS_ToolStrip
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.ts_tool);
            this.Name = "CS_ToolStrip";
            this.Text = "CS_ToolStrip";
            this.ts_tool.ResumeLayout(false);
            this.ts_tool.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

    }

    #endregion

    private System.Windows.Forms.ToolStrip ts_tool;
    private System.Windows.Forms.ToolStripButton tsb_button;
    private System.Windows.Forms.ToolStripLabel tsl_label;
}
