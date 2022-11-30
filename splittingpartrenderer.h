#ifndef SPLITTINGPARTRENDERER_H
#define SPLITTINGPARTRENDERER_H

#include <QGraphicsView>

class SplittingPartRenderer : public QGraphicsView
{
    Q_OBJECT
public:
    explicit SplittingPartRenderer(QWidget* widget, QGraphicsScene* scene, int offset, int parts, QWidget *parent = nullptr);

protected:
    void updateSize(QSize size);
    void resizeEvent(QResizeEvent *event) override;

private:
    QWidget* widget;
    int offset;
    int parts;
};

#endif // SPLITTINGPARTRENDERER_H
