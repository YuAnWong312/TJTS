#ifndef CHTTPDOWNLOADFILE_H
#define CHTTPDOWNLOADFILE_H

#include <QObject>
#include <QtNetwork/QNetworkReply>
#include <QFileInfo>
#include <QtCore/QtCore>
#include <QtNetwork/QNetworkAccessManager>
#include "qtUpdate/Export.h"
#include"osgMessageBox/dialogform.h"
#include"osgMessageBox/confirmdialog.h"
#include <QUrl>

namespace qtUpdate {

class QTUPDATE_EXPORT CHttpDownloadFile: public QObject
{
        Q_OBJECT
public:
    explicit CHttpDownloadFile(QUrl url,QString fileName,QString dir,QObject *parent = 0);
    ///url表示文件的网络地址；
    ///filename表示文件名；
    ///dir表示文件存储路径


    void DownLoadFile();




    QNetworkAccessManager *m_netAccessManager;//网络参数
    QNetworkReply *m_netReply;
    QUrl m_urlAdress;//网络地址
    QString m_strFileName;//需要下载的文件名
    QString m_strDir;//文件储存路径
    QFile *m_file;//下载的文件
    qint64 m_nTotal;
    bool m_bIsFinished;


public slots:
    void ReplyNewDateArrived();//有新数据时反应槽
    void ReplyFinished();//数据发送完毕反应槽
    void ReplyError(QNetworkReply::NetworkError);//数据发送错误反应槽
    void ReplyDownloadProgress(qint64 a, qint64);//数据发送进度
};
}
#endif // CHTTPDOWNLOADFILE_H
