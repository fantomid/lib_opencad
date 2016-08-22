/*******************************************************************************
 *  Project: libopencad
 *  Purpose: OpenSource CAD formats support library
 *  Author: Alexandr Borzykh, mush3d at gmail.com
 *  Author: Dmitry Baryshnikov, bishop.dev@gmail.com
 *  Language: C++
 *******************************************************************************
 *  The MIT License (MIT)
 *
 *  Copyright (c) 2016 Alexandr Borzykh
 *  Copyright (c) 2016 NextGIS, <info@nextgis.com>
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in all
 *  copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *  SOFTWARE.
 *******************************************************************************/
#ifndef CADTABLES_H
#define CADTABLES_H

#include "cadheader.h"
#include "cadlayer.h"

class CADFile;

using namespace std;

/**
 * @brief The CAD tables class. Store tables
 */
class OCAD_EXTERN CADTables
{
public:
    /**
     * @brief The CAD table types enum
     */
    enum TableType
    {
        CurrentViewportTable,
        BlocksTable,
        LayersTable,
        StyleTable,
        LineTypesTable,
        ViewTable,
        UCSTable,
        ViewportTable,
        APPIDTable,
        EntityTable,
        ACADGroupDict,
        ACADMLineStyleDict,
        NamedObjectsDict,
        LayoutsDict,
        PlotSettingsDict,
        PlotStylesDict,
        BlockRecordPaperSpace,
        BlockRecordModelSpace
    };
public:
    CADTables();
    
    void                addTable(enum TableType eType, CADHandle hHandle);
    CADHandle           getTableHandle(enum TableType);
    int                 readTable(CADFile * const file, enum TableType eType);
    size_t              getLayerCount() const;
    CADLayer&           getLayer(size_t index);

protected:
    int                 readLayersTable(CADFile * const file, long index);
    void                fillLayer(const CADEntityObject* ent);
protected:
    map<enum TableType, CADHandle>  tableMap;
    vector<CADLayer>                layers;
};

#endif // CADTABLES_H
