#ifndef UP_THREAD_H
#define UP_THREAD_H
#include <QThread>
#include "qtUpdate/chttpdownloadfile.h"
#include <QDomElement>
#include <QMessageBox>
#include "QPainter"
#include "qmath.h"
#include "qtUpdate/Export.h"
#include <QUrl>

namespace qtUpdate {
class QTUPDATE_EXPORT Up_Thread  : public QThread
{
   Q_OBJECT
public:
    explicit Up_Thread(QObject *parent = 0);
    void stop();
    virtual void run();
    bool m_stop;



    CHttpDownloadFile *CHttpDownloadFile_ob;
    void read_xml();//读XML
    void down_xml();//下载XML
    void ExitApp(QString);
    void DownLoadUpdateFiles();
    void read_setting();
    QString return_down_xml_name(QString,QString);
    int CheckUpdateFile(QString,QString);
    bool CheckVersion(QString,QString);
    //bool down_mark;

    QString strDownLoad;
    QString strCurrentDir;
    QString m_strTip;
    //QString DownLoadServerStr;
    QString read_ini_host;
    QString read_ini_path;
    QString read_ini_account;
    QString read_ini_password;
    qint64 read_ini_port;
    QString read_ini_type;
    QUrl DownUrl;
    QList<QString> m_listFileDir;
    QList<QString> m_listFileName;
signals:
    void return_number(int,int);
    void NeedDownLoad();
    void Not_NeedDown();
    void FinishedDown();

};
}
#endif // THREAD_H
