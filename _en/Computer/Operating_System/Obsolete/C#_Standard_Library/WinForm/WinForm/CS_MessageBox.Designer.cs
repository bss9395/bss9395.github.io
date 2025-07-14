
    partial class CS_MessageBox {
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
            this.b_MessageBox = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // b_MessageBox
            // 
            this.b_MessageBox.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.b_MessageBox.AutoSize = true;
            this.b_MessageBox.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.b_MessageBox.Location = new System.Drawing.Point(363, 214);
            this.b_MessageBox.Name = "b_MessageBox";
            this.b_MessageBox.Size = new System.Drawing.Size(75, 22);
            this.b_MessageBox.TabIndex = 0;
            this.b_MessageBox.Text = "MessageBox";
            this.b_MessageBox.UseVisualStyleBackColor = true;
            // 
            // CS_MessageBox
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.b_MessageBox);
            this.Name = "CS_MessageBox";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button b_MessageBox;
    }


