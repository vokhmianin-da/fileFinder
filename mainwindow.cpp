#include "mainwindow.h"
#include <QDir>
#include <QStatusBar>

MainWindow::MainWindow(QWidget *parent)
   : QMainWindow(parent)
{
   QWidget *centerWidget = new QWidget(this);
   setCentralWidget(centerWidget);
   QGridLayout *layout = new QGridLayout(this);
   ptrfilebrowser = new FileBrowser;
   centerWidget->setLayout(layout);
   searchEdit = new QLineEdit(this);
   layout->addWidget(searchEdit, 0, 0, 1, 3);
   layout->addWidget(ptrfilebrowser, 0, 3);

   startFindButton = new QPushButton(this);
   startFindButton->setText(tr("Find"));
   layout->addWidget(startFindButton, 0, 5);
   connect(startFindButton, SIGNAL(clicked()), this, SLOT(findFileSlot()));
   infoText = new QTextEdit(this);
   layout->addWidget(infoText, 1, 0, 10, 10);
   controllerl = new Controller(this);
   statusLabel = new QLabel(this);
   QStatusBar *statusBar = this->statusBar();
   statusBar->addWidget(statusLabel);
   connect(controllerl, SIGNAL(changFindPath(QString)), this, SLOT(changStatusLabel(QString)));
   connect(controllerl, SIGNAL(genPathOfFile(QString)), this, SLOT(printFindFile(QString)));
   connect(controllerl, SIGNAL((newFind())), infoText, SLOT(clear()));
}

MainWindow::~MainWindow()
{

}
void MainWindow::findFileSlot()
{
   QString linesearch = searchEdit->text();
   if (linesearch.length() == 0) return;
   controllerl->startFind(ptrfilebrowser->label.text(), linesearch);
}

void MainWindow::changStatusLabel(QString line)
{
   statusLabel->setText(line);
}

void MainWindow::printFindFile(QString str)
{
   infoText->append(str);
}


