#ifndef MAO_H
#define MAO_H

#include <QMainWindow>

namespace Ui {
class mao;
}

class mao : public QMainWindow
{
    Q_OBJECT

public:
    explicit mao(QWidget *parent = 0);
    ~mao();

private slots:
    void on_mao_check_clicked();

private:
    Ui::mao *ui;
};

#endif // MAO_H
