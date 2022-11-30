#include "widgetsplittingrenderer.h"

#include <QGridLayout>

#include "splittingpartrenderer.h"
#include "widgetsplittingrenderer.h"

WidgetSplittingRenderer::WidgetSplittingRenderer(QWidget *myWidget, int parts, QWidget *parent)
    : QWidget(parent)
{
    QGridLayout* gridLayout = new QGridLayout;

    QHBoxLayout* layout = new QHBoxLayout;
    QGraphicsScene* scene = new QGraphicsScene(this);
    scene->addWidget(myWidget);
    for(int i = 0; i < parts; ++i) {
        SplittingPartRenderer* view = new SplittingPartRenderer(myWidget, scene, i, parts);
        layout->addWidget(view);
    }
    gridLayout->addLayout(layout, 0, 0);

    hScrollbar = new QScrollBar;
    hScrollbar->setOrientation(Qt::Horizontal);
    gridLayout->addWidget(hScrollbar, 1, 0);

    vScrollbar = new QScrollBar;
    vScrollbar->setOrientation(Qt::Vertical);
    gridLayout->addWidget(vScrollbar, 0, 1);

    setLayout(gridLayout);
}

QScrollBar *WidgetSplittingRenderer::horizontalScrollBar() const
{
    return hScrollbar;
}

QScrollBar *WidgetSplittingRenderer::verticalScrollBar() const
{
    return vScrollbar;
}
