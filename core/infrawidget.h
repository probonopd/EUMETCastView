#ifndef INFRAWIDGET_H
#define INFRAWIDGET_H

#include <QWidget>
#include <QPainter>

class InfraWidget : public QWidget
{
    Q_OBJECT
public:
    explicit InfraWidget(QWidget *parent = 0);
    void setlowcursor(float low);
    void sethighcursor(float high);
    QColor getColor(float value);
    void setInverse(bool inv) { inverse = inv; lowlimit = 0.0; highlimit = 1.0; }
    bool getInverse() { return inverse; }
    void initializeLowHigh() { lowlimit = 0.0; highlimit = 1.0; }
    void drawInfraWidget(QPainter *paint, int x, int y, int width, int height);
    float lowlimit;
    float highlimit;

signals:

public slots:

protected:
  void paintEvent( QPaintEvent * );
  bool grablowlimit;
  bool grabhighlimit;
  bool inverse;

};

#endif // INFRAWIDGET_H
