#ifndef MUSICPLAYLISTFOUNDWIDGET_H
#define MUSICPLAYLISTFOUNDWIDGET_H

/* =================================================
 * This file is part of the TTK Music Player project
 * Copyright (c) 2015 - 2017 Greedysky Studio
 * All rights reserved!
 * Redistribution and use of the source code or any derivative
 * works are strictly forbiden.
   =================================================*/

#include "musicfoundabstractwidget.h"
#include "musicqueryfoundtablewidget.h"

class QPushButton;
class QStackedWidget;
class MusicPlaylistFoundInfoWidget;

/*! @brief The class of the playlist music item widget.
 * @author Greedysky <greedysky@163.com>
 */
class MUSIC_WIDGET_EXPORT MusicPlaylistFoundItemWidget : public QLabel
{
    Q_OBJECT
public:
    explicit MusicPlaylistFoundItemWidget(QWidget *parent = 0);
    /*!
     * Object contsructor.
     */
    virtual ~MusicPlaylistFoundItemWidget();

    static QString getClassName();
    /*!
     * Get class object name.
     */

    void setMusicPlaylistItem(const MusicPlaylistItem &item);
    /*!
     * Set music playlist item.
     */

Q_SIGNALS:
    void currentPlayListClicked(const MusicPlaylistItem &item);
    /*!
     * Current play list clicked.
     */

public Q_SLOTS:
    void downLoadFinished(const QByteArray &data);
    /*!
     * Send recieved data from net.
     */
    void currentPlayListClicked();
    /*!
     * Current play list clicked.
     */

protected:
    MusicPlaylistItem m_itemData;
    QPushButton *m_topListenButton, *m_playButton;
    QLabel *m_iconLabel, *m_nameLabel, *m_creatorLabel;

};



/*! @brief The class of the playlist music found widget.
 * @author Greedysky <greedysky@163.com>
 */
class MUSIC_WIDGET_EXPORT MusicPlaylistFoundWidget : public MusicFoundAbstractWidget
{
    Q_OBJECT
public:
    explicit MusicPlaylistFoundWidget(QWidget *parent = 0);
    /*!
     * Object contsructor.
     */
    virtual ~MusicPlaylistFoundWidget();

    static QString getClassName();
    /*!
     * Get class object name.
     */

    virtual void setSongName(const QString &name) override;
    /*!
     * Set current name to search founds.
     */

    virtual void resizeWindow() override;
    /*!
     * Resize window bound by widgte resize called.
     */

public Q_SLOTS:
    void queryAllFinished(const MusicPlaylistItem &item);
    /*!
     * Query all quality musics is finished.
     */
    void currentPlayListClicked(const MusicPlaylistItem &item);
    /*!
     * Current play list clicked.
     */
    void backToPlayListMenu();
    /*!
     * Set current index to playlist menu page.
     */

protected:
    virtual void resizeEvent(QResizeEvent *event) override;
    /*!
     * Override the widget event.
     */

    bool m_firstInit;
    QStackedWidget *m_container;
    MusicPlaylistFoundInfoWidget *m_infoWidget;
    MusicDownLoadQueryThreadAbstract *m_downloadThread;

};

#endif // MUSICPLAYLISTFOUNDWIDGET_H
