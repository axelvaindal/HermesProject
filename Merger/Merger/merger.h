#ifndef MERGER_H
#define MERGER_H

#include <QMainWindow>

namespace Ui {
class Merger;
}

class Merger : public QMainWindow
{
    Q_OBJECT

public:
    explicit Merger(QWidget *parent = 0);
    ~Merger();

private:
    Ui::Merger *ui;
};

#endif // MERGER_H
