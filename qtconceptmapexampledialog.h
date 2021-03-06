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
#ifndef QTCONCEPTMAPEXAMPLEDIALOG_H
#define QTCONCEPTMAPEXAMPLEDIALOG_H

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#pragma GCC diagnostic ignored "-Wunused-but-set-parameter"
#include "qthideandshowdialog.h"
#include "conceptmapexample.h"

#include "qtconceptmapfwd.h"
#pragma GCC diagnostic pop

namespace Ui { class QtExampleDialog; }

namespace ribi {
namespace cmap {

///Displays and modifies an Example
class QtExampleDialog : public ribi::QtHideAndShowDialog
{
  Q_OBJECT //!OCLINT

public:
  explicit QtExampleDialog(QWidget *parent = 0);
  QtExampleDialog(const QtExampleDialog&) = delete;
  QtExampleDialog& operator=(const QtExampleDialog&) = delete;
  ~QtExampleDialog() noexcept;

  const Example& GetExample() const noexcept { return m_example; }
        Example& GetExample()       noexcept { return m_example; }
  static int GetMinimumHeight(const Example& example) noexcept;
  void SetExample(const Example& example);

private slots:
  void on_box_competency_currentIndexChanged(int index);
  void on_box_is_complex_stateChanged(int arg1);
  void on_box_is_concrete_stateChanged(int arg1);
  void on_box_is_specific_stateChanged(int arg1);
  void on_edit_text_textChanged(const QString &arg1);

private:
  Ui::QtExampleDialog *ui;

  ///The Example to work on
  Example m_example;
};

} //~namespace cmap
} //~namespace ribi

#endif // QTCONCEPTMAPEXAMPLEDIALOG_H
