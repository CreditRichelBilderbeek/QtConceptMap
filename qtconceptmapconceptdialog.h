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
#ifndef QTCONCEPTMAPCONCEPTDIALOG_H
#define QTCONCEPTMAPCONCEPTDIALOG_H

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#pragma GCC diagnostic ignored "-Wunused-but-set-parameter"
//#include <boost/shared_ptr.hpp>
#include "qthideandshowdialog.h"

#include "qtconceptmapfwd.h"
#include "conceptmapconcept.h"
#pragma GCC diagnostic pop

namespace Ui { class QtConceptDialog; }

namespace ribi {
namespace cmap {

///Displays and modifies a Concept
class QtConceptDialog : public ribi::QtHideAndShowDialog
{
  Q_OBJECT //!OCLINT

public:
  explicit QtConceptDialog(QWidget *parent = 0);
  QtConceptDialog(const QtConceptDialog&) = delete;
  QtConceptDialog& operator=(const QtConceptDialog&) = delete;
  ~QtConceptDialog() noexcept;

  const Concept& GetConcept() const noexcept { return m_concept; }
        Concept& GetConcept()       noexcept { return m_concept; }
  static int GetMinimumHeight(const Concept& concept) noexcept;
  std::string GetUiName() const noexcept;

  void SetConcept(const Concept& concept) noexcept;
  void SetUiName(const std::string& name) noexcept;


private slots:
  void on_box_is_complex_stateChanged(int arg1) noexcept;
  void on_box_rating_complexity_valueChanged(int arg1) noexcept;
  void on_box_rating_concreteness_valueChanged(int arg1) noexcept;
  void on_box_rating_specificity_valueChanged(int arg1) noexcept;
  void on_edit_name_textChanged(const QString &arg1) noexcept;

private:
  Ui::QtConceptDialog *ui;

  ///The Concept to work on
  Concept m_concept;

  QtExamplesDialog * const m_qtexamplesdialog;
};

} //~namespace cmap
} //~namespace ribi

#endif // QTCONCEPTMAPCONCEPTDIALOG_H
