/**
 * Copyright (C) 2015 Deepin Technology Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 **/

#include <QDebug>

#include "backgroundlabel.h"
#include "shutdownframe.h"

ShutdownFrame::ShutdownFrame(QWidget *parent)
    : BoxFrame(parent)
{
    this->move(0, 0);
    this->setFixedSize(qApp->desktop()->size());

    qDebug() << "this geometry:" << geometry();

    initShutdownManager();
    initBackground();

    ShutdownFrontDBus* shutdownFrontDBus = new ShutdownFrontDBus(this);
    QDBusConnection::sessionBus().registerObject(DBUS_PATH, this);

    qDebug() << "RegistshutdownFrontDBus" << shutdownFrontDBus->result();
}

void ShutdownFrame::updateScreenPosition() {
    m_shutdownManager->updateGeometry();
}

void ShutdownFrame::keyPressEvent(QKeyEvent *e) {
    Q_UNUSED(e);
}

void ShutdownFrame::initShutdownManager()
{
    m_shutdownManager = new ShutdownManager(this);
    QPoint mousePoint = QCursor::pos();

    QList<QScreen *> screenList = qApp->screens();
    for (int i = 0; i < screenList.length(); i++) {
        const QRect rect = screenList[i]->geometry();
        if (rect.contains(mousePoint)) {
            m_shutdownManager->setFixedSize(rect.size());
            m_shutdownManager->move(rect.x(), rect.y());
            qDebug() << "shutdownManager:" << m_shutdownManager->geometry();
            updateScreenPosition();
            continue;
        }
    }
}

void ShutdownFrame::initBackground()
{
    const QString username = qgetenv("USER");
    const QSettings settings("/var/lib/AccountsService/users/" + username, QSettings::IniFormat);
    const QString background = settings.value("User/Background").toString();

    qDebug() << "user:" << qgetenv("USER") << " background: " << background;

    if (!background.isEmpty()) {
        setBackground(background);
    }
}

ShutdownFrame::~ShutdownFrame()
{
}

ShutdownFrontDBus::ShutdownFrontDBus(ShutdownFrame *parent):
    QDBusAbstractAdaptor(parent),
    m_parent(parent)
{
    qDebug() << "DBUS_PATH" << DBUS_PATH;
}

ShutdownFrontDBus::~ShutdownFrontDBus()
{

}

qulonglong ShutdownFrontDBus::result()
{
    return 0;
}
