/* CS_CheckBox.cs
Author: BSS9395
Update: 2022-04-30T23:51:00+08@China-Shanghai+08
Design: C# Standard Library: CheckBox
*/

using System;
using System.Windows.Forms;

public partial class CS_CheckBox : Form {
    public CS_CheckBox() {
        InitializeComponent();

        b_submit.Click += (object sender, EventArgs e) => {
            string hobbies = "";
            if (cb_basketball.Checked == true) {
                if (hobbies != "") {
                    hobbies += ", ";
                }
                hobbies += cb_basketball.Text;
            }
            if (cb_badminton.Checked == true) {
                if (hobbies != "") {
                    hobbies += ", ";
                }
                hobbies += cb_badminton.Text;
            }
            if (cb_swimming.Checked == true) {
                if (hobbies != "") {
                    hobbies += ", ";
                }
                hobbies += cb_swimming.Text;
            }
            if (cb_writting.Checked == true) {
                if (hobbies != "") {
                    hobbies += ", ";
                }
                hobbies += cb_writting.Text;
            }
            if (cb_volleyball.Checked == true) {
                if (hobbies != "") {
                    hobbies += ", ";
                }
                hobbies += cb_volleyball.Text;
            }
            if (cb_pingpong.Checked == true) {
                if (hobbies != "") {
                    hobbies += ", ";
                }
                hobbies += cb_pingpong.Text;
            }
            if (cb_reading.Checked == true) {
                if (hobbies != "") {
                    hobbies += ", ";
                }
                hobbies += cb_reading.Text;
            }
            string caption = "你的爱好";
            MessageBox.Show(hobbies, caption, MessageBoxButtons.OK);
        };
    }
}
