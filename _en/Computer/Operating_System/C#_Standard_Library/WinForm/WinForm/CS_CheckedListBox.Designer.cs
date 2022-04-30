
partial class CS_CheckedListBox {
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
        this.clb_fruit = new System.Windows.Forms.CheckedListBox();
        this.b_submit = new System.Windows.Forms.Button();
        this.SuspendLayout();
        // 
        // clb_fruit
        // 
        this.clb_fruit.FormattingEnabled = true;
        this.clb_fruit.Items.AddRange(new object[] {
            "苹果",
            "橘子",
            "梨子",
            "李子",
            "香蕉",
            "西瓜"});
        this.clb_fruit.Location = new System.Drawing.Point(282, 77);
        this.clb_fruit.Name = "clb_fruit";
        this.clb_fruit.Size = new System.Drawing.Size(236, 116);
        this.clb_fruit.TabIndex = 0;
        // 
        // b_submit
        // 
        this.b_submit.AutoSize = true;
        this.b_submit.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
        this.b_submit.Location = new System.Drawing.Point(381, 216);
        this.b_submit.Name = "b_submit";
        this.b_submit.Size = new System.Drawing.Size(39, 22);
        this.b_submit.TabIndex = 1;
        this.b_submit.Text = "提交";
        this.b_submit.UseVisualStyleBackColor = true;
        // 
        // CS_CheckedListBox
        // 
        this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
        this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
        this.ClientSize = new System.Drawing.Size(800, 450);
        this.Controls.Add(this.b_submit);
        this.Controls.Add(this.clb_fruit);
        this.Name = "CS_CheckedListBox";
        this.Text = "CS_CheckedListBox";
        this.ResumeLayout(false);
        this.PerformLayout();

    }

    #endregion

    private System.Windows.Forms.CheckedListBox clb_fruit;
    private System.Windows.Forms.Button b_submit;
}
