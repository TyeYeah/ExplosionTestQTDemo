#ifndef KU_H
#define KU_H

#include <QMainWindow>

namespace Ui {
class ku;
}

class ku : public QMainWindow
{
    Q_OBJECT

public:
    explicit ku(QWidget *parent = 0);
    ~ku();

private slots:
    void on_ku_check_clicked();

private:
    Ui::ku *ui;
};

#endif // KU_H
