/* CS_MDI.cs
Author: BSS9395
Update: 2022-04-30T23:51:00+08@China-Shanghai+08
Design: C# Standard Library: MDI
*/


using System;
using System.Windows.Forms;

public partial class CS_MDI : Form {
    public CS_MDI() {
        InitializeComponent();

        this.IsMdiContainer = true;

        tsmi_open.Click += (object sender, EventArgs e) => {
            CS_MenuStrip child = new CS_MenuStrip();
            child.MdiParent = this;
            child.Show();
        };
    }

}
