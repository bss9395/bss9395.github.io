
partial class CS_PictureBox {
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
            this.pb_left = new System.Windows.Forms.PictureBox();
            this.pb_right = new System.Windows.Forms.PictureBox();
            this.b_swap = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.pb_left)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pb_right)).BeginInit();
            this.SuspendLayout();
            // 
            // pb_left
            // 
            this.pb_left.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.pb_left.Location = new System.Drawing.Point(212, 108);
            this.pb_left.Name = "pb_left";
            this.pb_left.Size = new System.Drawing.Size(128, 128);
            this.pb_left.TabIndex = 0;
            this.pb_left.TabStop = false;
            // 
            // pb_right
            // 
            this.pb_right.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.pb_right.Location = new System.Drawing.Point(378, 108);
            this.pb_right.Name = "pb_right";
            this.pb_right.Size = new System.Drawing.Size(128, 128);
            this.pb_right.TabIndex = 1;
            this.pb_right.TabStop = false;
            // 
            // b_swap
            // 
            this.b_swap.AutoSize = true;
            this.b_swap.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.b_swap.Location = new System.Drawing.Point(338, 285);
            this.b_swap.Name = "b_swap";
            this.b_swap.Size = new System.Drawing.Size(39, 22);
            this.b_swap.TabIndex = 2;
            this.b_swap.Text = "交换";
            this.b_swap.UseVisualStyleBackColor = true;
            // 
            // CS_PictureBox
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.b_swap);
            this.Controls.Add(this.pb_right);
            this.Controls.Add(this.pb_left);
            this.Name = "CS_PictureBox";
            this.Text = "CS_PictureBox";
            ((System.ComponentModel.ISupportInitialize)(this.pb_left)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pb_right)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

    }

    #endregion

    private System.Windows.Forms.PictureBox pb_left;
    private System.Windows.Forms.PictureBox pb_right;
    private System.Windows.Forms.Button b_swap;
}
