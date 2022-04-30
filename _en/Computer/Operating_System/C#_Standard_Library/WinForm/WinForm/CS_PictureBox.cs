/* CS_PictureBox.cs
Author: BSS9395
Update: 2022-04-30T23:51:00+08@China-Shanghai+08
Design: C# Standard Library: PictureBox
*/

using System;
using System.Drawing;
using System.Windows.Forms;

public partial class CS_PictureBox : Form {
    public CS_PictureBox() {
        InitializeComponent();

        pb_left.Image = WinForm.Properties.Resources._3d_rotation;
        pb_left.SizeMode = PictureBoxSizeMode.Zoom;
        pb_right.Image = WinForm.Properties.Resources._M31;
        pb_right.SizeMode = PictureBoxSizeMode.Zoom;

        b_swap.Click += (object sender, EventArgs e) => {
            Image temp = pb_left.Image;
            pb_left.Image = pb_right.Image;
            pb_right.Image = temp;
        };
    }
}

