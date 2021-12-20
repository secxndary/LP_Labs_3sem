using System;
using System.Drawing;
using System.Windows.Forms;
using System.IO;
using System.Drawing.Drawing2D;

namespace GraphicInterface
{


    public partial class Form1 : Form
    {
        public string filePath = "";

        public string fileIn = @"C:\Users\valda\source\repos\semester #3\LP_Labs\VAD-2021\VAD-2021\example.txt";

        //public string batPath = @"C:\Users\valda\source\repos\semester #3\LP_Labs\VAD-2021\GraphicInterface\GraphicInterface\out.bat";

        public string outBatPath = @"C:\Users\valda\source\repos\semester #3\LP_Labs\VAD-2021\GraphicInterface\GraphicInterface\out.bat";

        //public string recompilePath = @"C:\Users\valda\source\repos\semester #3\LP_Labs\VAD-2021\GraphicInterface\GraphicInterface\asmRecompile.bat";

        public Form1()
        {
            InitializeComponent();
        }


        private void button1_Click(object sender, EventArgs e)
        {
            //Save(sender, e);

            System.Diagnostics.Process p = new System.Diagnostics.Process();
            p.StartInfo.FileName = outBatPath;
            File.WriteAllText(outBatPath, "@echo off\n" +
                @"call ""C:\Users\valda\source\repos\semester #3\LP_Labs\VAD-2021\Debug\VAD-2021.exe""" +
                @" -in:""" + fileIn + @""" -out:""C:\Users\valda\source\repos\semester #3\LP_Labs\VAD-2021\Generation\Generation\Generation.asm""" +
                "\necho.\n" + @"call ""C:\Users\valda\source\repos\semester #3\LP_Labs\VAD-2021\Generation\Debug\Generation.exe""" +
                "\necho.\npause");
            p.Start();


            //p.StartInfo.FileName = recompilePath;
            //p.Start();

        }


        //public void Save(object sender, EventArgs e)
        //{
        //    SaveFileDialog saveFile1 = new SaveFileDialog();
        //    saveFile1.FileName = fileIn;
        //    using (StreamWriter sw = new StreamWriter(saveFile1.FileName, false))
        //    {
        //        saveFile1.FileName = fileIn;
        //        sw.WriteLine(richTextBox1.Text);
        //        sw.Close();
        //    }
        //}

/*@echo off
call "C:\Users\valda\source\repos\semester #3\LP_Labs\VAD-2021\Debug\VAD-2021.exe" -in:example.txt -out:"C:\Users\valda\source\repos\semester #3\LP_Labs\VAD-2021\Generation\Generation\Generation.asm"
call "C:\Users\valda\source\repos\semester #3\LP_Labs\VAD-2021\Generation\Debug\Generation.exe"
echo.
pause*/



        private void button2_Click(object sender, EventArgs e)
        {
            OpenFileDialog openFileDialog = new OpenFileDialog();
            if (openFileDialog.ShowDialog() == DialogResult.OK)
            {
                richTextBox1.Text = File.ReadAllText(openFileDialog.FileName);
                fileIn = openFileDialog.FileName;
                filePath = fileIn;

            }
        }
    }
}
