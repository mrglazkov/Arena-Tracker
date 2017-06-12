#include "movetabwidget.h"
#include "../themehandler.h"
#include <QtWidgets>

MoveTabWidget::MoveTabWidget(QWidget *parent) : QTabWidget(parent)
{
    this->setTabBar(new MoveTabBar(this));
    this->hide();
    this->tabSize = 32;
}


void MoveTabWidget::setTheme(Theme theme, QString tabBarAlignment, int maxWidth, bool resizing)
{
    QString foregroundColor = (theme==ThemeWhite)?"black":"white";
    QString backgroundColor = (theme==ThemeWhite)?ThemeHandler::bgColor():"black";
    QString borderColor = (theme==ThemeWhite)?ThemeHandler::themeColor1():ThemeHandler::themeColor1();
    int tabSize = std::max(24, std::min(32, maxWidth/std::max(1, this->count()) - 14));

    if(resizing && (tabSize == this->tabSize)) return;

    this->setStyleSheet(
        "QTabBar::tab:selected {background: " + backgroundColor + ";border-bottom-color: " + backgroundColor + ";}"
        "QTabBar::tab:hover {background: " + backgroundColor + ";border-bottom-color: " + backgroundColor + ";}"
        "QTabWidget::tab-bar {alignment: " + tabBarAlignment + ";}"
        "QTabWidget::pane {border-color: transparent; background: " + backgroundColor + ";}"
        "QTabWidget::pane {position: absolute;top: -38px;}"
        "QTabBar::tab {border: 2px solid " + borderColor + ";"
            "padding: 5px;background: " + borderColor + "; color: " + foregroundColor +
            "; height: 24px; width: " + QString::number(tabSize) + "px}"
    );

    if(tabSize != this->tabSize)    tabBar()->setIconSize(QSize(tabSize, tabSize));
    this->tabSize = tabSize;
}



MoveTabBar::MoveTabBar(QWidget *parent) : QTabBar(parent)
{
    this->setIconSize(QSize(32,32));
}

void MoveTabBar::mouseDoubleClickEvent(QMouseEvent *event)
{
    QTabBar::mouseDoubleClickEvent(event);
    event->ignore();
}
void MoveTabBar::mouseMoveEvent(QMouseEvent *event)
{
    QTabBar::mouseMoveEvent(event);
    event->ignore();
}
void MoveTabBar::mousePressEvent(QMouseEvent *event)
{
    QTabBar::mousePressEvent(event);
    event->ignore();

}
void MoveTabBar::mouseReleaseEvent(QMouseEvent *event)
{
    QTabBar::mouseReleaseEvent(event);
    event->ignore();
}

