#include "../include/commandcompleter.hpp"
#include <QEvent>
#include <QLineEdit>
#include <QTextCursor>
#include <QKeyEvent>

CommandCompleter::CommandCompleter(const QStringList& commands, QObject *parent)
    : _commands(commands), QCompleter(parent)
{
}

bool CommandCompleter::eventFilter(QObject *watched, QEvent *event)
{
    if(widget()->inherits("QLineEdit") && event->type() == QEvent::KeyPress){
        QKeyEvent *ke = static_cast<QKeyEvent*>(event);
        switch(ke->key()){
        case Qt::Key_Space:
            if(ke->modifiers().testFlag(Qt::ControlModifier)){
                QLineEdit *edit = qobject_cast<QLineEdit*>(widget());
                QTextCursor textCursor = edit->textCursor();
            }
            break;
        default:
            break;
        }
    }
    return QCompleter::eventFilter(watched, event);
}
