#ifndef ROUNDITEMBUTTON
#define ROUNDITEMBUTTON

#include <QObject>
#include <QFrame>
#include <QAbstractButton>
#include <QPushButton>
#include <QLabel>
#include <QtWidgets>
#include <QFocusEvent>
#include <QLabel>
#include <QGraphicsDropShadowEffect>

#include "util_signalmanager.h"

/* The RoundItemButton is used by shutdownButton, restartButton, and so on... */

class RoundItemButton: public QAbstractButton
{
    Q_OBJECT
    Q_PROPERTY(QString normalIcon MEMBER m_normalIcon DESIGNABLE true NOTIFY iconChanged)
    Q_PROPERTY(QString hoverIcon MEMBER m_hoverIcon DESIGNABLE true NOTIFY iconChanged)
    Q_PROPERTY(QString checkedIcon MEMBER m_checkedIcon DESIGNABLE true NOTIFY iconChanged)

public:
    RoundItemButton(const QString &text, QWidget* parent=0);
    ~RoundItemButton();

    enum State {Normal, Hover, Checked};

    inline bool isChecked() const {return m_state == Checked;}
    inline void setState(const State state) {updateState(state);}
    inline State state() const {return m_state;}
    inline const QString text() const {return m_itemText->text();}
    inline void setText(const QString &text) {m_itemText->setText(text);}

signals:
    void stateChanged(const State state);
    void clicked();
    void iconChanged();

private:
    void initUI();
    void initConnect();
    void updateState(const State state);
    void paintEvent(QPaintEvent* event);
    void enterEvent(QEvent* event);
    void leaveEvent(QEvent* event);
    void mouseReleaseEvent(QMouseEvent* e);
//    void setChecked(bool checked);

private slots:
    void updateIcon();

private:
    State m_state = Normal;

    QLabel *m_itemIcon;
    QLabel *m_itemText;

    QString m_normalIcon;
    QString m_hoverIcon;
    QString m_checkedIcon;
};
#endif // ROUNDITEMBUTTON
