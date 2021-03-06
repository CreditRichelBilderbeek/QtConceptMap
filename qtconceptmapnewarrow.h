//---------------------------------------------------------------------------
/*
QtConceptMap, Qt classes for display and interaction with ConceptMap
Copyright (C) 2013-2016 Richel Bilderbeek

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.If not, see <http://www.gnu.org/licenses/>.
*/
//---------------------------------------------------------------------------
//From http://www.richelbilderbeek.nl/CppQtConceptMap.htm
//---------------------------------------------------------------------------
#ifndef QTCONCEPTMAPNEWARROW_H
#define QTCONCEPTMAPNEWARROW_H

#include <string>
#include <vector>


#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#pragma GCC diagnostic ignored "-Wunused-but-set-parameter"
#include <QBrush>
#include "qtarrowitem.h"
#include "qtconceptmapfwd.h"
#pragma GCC diagnostic pop

namespace ribi {
namespace cmap {

///QtNewArrow is the arrow shown before a new one is added
struct QtNewArrow : public QtArrowItem
{
  QtNewArrow();

  ///Set and show the arrow in itis initial condition
  void Start(QtNode * const from);

  QtNewArrow(const QtNewArrow&) = delete;
  QtNewArrow& operator=(const QtNewArrow&) = delete;

  ///Obtain the source node, can be nullptr
  const QtNode * GetFrom() const noexcept;
  QtNode * GetFrom() noexcept;

  private:
  ///Must be suppplied
  void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);

  ///The source node
  ///Cannot be const as the user might want to edit it
  QtNode * m_from;
};

} //~namespace cmap
} //~namespace ribi

#endif // QTCONCEPTMAPNEWARROW_H
