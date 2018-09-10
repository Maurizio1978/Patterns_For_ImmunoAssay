#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void slot_started();
    void slot_finished();


//void slot_finished();
//        QFuture<void> FutureWatcher;

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
