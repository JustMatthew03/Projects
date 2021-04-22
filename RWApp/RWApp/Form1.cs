using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace RWApp
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Save_Button_Click(object sender, EventArgs e)
        {
            OpenFileDialog ofd = new OpenFileDialog();
            ofd.Filter = "Text|*.txt|All|*.*";

            if (ofd.ShowDialog() == DialogResult.OK)
            {
                string file = ofd.FileName;

                using (StreamWriter sw = new StreamWriter(file))
                {
                    foreach (var line in textBox1.Lines)
                    {
                        if (line != null)
                        {
                            sw.WriteLine(line);
                        }
                    }

                    sw.Close();
                    MessageBox.Show("Text Saved to " + file);
                }
            }
        }

        private void Load_Button_Click(object sender, EventArgs e)
        {
            OpenFileDialog ofd = new OpenFileDialog();
            ofd.Filter = "Text|*.txt|All|*.*";

            if (ofd.ShowDialog() == DialogResult.OK)
            {
                string file = ofd.FileName;

                using (StreamReader sr = new StreamReader(file))
                {
                    string[] lines = File.ReadAllLines(file);

                    foreach (var line in lines)
                    {
                        if (line != null)
                        {
                            textBox1.AppendText(line + "\r\n");
                        }
                    }
                }
            }
        }
    }
}
