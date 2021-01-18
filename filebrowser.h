#ifndef FILEBROWSER_H
#define FILEBROWSER_H

#include <QtWidgets>
#include <QVBoxLayout>
#include <QString>

class FileBrowser : public QWidget
{
    Q_OBJECT
private:
    QFileSystemModel fileModel;
    QTreeView pTreeView;
    QVBoxLayout layout;
    QString str;

public:
    explicit FileBrowser(QWidget *parent = 0);
        QLabel label;

signals:

public slots:
    void setMove(const QModelIndex &index);
};

#endif // FILEBROWSER_H
