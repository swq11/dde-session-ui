/*
 * Copyright (C) 2014 ~ 2018 Deepin Technology Co., Ltd.
 *
 * Author:     kirigaya <kirigaya@mkacg.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp -a notifications_dbus_adaptor -c NotificationsDBusAdaptor org.freedesktop.Notifications.xml
 *
 * qdbusxml2cpp is Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies).
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#include "notifications_dbus_adaptor.h"
#include <QtCore/QMetaObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include "bubblemanager.h"

#include <DDesktopServices>


DCORE_USE_NAMESPACE


/*
 * Implementation of adaptor class NotificationsDBusAdaptor
 */

NotificationsDBusAdaptor::NotificationsDBusAdaptor(QObject *parent)
    : QDBusAbstractAdaptor(parent)
{
    // constructor
    setAutoRelaySignals(true);
}

NotificationsDBusAdaptor::~NotificationsDBusAdaptor()
{
    // destructor
}

void NotificationsDBusAdaptor::CloseNotification(uint in0)
{
    // handle method call org.freedesktop.Notifications.CloseNotification
    QMetaObject::invokeMethod(parent(), "CloseNotification", Q_ARG(uint, in0));
}

QStringList NotificationsDBusAdaptor::GetCapabilities()
{
    // handle method call org.freedesktop.Notifications.GetCapabilities
    QStringList out0;
    QMetaObject::invokeMethod(parent(), "GetCapabilities", Q_RETURN_ARG(QStringList, out0));
    return out0;
}

QString NotificationsDBusAdaptor::GetServerInformation(QString &out1, QString &out2, QString &out3)
{
    // handle method call org.freedesktop.Notifications.GetServerInformation
    return static_cast<BubbleManager*>(parent())->GetServerInformation(out1, out2, out3);
}

uint NotificationsDBusAdaptor::Notify(const QString &in0, uint in1, const QString &in2, const QString &in3, const QString &in4, const QStringList &in5, const QVariantMap &in6, int in7)
{
    // handle method call org.freedesktop.Notifications.Notify
    uint out0;
    QMetaObject::invokeMethod(parent(), "Notify", Q_RETURN_ARG(uint, out0), Q_ARG(QString, in0), Q_ARG(uint, in1), Q_ARG(QString, in2), Q_ARG(QString, in3), Q_ARG(QString, in4), Q_ARG(QStringList, in5), Q_ARG(QVariantMap, in6), Q_ARG(int, in7));
    return out0;
}

//////////////////////////////////

DDENotifyDBus::DDENotifyDBus(QObject *parent)
    : QDBusAbstractAdaptor(parent)
{
    // constructor
    setAutoRelaySignals(true);
}

DDENotifyDBus::~DDENotifyDBus()
{
    // destructor
}

void DDENotifyDBus::CloseNotification(uint in0)
{
    // handle method call org.freedesktop.Notifications.CloseNotification
    QMetaObject::invokeMethod(parent(), "CloseNotification", Q_ARG(uint, in0));
}

QStringList DDENotifyDBus::GetCapabilities()
{
    // handle method call org.freedesktop.Notifications.GetCapabilities
    QStringList out0;
    QMetaObject::invokeMethod(parent(), "GetCapabilities", Q_RETURN_ARG(QStringList, out0));
    return out0;
}

QString DDENotifyDBus::GetServerInformation(QString &out1, QString &out2, QString &out3)
{
    // handle method call org.freedesktop.Notifications.GetServerInformation
    return static_cast<BubbleManager*>(parent())->GetServerInformation(out1, out2, out3);
}

uint DDENotifyDBus::Notify(const QString &in0, uint in1, const QString &in2, const QString &in3, const QString &in4, const QStringList &in5, const QVariantMap &in6, int in7)
{
    // handle method call org.freedesktop.Notifications.Notify
    uint out0;
    QMetaObject::invokeMethod(parent(), "Notify", Q_RETURN_ARG(uint, out0), Q_ARG(QString, in0), Q_ARG(uint, in1), Q_ARG(QString, in2), Q_ARG(QString, in3), Q_ARG(QString, in4), Q_ARG(QStringList, in5), Q_ARG(QVariantMap, in6), Q_ARG(int, in7));
    return out0;
}

QString DDENotifyDBus::GetAllRecords()
{
    QString out0;
    QMetaObject::invokeMethod(parent(), "GetAllRecords", Q_RETURN_ARG(QString, out0));
    return out0;
}

QString DDENotifyDBus::GetRecordById(const QString &id)
{
    QString out0;
    QMetaObject::invokeMethod(parent(), "GetRecordById", Q_RETURN_ARG(QString, out0), Q_ARG(QString, id));
    return out0;
}

QString DDENotifyDBus::GetRecordsFromId(int rowCount, const QString &offsetId)
{
    QString out0;
    QMetaObject::invokeMethod(parent(), "GetRecordsFromId", Q_RETURN_ARG(QString, out0), Q_ARG(int, rowCount), Q_ARG(QString, offsetId));
    return out0;
}

void DDENotifyDBus::RemoveRecord(const QString &id)
{
    QMetaObject::invokeMethod(parent(), "RemoveRecord", Q_ARG(QString, id));
}

void DDENotifyDBus::ClearRecords()
{
    QMetaObject::invokeMethod(parent(), "ClearRecords");
}

void DDENotifyDBus::doAction(uint id, const QString &action)
{
    QMetaObject::invokeMethod(parent(), "bubbleActionInvoked", Q_ARG(uint, id), Q_ARG(QString, action));
}

void DDENotifyDBus::Toggle()
{
    QMetaObject::invokeMethod(parent(), "Toggle");
}

uint DDENotifyDBus::recordCount()
{
    uint out0;
    QMetaObject::invokeMethod(parent(), "recordCount", Q_RETURN_ARG(uint, out0));
    return out0;
}

QString DDENotifyDBus::getAllSetting()
{
    QString out0;
    QMetaObject::invokeMethod(parent(), "getAllSetting", Q_RETURN_ARG(QString, out0));
    return  out0;
}

void DDENotifyDBus::setAllSetting(const QString settings)
{
    QMetaObject::invokeMethod(parent(), "setAllSetting", Q_ARG(QString, settings));
}

QString DDENotifyDBus::getAppSetting(QString appName)
{
    QString out0;
    QMetaObject::invokeMethod(parent(), "getAppSetting", Q_RETURN_ARG(QString, out0), Q_ARG(QString, appName));
    return  out0;
}

void DDENotifyDBus::setAppSetting(const QString settings)
{
    QMetaObject::invokeMethod(parent(), "setAppSetting", Q_ARG(QString, settings));
}

QString DDENotifyDBus::getSystemSetting()
{
    QString out0;
    QMetaObject::invokeMethod(parent(), "getSystemSetting", Q_RETURN_ARG(QString, out0));
    return  out0;
}

void DDENotifyDBus::setSystemSetting(QString settings)
{
    QMetaObject::invokeMethod(parent(), "setSystemSetting", Q_ARG(QString, settings));
}
