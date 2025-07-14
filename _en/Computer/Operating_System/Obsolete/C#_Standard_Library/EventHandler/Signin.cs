using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;


public partial class Signin : Form {
    public Signin() {
        InitializeComponent();

        void Show_Message(Object sender, EventArgs eve) {
            MessageBox.Show("abc", "def", MessageBoxButtons.OK, MessageBoxIcon.Information);
        };
        _b_MessageBox.Click += Show_Message;
        _b_MessageBox.Click += new EventHandler(Show_Message);

        _b_MessageBox.Click += (Object sender, EventArgs eve) => {
            MessageBox.Show("abc", "def", MessageBoxButtons.OK, MessageBoxIcon.Information);
        };
    }
}
