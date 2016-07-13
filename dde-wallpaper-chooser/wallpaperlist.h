#ifndef WALLPAPERLIST_H
#define WALLPAPERLIST_H

#include <QListWidget>

class WallpaperItem;
class AppearanceDaemonInterface;
class WallpaperList : public QListWidget
{
    Q_OBJECT

public:
    explicit WallpaperList(QWidget * parent = 0);
    ~WallpaperList();

    WallpaperItem * addWallpaper(const QString &path);
    void removeWallpaper(const QString &path);

signals:
    void wallpaperSet(QString wallpaper);
    void needCloseButton(QString path, QPoint pos);

protected:
    void wheelEvent(QWheelEvent *);

private:
    AppearanceDaemonInterface * m_dbusAppearance;

    void setWallpaper(QString realPath);
    void setLockScreen(QString realPath);

private slots:
    void wallpaperItemPressed();
    void wallpaperItemHoverIn();
    void wallpaperItemHoverOut();
    void handleSetDesktop();
    void handleSetDesktopLock();
};

#endif // WALLPAPERLIST_H
