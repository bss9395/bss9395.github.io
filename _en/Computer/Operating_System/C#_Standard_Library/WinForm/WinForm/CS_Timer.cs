/* CS_Timer.cs
Author: BSS9395
Update: 2022-04-30T23:51:00+08@China-Shanghai+08
Design: C# Standard Library: Timer
*/

using System;
using System.Windows.Forms;

public partial class CS_Timer : Form {
    bool flag = true;
    public CS_Timer() {
        InitializeComponent();

        pb_picture.Image = WinForm.Properties.Resources._M31;
        pb_picture.SizeMode = PictureBoxSizeMode.Zoom;

        t_timer.Interval = 1000;
        t_timer.Tick += (object sender, EventArgs e) => {
            if (flag == true) {
                pb_picture.Image = WinForm.Properties.Resources._M31;
                flag = false;
            } else {
                pb_picture.Image = WinForm.Properties.Resources._3d_rotation;
                flag = true;
            }
        };

        b_start.Click += (object sender, EventArgs e) => {
            t_timer.Start();
        };

        b_stop.Click += (object sender, EventArgs e) => {
            t_timer.Stop();
        };
    }
}
