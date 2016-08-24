#ifndef CONTROLCENTER_H
#define CONTROLCENTER_H 1

#include <QObject>
#include<QtSql/QtSql>
#include<QDebug>
#include<QGraphicsItem>
#include<QTimer>
#include"osgSQL/DBHelper.h"
#include"qtBackGround/node.h"
#include"qtBackGround/textitem.h"
#include"qtBackGround/maincanvas.h"
#include<QMessageBox>
#include"qtLogicControl/Export.h"
#include"GLOBAL.h"
class  QTLOGICCONTROL_EXPORT ControlCenter : public QObject
{
    Q_OBJECT
public:
      explicit ControlCenter(QObject *parent = 0);
      QMenu  *menu_st ,*menu_gc_he,*menu_gc;
       QAction *action_Down, *action_below, *action_upward,*action_opening, *action_closed;
       QTimer MalTimer;
      QString  MalOrder;
      QTimer  MalBZTTimer;
      QString  MalBZTOrder;
      QString  SLTName;
      QString  SLTDescri;
      QString  SLTRemark;
      QString DLQ;
      QString DLQReamark;
      QString DLQName;
      QString MalName;
      int sceneID;
      QString SLTstation;
      bool checkOSGdd;
      QString currentSceneName;
      QString currentNodeName;
      QMap<QString,QString> getHanNode(const QString &stationName, const QString &nodeName,const int &currentFPS,const QString &colorName);
public slots:
    void  malFunctionReset(QString,int);
    void operateItemMalFunction(QString,int);
    QString getStationName(QString,QString);
    void malFunctionSimulation(QString,int );
    void GetOperaResponse(QString,QString);
    void GetOperate();
     void OperateItem(QString,int);
     int GetHandleSceneID(QString,QString,int);
     void voiceTip(QString,QString);
     void voiceTip(int);
     void operateItemByOSG(QString,QString,QString);

     void checkItemOSGToLogicControl(QString,QString,QString,QString);
     void checkBG_LogicCenter(int,QString,QString,QString);
     void operateBG_LogicCenter(int,QString,QString,QString);
     void GetOperaResponseBZT(QString,QString);
      void GetOperateBZT();
      void OSGToLogicControl(const QString &sceneName,const QString &nodeName,const int &currentFPS,const QString &colorName);
      void modelLogicCondition(const QString &sceneName,const QString &sql);
      void modelLogicResponse(const QString &sceneName,const QString &sql);
      void modelLogicResponseExplain(const QString &sceneName,const QString &resNodeName,const QString &resNodeKind,const QString &resNodeStatus);
      void modelLogicConditionExplain(const QString &sceneName,const QString &resNodeName,const QString &resNodeKind,const QString &resNodeStatus);
      QString getNodeStatus( const QString &nodeName,const int &currentFPS,const QString &colorName);
      void stysk_down();
      void stysk_upward();
      void stysk_below();
      void gk_opening();
      void gk_closed();
signals:
    void FaultReportShow(QString);
    void showEvent();
    void operateItemToBackGround(QString,QString,QString);
    void operateItemToOSG(QString,QString,QString);
    void checkItemBackGroundToLogicControlException(QString,QString,QString,int);
    void checkItemBackGroundToLogicControl(QString,QString,QString,int);
    void operateItemBackGroundToLogicControl(QString,QString,QString,int);
    void operateItemLogicToOSG(QString,QString,int);
    void checkBG_Voltage(QString,QString);
    void checkOSGMalFinctionCondition(QString,QString,QString,QString);
    void checkBG_BZT(QString,QString,QString,QString,QString);
    void LogicControlToOSGOperateAnimation(const QString &sceneName,const QString &nodeName,const int &endFPS);
    void LogicControlToOSGOperateColor(const QString &sceneName,const QString &nodeName,const QString &colrName);
    void LogicControlToOSGOperateStatus(const QString &sceneName,const QString &nodeName,const QString &statusName);
    void LogicControlToOSGCheckAnimation(const QString &sceneName,const QString &nodeName,const int &endFPS);
    void LogicControlToOSGCheckColor(const QString &sceneName,const QString &nodeName,const QString &colrName);
    void LogicControlToOSGCheckStatus(const QString &sceneName,const QString &nodeName,const QString &statusName);
    void checkYFDD(const QString &hanId, const QString &hanStatus, const int &sceneID);
       void operateItemLogicToOSGForMal(const QString &nodeName,const QString &nodeRemark,const QString &sceneID);

};
#endif // CONTROLCENTER_H
