#include "filebrowser.h"

FileBrowser::FileBrowser(QWidget *parent) : QWidget(parent)
{
    fileModel.setRootPath(QDir::rootPath());
    pTreeView.setModel(&fileModel);

    layout.addWidget(&label);
    layout.addWidget(&pTreeView);
    setLayout(&layout);
    connect(&pTreeView, SIGNAL(clicked(QModelIndex)), this, SLOT(setMove(QModelIndex)));
}

void FileBrowser::setMove(const QModelIndex &index)
{
    str = fileModel.filePath(index);
    label.setText(str);
}


