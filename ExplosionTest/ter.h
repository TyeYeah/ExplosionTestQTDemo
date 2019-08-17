#ifndef TER_H
#define TER_H

#include <QMainWindow>

namespace Ui {
class ter;
}

class ter : public QMainWindow
{
    Q_OBJECT

public:
    explicit ter(QWidget *parent = 0);
    ~ter();

private slots:
    void on_ter_check_clicked();

private:
    Ui::ter *ui;
};

#endif // TER_H
