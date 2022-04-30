partial class CS_MonthCalendar {
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
        this.tb_date = new System.Windows.Forms.TextBox();
        this.b_select = new System.Windows.Forms.Button();
        this.mc_calendar = new System.Windows.Forms.MonthCalendar();
        this.SuspendLayout();
        // 
        // tb_date
        // 
        this.tb_date.Location = new System.Drawing.Point(139, 133);
        this.tb_date.Name = "tb_date";
        this.tb_date.Size = new System.Drawing.Size(189, 21);
        this.tb_date.TabIndex = 0;
        // 
        // b_select
        // 
        this.b_select.AutoSize = true;
        this.b_select.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
        this.b_select.Location = new System.Drawing.Point(334, 133);
        this.b_select.Name = "b_select";
        this.b_select.Size = new System.Drawing.Size(39, 22);
        this.b_select.TabIndex = 1;
        this.b_select.Text = "选择";
        this.b_select.UseVisualStyleBackColor = true;
        // 
        // mc_calendar
        // 
        this.mc_calendar.Location = new System.Drawing.Point(139, 166);
        this.mc_calendar.Name = "mc_calendar";
        this.mc_calendar.TabIndex = 2;
        // 
        // CS_MonthCalendar
        // 
        this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
        this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
        this.ClientSize = new System.Drawing.Size(800, 450);
        this.Controls.Add(this.mc_calendar);
        this.Controls.Add(this.b_select);
        this.Controls.Add(this.tb_date);
        this.Name = "CS_MonthCalendar";
        this.Text = "CS_MonthCalendar";
        this.ResumeLayout(false);
        this.PerformLayout();

    }

    #endregion

    private System.Windows.Forms.TextBox tb_date;
    private System.Windows.Forms.Button b_select;
    private System.Windows.Forms.MonthCalendar mc_calendar;
}
