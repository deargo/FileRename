#include "renameWindow.h"
#include "ui_renameWindow.h"
#include <QProxyStyle>
#include <QDebug>
#include <QPainter>
#include <QTabWidget>

class CustomTabStyle:public QProxyStyle
{
public:
    CustomTabStyle(){}

    //����Bar��������ݴ�С
    QSize sizeFromContents(ContentsType type, const QStyleOption *option, const QSize &size, const QWidget *widget) const
    {
        QSize newSize = QProxyStyle::sizeFromContents(type, option, size, widget);
        if (type == QStyle::CT_TabBarTab) {
            //���ø߶ȺͿ��
            newSize.setHeight(35);
            newSize.setWidth(60);
        }
        return newSize;
    }

    void drawControl(ControlElement element, const QStyleOption *option, QPainter *painter, const QWidget *widget) const
    {
        if (element == CE_TabBarTabLabel) {
            if (const QStyleOptionTab *tab = qstyleoption_cast<const QStyleOptionTab *>(option)) {
                QRect allRect = tab->rect;
                if (tab->state & QStyle::State_Selected) {
                    painter->save();
                    painter->setPen(0x89cfff);//��ɫ�ױ߿�
                    painter->drawRect(allRect.adjusted(6, 6, -6, -6));
                    painter->restore();
                }
                //����λ�þ���
                QTextOption option;
                option.setAlignment(Qt::AlignCenter);
                painter->drawText(allRect, tab->text, option);
                return;
            }
        }
        if (element == CE_TabBarTab) {
            QProxyStyle::drawControl(element, option, painter, widget);
        }
    }
};

renameWindow::renameWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::renameWindow)
{
    ui->setupUi(this);
    //������С����
    this->setMinimumSize(this->size());
    ui->tabWidget->tabBar()->setStyle(new CustomTabStyle);
}

renameWindow::~renameWindow()
{
    delete ui;
}

