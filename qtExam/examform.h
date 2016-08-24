#ifndef EXAMFORM_H
#define EXAMFORM_H

#include <QWidget>
#include<QStringList>
#include<QtSql/QSqlQuery>
#include"osgSQL/DBHelper.h"
#include"osgMessageBox/dialogform.h"
namespace Ui {
class ExamForm;
}

class ExamForm : public QWidget
{
    Q_OBJECT

public:
    explicit ExamForm(QWidget *parent = 0);
    ~ExamForm();

private slots:
    void on_comboBox_activated(const QString &arg1);

    void on_pushButton_clicked();
    void setCurrentQuestionEnd();
private:
    Ui::ExamForm *ui;
    QStringList QuestionIDs;
    void initExam();
    void GetRecult();

 signals:
    void StartExam(QString);
};

#endif // EXAMFORM_H
