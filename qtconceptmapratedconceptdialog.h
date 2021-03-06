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
#ifndef QTCONCEPTMAPRATEDCONCEPTDIALOG_H
#define QTCONCEPTMAPRATEDCONCEPTDIALOG_H

#include <string>
#include <vector>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#pragma GCC diagnostic ignored "-Wunused-but-set-parameter"
#include <boost/shared_ptr.hpp>
#include <QDialog>
#include "qtconceptmapfwd.h"
#include "conceptmapnode.h"
#include "conceptmap.h"
#pragma GCC diagnostic pop

namespace Ui { class QtConceptMapRatedConceptDialog; }

namespace ribi {
namespace cmap {

class QtConceptMapRatedConceptDialog : public QDialog
{
  Q_OBJECT //!OCLINT
  
public:

  explicit QtConceptMapRatedConceptDialog(
    const ConceptMap& conceptmap,
    const Node& node,
    QWidget *parent = 0
  );
  QtConceptMapRatedConceptDialog(const QtConceptMapRatedConceptDialog&) = delete;
  QtConceptMapRatedConceptDialog& operator=(const QtConceptMapRatedConceptDialog&) = delete;
  ~QtConceptMapRatedConceptDialog() noexcept;

  ///Hides the rating. This is used when a student views his/her
  ///work before an assessor has rated his/her work
  void HideRating() noexcept;

private slots:
  void DoResizeLists() noexcept;

private:
  Ui::QtConceptMapRatedConceptDialog *ui;
  QTimer * const m_timer;

  void AddExamples(const Edge& edge) noexcept;
  void DisplayEdges(const ConceptMap& conceptmap, const Node& node) noexcept;
  void DisplayHeading(const Node& node) noexcept;

  std::string GetFromArrowText(
    const Edge& edge, const ConceptMap& conceptmap
  ) const noexcept;
  std::string GetToArrowText(
    const Edge& edge, const ConceptMap& conceptmap
  ) const noexcept;

  void PutExamplesInList(const Node& node) noexcept;
};

} //~namespace cmap

} //~namespace ribi

#endif // QTCONCEPTMAPRATEDCONCEPTDIALOG_H
