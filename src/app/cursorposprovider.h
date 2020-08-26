#include <QObject>
#include <QPoint>
#include <QCursor>

class CursorPosProvider : public QObject
{
    Q_OBJECT
public:
    explicit CursorPosProvider(QObject *parent = nullptr) : QObject(parent)
    {
    }
    virtual ~CursorPosProvider() = default;

public slots:

    // gets current cursor position
    QPoint cursorPos()
    {
        return QCursor::pos();
    }
};
