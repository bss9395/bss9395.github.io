
partial class CS_CheckBox {
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
        this.gb_hobbies = new System.Windows.Forms.GroupBox();
        this.cb_basketball = new System.Windows.Forms.CheckBox();
        this.cb_badminton = new System.Windows.Forms.CheckBox();
        this.cb_swimming = new System.Windows.Forms.CheckBox();
        this.cb_writting = new System.Windows.Forms.CheckBox();
        this.cb_volleyball = new System.Windows.Forms.CheckBox();
        this.cb_pingpong = new System.Windows.Forms.CheckBox();
        this.cb_reading = new System.Windows.Forms.CheckBox();
        this.b_submit = new System.Windows.Forms.Button();
        this.gb_hobbies.SuspendLayout();
        this.SuspendLayout();
        // 
        // gb_hobbies
        // 
        this.gb_hobbies.Controls.Add(this.b_submit);
        this.gb_hobbies.Controls.Add(this.cb_reading);
        this.gb_hobbies.Controls.Add(this.cb_pingpong);
        this.gb_hobbies.Controls.Add(this.cb_volleyball);
        this.gb_hobbies.Controls.Add(this.cb_writting);
        this.gb_hobbies.Controls.Add(this.cb_swimming);
        this.gb_hobbies.Controls.Add(this.cb_badminton);
        this.gb_hobbies.Controls.Add(this.cb_basketball);
        this.gb_hobbies.Location = new System.Drawing.Point(156, 49);
        this.gb_hobbies.Name = "gb_hobbies";
        this.gb_hobbies.Size = new System.Drawing.Size(399, 216);
        this.gb_hobbies.TabIndex = 0;
        this.gb_hobbies.TabStop = false;
        this.gb_hobbies.Text = "兴趣爱好";
        // 
        // cb_basketball
        // 
        this.cb_basketball.AutoSize = true;
        this.cb_basketball.Location = new System.Drawing.Point(169, 21);
        this.cb_basketball.Name = "cb_basketball";
        this.cb_basketball.Size = new System.Drawing.Size(48, 16);
        this.cb_basketball.TabIndex = 0;
        this.cb_basketball.Text = "篮球";
        this.cb_basketball.UseVisualStyleBackColor = true;
        // 
        // cb_badminton
        // 
        this.cb_badminton.AutoSize = true;
        this.cb_badminton.Location = new System.Drawing.Point(169, 43);
        this.cb_badminton.Name = "cb_badminton";
        this.cb_badminton.Size = new System.Drawing.Size(60, 16);
        this.cb_badminton.TabIndex = 1;
        this.cb_badminton.Text = "羽毛球";
        this.cb_badminton.UseVisualStyleBackColor = true;
        // 
        // cb_swim
        // 
        this.cb_swimming.AutoSize = true;
        this.cb_swimming.Location = new System.Drawing.Point(169, 65);
        this.cb_swimming.Name = "cb_swim";
        this.cb_swimming.Size = new System.Drawing.Size(48, 16);
        this.cb_swimming.TabIndex = 2;
        this.cb_swimming.Text = "游泳";
        this.cb_swimming.UseVisualStyleBackColor = true;
        // 
        // cb_writting
        // 
        this.cb_writting.AutoSize = true;
        this.cb_writting.Location = new System.Drawing.Point(169, 88);
        this.cb_writting.Name = "cb_writting";
        this.cb_writting.Size = new System.Drawing.Size(48, 16);
        this.cb_writting.TabIndex = 3;
        this.cb_writting.Text = "写作";
        this.cb_writting.UseVisualStyleBackColor = true;
        // 
        // cb_volleyball
        // 
        this.cb_volleyball.AutoSize = true;
        this.cb_volleyball.Location = new System.Drawing.Point(169, 111);
        this.cb_volleyball.Name = "cb_volleyball";
        this.cb_volleyball.Size = new System.Drawing.Size(48, 16);
        this.cb_volleyball.TabIndex = 4;
        this.cb_volleyball.Text = "排球";
        this.cb_volleyball.UseVisualStyleBackColor = true;
        // 
        // cb_pingpong
        // 
        this.cb_pingpong.AutoSize = true;
        this.cb_pingpong.Location = new System.Drawing.Point(169, 134);
        this.cb_pingpong.Name = "cb_pingpong";
        this.cb_pingpong.Size = new System.Drawing.Size(60, 16);
        this.cb_pingpong.TabIndex = 5;
        this.cb_pingpong.Text = "乒乓球";
        this.cb_pingpong.UseVisualStyleBackColor = true;
        // 
        // cb_reading
        // 
        this.cb_reading.AutoSize = true;
        this.cb_reading.Location = new System.Drawing.Point(169, 157);
        this.cb_reading.Name = "cb_reading";
        this.cb_reading.Size = new System.Drawing.Size(48, 16);
        this.cb_reading.TabIndex = 6;
        this.cb_reading.Text = "阅读";
        this.cb_reading.UseVisualStyleBackColor = true;
        // 
        // b_submit
        // 
        this.b_submit.AutoSize = true;
        this.b_submit.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
        this.b_submit.Location = new System.Drawing.Point(169, 180);
        this.b_submit.Name = "b_submit";
        this.b_submit.Size = new System.Drawing.Size(39, 22);
        this.b_submit.TabIndex = 7;
        this.b_submit.Text = "提交";
        this.b_submit.UseVisualStyleBackColor = true;
        // 
        // CS_CheckBox
        // 
        this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
        this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
        this.ClientSize = new System.Drawing.Size(800, 450);
        this.Controls.Add(this.gb_hobbies);
        this.Name = "CS_CheckBox";
        this.Text = "CS_CheckBox";
        this.gb_hobbies.ResumeLayout(false);
        this.gb_hobbies.PerformLayout();
        this.ResumeLayout(false);

    }

    #endregion

    private System.Windows.Forms.GroupBox gb_hobbies;
    private System.Windows.Forms.CheckBox cb_reading;
    private System.Windows.Forms.CheckBox cb_pingpong;
    private System.Windows.Forms.CheckBox cb_volleyball;
    private System.Windows.Forms.CheckBox cb_writting;
    private System.Windows.Forms.CheckBox cb_swimming;
    private System.Windows.Forms.CheckBox cb_badminton;
    private System.Windows.Forms.CheckBox cb_basketball;
    private System.Windows.Forms.Button b_submit;
}
