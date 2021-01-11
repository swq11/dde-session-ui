/*
 * Copyright (C) 2015 ~ 2018 Deepin Technology Co., Ltd.
 *
 * Author:     sbw <sbw@sbw.so>
 *             Hualet <mr.asianwang@gmail.com>
 *             kirigaya <kirigaya@mkacg.com>
 *
 * Maintainer: sbw <sbw@sbw.so>
 *             Hualet <mr.asianwang@gmail.com>
 *             kirigaya <kirigaya@mkacg.com>
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

#include "buttondelegate.h"
#include "processinfomodel.h"
#include "dmemorywarningdialog.h"

#include <QApplication>
#include <QProcess>
#include <QDebug>
#include <QPainter>

#include <ddialog.h>

#if (DTK_VERSION >= DTK_VERSION_CHECK(2, 0, 8, 0))
#include <DDBusSender>
#else
#include <QProcess>
#endif

DWIDGET_USE_NAMESPACE

void terminate(const QStringList &pidList, const QPixmap &icon)
{
    if (confirm(icon))
        for (const auto &pid : pidList) {
            qDebug() << "terminate kill process pid:" << pid;
            QProcess::startDetached("kill", QStringList() << "-9" << pid);

        }
}

void close_tab(const QList<int> &tabs)
{
    if (!confirm(QIcon::fromTheme("google-chrome").pixmap(32, 32)))
        return;

    for (auto tab : tabs)
        DDBusSender()
            .service("com.deepin.chromeExtension.TabsLimit")
            .interface("com.deepin.chromeExtension.TabsLimit")
            .path("/com/deepin/chromeExtension/TabsLimit")
            .method("CloseTab")
            .arg(QString::number(tab))
            .call();
}

ButtonDelegate::ButtonDelegate(QObject *parent)
    : QItemDelegate(parent)
{

}

void ButtonDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (index.row() % 2)
        painter->fillRect(option.rect, QColor(0, 0, 0, 255 * 0.05));

    QStyleOptionButton button;
    button.rect = option.rect.marginsRemoved(QMargins(6, 6, 6, 6));
    button.text = index.data().toString();
    button.state = QStyle::State_Enabled;
    if (index.data(ProcessInfoModel::StateRole).toBool())
        button.state |= QStyle::State_Sunken | QStyle::State_Active;

    QApplication::style()->drawControl(QStyle::CE_PushButton, &button, painter);
}

bool ButtonDelegate::editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index)
{
    Q_UNUSED(option);

    switch (event->type())
    {
    case QEvent::MouseButtonPress:
        model->setData(index, QVariant(), ProcessInfoModel::StateRole);
        break;
    case QEvent::MouseButtonRelease:
    {
        const auto &pidList = index.data(ProcessInfoModel::PidListRole).value<QStringList>();
        if (!pidList.isEmpty())
            terminate(pidList, index.data(ProcessInfoModel::IconRole).value<QPixmap>());
        else
            close_tab(index.data(ProcessInfoModel::TabListRole).value<QList<int>>());
        break;
    }
    default:;
    }

    return true;
}
