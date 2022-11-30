#ifndef WIDGETSPLITTINGRENDERER_H
#define WIDGETSPLITTINGRENDERER_H

#include <QWidget>
#include <QScrollBar>

class WidgetSplittingRenderer : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetSplittingRenderer(QWidget *myWidget, int parts, QWidget *parent = nullptr);

    QScrollBar *horizontalScrollBar() const;
    QScrollBar *verticalScrollBar() const;

private:
    QScrollBar* hScrollbar;
    QScrollBar* vScrollbar;
};

#endif // WIDGETSPLITTINGRENDERER_H
