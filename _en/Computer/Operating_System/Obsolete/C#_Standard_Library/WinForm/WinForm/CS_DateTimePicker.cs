/* CS_DateTimePicker.cs
Author: BSS9395
Update: 2022-04-30T23:51:00+08@China-Shanghai+08
Design: C# Standard Library: DateTimePicker
*/


using System;
using System.Windows.Forms;

public partial class CS_DateTimePicker : Form {
    public CS_DateTimePicker() {
        InitializeComponent();

        dtp_datetime.Format = DateTimePickerFormat.Time;
        t_timer.Interval = 1000;
        t_timer.Start();
        t_timer.Tick += (object sender, EventArgs e) => {
            dtp_datetime.ResetText();
        };
    }
}

