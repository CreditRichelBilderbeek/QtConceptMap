#include "qtconceptmaprateexamplesdialog_test.h"
#include "qtconceptmaprateexamplesdialog.h"


#include <QDesktopWidget>
#include <QKeyEvent>
#include <QListWidgetItem>

#include "conceptmapconceptfactory.h"
#include "conceptmapconcept.h"
#include "conceptmapexamplefactory.h"
#include "conceptmapexamplesfactory.h"
#include "conceptmaphelper.h"
#include "qtconceptmapcompetency.h"
#include "ui_qtconceptmaprateexamplesdialog.h"

void ribi::cmap::qtconceptmaprateexamplesdialog_test::get_rated_examples()
{
  const int sz = ConceptFactory().GetTests().size();
  for (int i=0; i!=sz; ++i)
  {
    QVERIFY(i < static_cast<int>(ConceptFactory().GetTests().size()));
    const auto a = QtRateExamplesDialog(ConceptFactory().GetTests()[i]).GetRatedExamples();
    for (int j=0; j!=sz; ++j)
    {
      QVERIFY(j < static_cast<int>(ConceptFactory().GetTests().size()));
      const auto b = QtRateExamplesDialog(ConceptFactory().GetTests()[j]).GetRatedExamples();
      if (i == j)
      {
        QVERIFY(a == b);
      }
      else
      {
        QVERIFY(a != b);
      }
    }
  }
}

void ribi::cmap::qtconceptmaprateexamplesdialog_test::key_presses()
{
  QtRateExamplesDialog d(ConceptFactory().Get1());
  d.show();
  QTest::qWait(100);
  //Press all buttons
  QTest::keyPress(&d, Qt::Key_B, Qt::AltModifier);
  d.show();
  QTest::qWait(100);
  QTest::keyPress(&d, Qt::Key_R, Qt::AltModifier);
  d.show();
  QTest::qWait(100);
  QTest::keyPress(&d, Qt::Key_S, Qt::AltModifier);
  d.show();
  QTest::qWait(100);
  QTest::keyPress(&d, Qt::Key_D, Qt::AltModifier);
  d.show();
  QTest::qWait(100);
  QTest::keyPress(&d, Qt::Key_T, Qt::AltModifier);
  d.show();
  QTest::qWait(100);
  QTest::keyPress(&d, Qt::Key_P, Qt::AltModifier);
  d.show();
  QTest::qWait(100);
  QTest::keyPress(&d, Qt::Key_V, Qt::AltModifier);
  d.show();
  QTest::qWait(100);
  //Translate
  QTest::keyPress(&d, Qt::Key_T, Qt::ControlModifier | Qt::ShiftModifier);
  d.show();
  QTest::qWait(100);
}

void ribi::cmap::qtconceptmaprateexamplesdialog_test::key_presses_from_slots()
{
  QtRateExamplesDialog d(ConceptFactory().Get1());
  d.show();
  QTest::qWait(1000);
  d.on_button_prof_clicked();
  d.show();
  QTest::qWait(1000);
  d.on_button_organisations_clicked();
  d.show();
  QTest::qWait(1000);
  d.on_button_social_clicked();
  d.show();
  QTest::qWait(1000);
  d.on_button_target_audience_clicked();
  d.show();
  QTest::qWait(1000);
  d.on_button_prof_development_clicked();
  d.show();
  QTest::qWait(1000);
  d.on_button_misc_clicked();
  d.show();
  QTest::qWait(1000);
  d.on_button_ti_knowledge_clicked();
  d.show();
  QTest::qWait(1000);
  d.on_button_ok_clicked();
  d.show();
  QTest::qWait(1000);
}
