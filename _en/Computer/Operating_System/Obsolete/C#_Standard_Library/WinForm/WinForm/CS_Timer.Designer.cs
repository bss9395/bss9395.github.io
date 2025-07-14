
partial class CS_Timer {
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
            this.pb_picture = new System.Windows.Forms.PictureBox();
            this.b_start = new System.Windows.Forms.Button();
            this.b_stop = new System.Windows.Forms.Button();
            this.t_timer = new System.Windows.Forms.Timer(this.components);
            ((System.ComponentModel.ISupportInitialize)(this.pb_picture)).BeginInit();
            this.SuspendLayout();
            // 
            // pb_picture
            // 
            this.pb_picture.Location = new System.Drawing.Point(243, 12);
            this.pb_picture.Name = "pb_picture";
            this.pb_picture.Size = new System.Drawing.Size(256, 256);
            this.pb_picture.TabIndex = 0;
            this.pb_picture.TabStop = false;
            // 
            // b_start
            // 
            this.b_start.Location = new System.Drawing.Point(274, 284);
            this.b_start.Name = "b_start";
            this.b_start.Size = new System.Drawing.Size(75, 23);
            this.b_start.TabIndex = 1;
            this.b_start.Text = "启动定时器";
            this.b_start.UseVisualStyleBackColor = true;
            // 
            // b_stop
            // 
            this.b_stop.AutoSize = true;
            this.b_stop.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.b_stop.Location = new System.Drawing.Point(388, 285);
            this.b_stop.Name = "b_stop";
            this.b_stop.Size = new System.Drawing.Size(75, 22);
            this.b_stop.TabIndex = 2;
            this.b_stop.Text = "关闭定时器";
            this.b_stop.UseVisualStyleBackColor = true;
            // 
            // CS_Timer
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.b_stop);
            this.Controls.Add(this.b_start);
            this.Controls.Add(this.pb_picture);
            this.Name = "CS_Timer";
            this.Text = "CS_Timer";
            ((System.ComponentModel.ISupportInitialize)(this.pb_picture)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

    }

    #endregion

    private System.Windows.Forms.PictureBox pb_picture;
    private System.Windows.Forms.Button b_start;
    private System.Windows.Forms.Button b_stop;
    private System.Windows.Forms.Timer t_timer;
}
