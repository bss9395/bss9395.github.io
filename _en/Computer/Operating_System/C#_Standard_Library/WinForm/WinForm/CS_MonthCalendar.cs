/* CS_MonthCalendar.cs
Author: BSS9395
Update: 2022-04-30T23:51:00+08@China-Shanghai+08
Design: C# Standard Library: MonthCalendar
*/


using System;
using System.Windows.Forms;

public partial class CS_MonthCalendar : Form {
    public CS_MonthCalendar() {
        InitializeComponent();

        mc_calendar.Hide();

        b_select.Click += (object sender, EventArgs e) => {
            mc_calendar.Show();
        };

        mc_calendar.DateSelected += (object sender, DateRangeEventArgs e) => {
            tb_date.Text = mc_calendar.SelectionStart.ToString("yyyy-MM-dd");
            mc_calendar.Hide();
        };
    }
}
