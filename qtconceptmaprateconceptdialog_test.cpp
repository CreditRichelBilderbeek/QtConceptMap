#include "qtconceptmaprateconceptdialog_test.h"

#include "qtconceptmaprateconceptdialog.h"
#include "conceptmapfactory.h"

void ribi::cmap::qtconceptmaprateconceptdialog_test::show_normal_concept_map()
{
  ConceptMap m = ConceptMapFactory().Get2();
  QtRateConceptDialog d(m);
  d.show();
}

void ribi::cmap::qtconceptmaprateconceptdialog_test::show_concept_map_with_only_center_node()
{
  ConceptMap m = ConceptMapFactory().Get1();
  QtRateConceptDialog d(m);
  d.show();

}

void ribi::cmap::qtconceptmaprateconceptdialog_test::show_empty_concept_map()
{
  ConceptMap m = ConceptMapFactory().Get0();
  try
  {
    QtRateConceptDialog d(m);
    d.show();
    QVERIFY(!"Should not get here");
  }
  catch (std::invalid_argument&)
  {
    QVERIFY("OK");
  }
}
