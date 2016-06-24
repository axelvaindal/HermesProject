#ifndef MERGER_HPP
#define MERGER_HPP

#include <QMainWindow>
#include <QtNetwork/QNetworkReply>

namespace Ui {
class Merger;
}

class Merger : public QMainWindow
{
    Q_OBJECT

public:
    explicit Merger(QWidget *parent = 0);
    ~Merger();

private slots:
   void on_selectFolder_clicked();
   void on_selectJson_clicked();
   void on_merge_clicked();
   void replyFinished(QNetworkReply *);


private:
    void merge();
    Ui::Merger *ui;
};

#endif // MERGER_HPP


