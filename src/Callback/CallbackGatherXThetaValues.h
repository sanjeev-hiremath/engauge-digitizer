#ifndef CALLBACK_GATHER_X_THETA_VALUES_H
#define CALLBACK_GATHER_X_THETA_VALUES_H

#include "CallbackSearchReturn.h"
#include "DocumentModelExport.h"
#include <QHash>
#include <QList>
#include <QMap>
#include "Transformation.h"

class Point;

typedef QList<double> Values;

// Save values into container that preserves order by key (QMap)
typedef QMap<double, bool> ValuesContainer;

typedef QHash<QString, bool> CurveNamesIncluded;

/// Callback for collecting X/Theta independent variables in preparation for exporting.
class CallbackGatherXThetaValues
{
public:
  /// Single constructor.
  CallbackGatherXThetaValues(const DocumentModelExport &modelExport,
                             const QStringList &curvesGraphsNames,
                             const Transformation &transformation);

  /// Callback method.
  CallbackSearchReturn callback (const QString &curveName,
                                 const Point &point);

  /// Resulting values
  Values xThetaValues () const;

private:
  CallbackGatherXThetaValues();

  const DocumentModelExport m_modelExport;
  const Transformation m_transformation;

  CurveNamesIncluded m_curveNamesIncluded;

  ValuesContainer m_values;
};

#endif // CALLBACK_GATHER_X_THETA_VALUES_H