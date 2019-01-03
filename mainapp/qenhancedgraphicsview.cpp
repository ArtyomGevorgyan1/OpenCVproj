#include "qenhancedgraphicsview.h"

QEnhancedGraphicsView::QEnhancedGraphicsView(QWidget *parent)
    : QGraphicsView(parent)
{

}

void QEnhancedGraphicsView::wheelEvent(QWheelEvent *event)
{
    if (event->orientation() == Qt::Vertical)
    {
        double angleDeltaY = event->angleDelta().y();
        double zoomFactor = qPow(1.0015, angleDeltaY);

        // scale the current view by x, y factors
        scale(zoomFactor, zoomFactor);
        if(angleDeltaY > 0)
        {
            // center the window around the point to which the mouse is pointing
            this->centerOn(sceneMousePos);
            sceneMousePos = this->mapToScene(event->pos());
        }
        this->viewport()->update();
        event->accept();
    }
    else
    {
        event->ignore();
    }
}
