#ifndef LE_H
#define LE_H

#include <QMainWindow>

namespace Ui {
class le;
}

class le : public QMainWindow
{
    Q_OBJECT

public:
    explicit le(QWidget *parent = 0);
    ~le();

private slots:
    void on_le_check_clicked();

private:
    Ui::le *ui;
};

#endif // LE_H
