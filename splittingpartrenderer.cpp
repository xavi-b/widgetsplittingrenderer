#include "splittingpartrenderer.h"

#include <QResizeEvent>
#include <QScrollBar>

SplittingPartRenderer::SplittingPartRenderer(QWidget *widget, QGraphicsScene *scene, int offset, int parts, QWidget *parent)
    : QGraphicsView(scene, parent),
      widget(widget),
      offset(offset),
      parts(parts)
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    updateSize(size());
}

void SplittingPartRenderer::updateSize(QSize size)
{
    widget->resize(QSize(size.width(), size.height() * parts));
    scene()->setSceneRect(0, 0, size.width(), size.height() * parts);
    verticalScrollBar()->setValue((verticalScrollBar()->maximum() - verticalScrollBar()->minimum()) * offset / (parts - 1));
}

void SplittingPartRenderer::resizeEvent(QResizeEvent *event)
{
    updateSize(event->size());
    QGraphicsView::resizeEvent(event);
}
