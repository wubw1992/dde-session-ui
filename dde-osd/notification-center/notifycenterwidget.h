/*
 * Copyright (C) 2011 ~ 2018 Deepin Technology Co., Ltd.
 *
 * Author:     sbw <sbw@sbw.so>
 *             kirigaya <kirigaya@mkacg.com>
 *             Hualet <mr.asianwang@gmail.com>
 *
 * Maintainer: sbw <sbw@sbw.so>
 *             kirigaya <kirigaya@mkacg.com>
 *             Hualet <mr.asianwang@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include "notifywidget.h"
#include <DBlurEffectWidget>

DWIDGET_USE_NAMESPACE

static const int CenterWidth = 400;
static const int CenterMargin = 10;

class QStackedLayout;
class NotifyCenterWidget : public DBlurEffectWidget
{
    Q_OBJECT
public:
    explicit NotifyCenterWidget(QWidget *parent = nullptr);

protected:
    void showEvent(QShowEvent *event) override;
    void hideEvent(QHideEvent *event) override;

private:
    void initUI();
    void initAnimations();
    void updateGeometry();

private:
    QTimer *m_timeRefersh;
    QStackedLayout *m_contentLayout;
    NotifyWidget *m_notifyWidget;
    QDBusInterface *m_dockSizeInter;

    QPropertyAnimation *m_inAnimation = nullptr;
    QPropertyAnimation *m_outAnimation = nullptr;
};

#endif // MAINWIDGET_H
