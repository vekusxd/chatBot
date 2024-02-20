#include "../include/helpcommandswidget.hpp"
#include <QVBoxLayout>

HelpCommandsWidget::HelpCommandsWidget(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    view = new QListView;
    model = new HelpCommandsModel;

    view->setModel(model);

    mainLayout->addWidget(view);
    connect(view, &QListView::doubleClicked, this, &HelpCommandsWidget::onDoubleClickedView);
}

QStringList HelpCommandsWidget::getCommands()
{
    return model->getCommands();
}

void HelpCommandsWidget::onDoubleClickedView(const QModelIndex& index)
{
    int indexRow = index.row();
    emit sendClickedCommand(model->commands.at(indexRow));
}
