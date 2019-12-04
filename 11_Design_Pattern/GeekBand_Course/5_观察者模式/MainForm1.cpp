/*
 * @Author: sanjayzhong
 * @Github: https://github.com/sanjayzzzhong
 * @Date: 2019-12-03 16:58:59
 */
class MainForm : public Form
{
    TextBox *txtFilePath;
    TextBox *txtFileNumber;
    ProgressBar *progressBar; //变化的东西, 不一定是进度条 //责任是通知

public:
    void Button1_Click()
    {

        string filePath = txtFilePath->getText();
        int number = atoi(txtFileNumber->getText().c_str());

        FileSplitter splitter(filePath, number, progressBar);

        splitter.split();
    }
};
