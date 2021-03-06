#ifndef QIGDCCHAT
#define QIGDCCHAT

#include "../core/qchatservice.h"

class QNetworkAccessManager;

class QIgdcChat: public QChatService
{
    Q_OBJECT
public:
    explicit                QIgdcChat( QObject * parent = nullptr );
                            ~QIgdcChat() override;

protected:
    void                    timerEvent( QTimerEvent * event ) override;
private:
    void                    loadSettings();

    void                    loadChannelInfo();

    void                    loadStatistic();

    void                    loadMessages();

public slots:
    void                    connect() override;
    void                    disconnect() override;
    void                    reconnect() override;

private slots:
    void                    onChannelInfoLoaded();
    void                    onChannelInfoLoadError();

    void                    onMessagesLoaded();
    void                    onMessagesLoadError();

    void                    onStatisticLoaded();
    void                    onStatisticLoadError();

    void                    changeBadges( bool badges );

private:
    QNetworkAccessManager * nam_;
    QString                 channelName_;
    QString                 channelId_;
    QString                 lastMessageId_ = {QString( "0" )};
    int                     updateMessagesTimerId_ = {-1};
    int                     reconnectTimerId_ = {-1};
    int                     statisticTimerId_ = {-1};
    bool                    badges_ = {false};

    static const QString    SERVICE_NAME;
    static const QString    SERVICE_USER_NAME;

    static const int        UPDATE_INTERVAL;
    static const int        RECONNECT_INTERVAL;
    static const int        STATISTIC_INTERVAL;
};

#endif // QIGDCCHAT

