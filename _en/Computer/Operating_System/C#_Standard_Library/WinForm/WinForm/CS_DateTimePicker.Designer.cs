
partial class CS_DateTimePicker {
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
            this.dtp_datetime = new System.Windows.Forms.DateTimePicker();
            this.t_timer = new System.Windows.Forms.Timer(this.components);
            this.SuspendLayout();
            // 
            // dtp_datetime
            // 
            this.dtp_datetime.Format = System.Windows.Forms.DateTimePickerFormat.Time;
            this.dtp_datetime.Location = new System.Drawing.Point(208, 115);
            this.dtp_datetime.Name = "dtp_datetime";
            this.dtp_datetime.Size = new System.Drawing.Size(200, 21);
            this.dtp_datetime.TabIndex = 0;
            // 
            // CS_DateTimePicker
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.dtp_datetime);
            this.Name = "CS_DateTimePicker";
            this.Text = "CS_DateTimePicker";
            this.ResumeLayout(false);

    }

    #endregion

    private System.Windows.Forms.DateTimePicker dtp_datetime;
    private System.Windows.Forms.Timer t_timer;
}
