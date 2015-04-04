/***************************************************************************
 *   Copyright (C) 2015 by Eike Hein <hein@kde.org>                        *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA .        *
 ***************************************************************************/

#ifndef FORWARDINGMODEL_H
#define FORWARDINGMODEL_H

#include "abstractmodel.h"

#include <QPointer>

class ForwardingModel : public AbstractModel
{
    Q_OBJECT

    public:
        explicit ForwardingModel(QObject *parent = 0);
        ~ForwardingModel();

        QAbstractItemModel *sourceModel() const;
        void setSourceModel(QAbstractItemModel *sourceModel);

        bool canFetchMore(const QModelIndex &parent) const;
        void fetchMore(const QModelIndex &parent);

        QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const;
        QModelIndex parent(const QModelIndex &index) const;

        QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

        int rowCount(const QModelIndex &parent = QModelIndex()) const;

    private:
        void connectSignals();
        void disconnectSignals();

        QPointer<QAbstractItemModel> m_sourceModel;
};

#endif