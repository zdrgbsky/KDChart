/****************************************************************************
** Copyright (C) 2001-2021 Klaralvdalens Datakonsult AB.  All rights reserved.
**
** This file is part of the KD Chart library.
**
** Licensees holding valid commercial KD Chart licenses may use this file in
** accordance with the KD Chart Commercial License Agreement provided with
** the Software.
**
**
** This file may be distributed and/or modified under the terms of the
** GNU General Public License version 2 and version 3 as published by the
** Free Software Foundation and appearing in the file LICENSE.GPL.txt included.
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
** Contact info@kdab.com if any conditions of this licensing are not
** clear to you.
**
**********************************************************************/

#ifndef PROJECTMODEL_H
#define PROJECTMODEL_H

#include <QAbstractItemModel>

class ProjectModel : public QAbstractItemModel {
    Q_OBJECT
public:
    explicit ProjectModel( QObject* parent = 0 );
    ~ProjectModel() override;

    /*reimp*/ int rowCount( const QModelIndex& idx ) const override;
    /*reimp*/ int columnCount( const QModelIndex& idx ) const override;

    /*reimp*/ QModelIndex index( int row, int col, const QModelIndex& parent = QModelIndex() ) const override;
    /*reimp*/ QModelIndex parent( const QModelIndex& idx ) const override;

    /*reimp*/QVariant headerData( int section, Qt::Orientation orientation, int role = Qt::DisplayRole ) const override;
    /*reimp*/ QVariant data( const QModelIndex& idx, int role = Qt::DisplayRole ) const override;
    /*reimp*/ bool setData( const QModelIndex& idx,  const QVariant& value,
                            int role = Qt::DisplayRole ) override;

    /*reimp*/ bool insertRows( int row, int count, const QModelIndex& parent = QModelIndex() ) override;

    /*reimp*/ Qt::ItemFlags flags( const QModelIndex& ) const override;

    bool load( const QString& filename );
    bool save( const QString& filename );

private:
    class Node;

    Node* m_root;
};

#endif /* PROJECTMODEL_H */

