partial class CS_LinkLabel {
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
        this.l_label_1 = new System.Windows.Forms.Label();
        this.l_label_2 = new System.Windows.Forms.Label();
        this.ll_link_label = new System.Windows.Forms.LinkLabel();
        this.SuspendLayout();
        // 
        // l_label_1
        // 
        this.l_label_1.AutoSize = true;
        this.l_label_1.Location = new System.Drawing.Point(383, 100);
        this.l_label_1.Name = "l_label_1";
        this.l_label_1.Size = new System.Drawing.Size(35, 12);
        this.l_label_1.TabIndex = 0;
        this.l_label_1.Text = "标签1";
        // 
        // l_label_2
        // 
        this.l_label_2.AutoSize = true;
        this.l_label_2.Location = new System.Drawing.Point(383, 200);
        this.l_label_2.Name = "l_label_2";
        this.l_label_2.Size = new System.Drawing.Size(35, 12);
        this.l_label_2.TabIndex = 1;
        this.l_label_2.Text = "标签2";
        // 
        // ll_link_label
        // 
        this.ll_link_label.AutoSize = true;
        this.ll_link_label.Location = new System.Drawing.Point(374, 300);
        this.ll_link_label.Name = "ll_link_label";
        this.ll_link_label.Size = new System.Drawing.Size(53, 12);
        this.ll_link_label.TabIndex = 2;
        this.ll_link_label.TabStop = true;
        this.ll_link_label.Text = "链接标签";
        // 
        // CS_LinkLabel
        // 
        this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
        this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
        this.ClientSize = new System.Drawing.Size(800, 450);
        this.Controls.Add(this.ll_link_label);
        this.Controls.Add(this.l_label_2);
        this.Controls.Add(this.l_label_1);
        this.Name = "CS_LinkLabel";
        this.Text = "CS_LinkLabel";
        this.ResumeLayout(false);
        this.PerformLayout();

    }

    #endregion

    private System.Windows.Forms.Label l_label_1;
    private System.Windows.Forms.Label l_label_2;
    private System.Windows.Forms.LinkLabel ll_link_label;
}
