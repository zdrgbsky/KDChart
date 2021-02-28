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

#ifndef KDCHARTPOLARDIAGRAM_P_H
#define KDCHARTPOLARDIAGRAM_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the KD Chart API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include "KDChartAbstractPolarDiagram_p.h"

#include <KDABLibFakes>

namespace KDChart
{
/**
 * \internal
 */
class PolarDiagram::Private : public AbstractPolarDiagram::Private
{
    friend class PolarDiagram;

public:
    Private();
    ~Private() override;

    Private(const Private &rhs)
        : AbstractPolarDiagram::Private(rhs)
        , showDelimitersAtPosition(rhs.showDelimitersAtPosition)
        , showLabelsAtPosition(rhs.showLabelsAtPosition)
        , rotateCircularLabels(rhs.rotateCircularLabels)
        , closeDatasets(rhs.closeDatasets)
    {
    }

private:
    QMap<int, bool> showDelimitersAtPosition;
    QMap<int, bool> showLabelsAtPosition;
    bool rotateCircularLabels;
    bool closeDatasets;
    LabelPaintCache labelPaintCache;
};

KDCHART_IMPL_DERIVED_DIAGRAM(PolarDiagram, AbstractPolarDiagram, PolarCoordinatePlane)

}

#endif /* KDCHARTPOLARDIAGRAM_P_H */
