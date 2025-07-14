
partial class Signin {
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
            this._b_MessageBox = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // b_MessageBox
            // 
            this._b_MessageBox.AutoSize = true;
            this._b_MessageBox.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this._b_MessageBox.Location = new System.Drawing.Point(268, 149);
            this._b_MessageBox.Name = "b_MessageBox";
            this._b_MessageBox.Size = new System.Drawing.Size(62, 25);
            this._b_MessageBox.TabIndex = 1;
            this._b_MessageBox.Text = "消息框";
            this._b_MessageBox.UseVisualStyleBackColor = true;
            // 
            // Signin
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(582, 323);
            this.Controls.Add(this._b_MessageBox);
            this.Name = "Signin";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

    }

    #endregion
    private System.Windows.Forms.Button _b_MessageBox;
}


