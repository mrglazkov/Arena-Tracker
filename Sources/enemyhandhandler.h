#ifndef ENEMYHANDHANDLER_H
#define ENEMYHANDHANDLER_H

#include "handcard.h"
#include "ui_mainwindow.h"
#include "deckhandler.h"
#include <QObject>
#include <QMap>

#define COIN QString("GAME_005")

class EnemyHandHandler : public QObject
{
    Q_OBJECT
public:
    EnemyHandHandler(QObject *parent, Ui::MainWindow *ui);
    ~EnemyHandHandler();

//Variables
private:
    QList<HandCard> enemyHandList;
    Ui::MainWindow *ui;
    bool inGame;

//Metodos
private:
    void reset();
    void completeUI();

public:
    void redrawDownloadedCardImage(QString code);
    void showCount();

signals:
    void checkCardImage(QString code);
    void sendLog(QString line);
    void sendStatusBarMessage(QString message, int timeout=0);

public slots:
    void lastHandCardIsCoin();
    void showEnemyCardDraw(int id, int turn, bool special, QString code);
    void showEnemyCardPlayed(int id, QString code);
    void lockEnemyInterface();
    void unlockEnemyInterface();
};

#endif // ENEMYHANDHANDLER_H