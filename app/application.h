#ifndef APPLICATION_H_
#define APPLICATION_H_

#include <memory>

#include <QList>
#include <QObject>
#include <QThread>

#include "controller.h"
#include "dove_eye/parameters.h"
#include "dove_eye/localization.h"
#include "dove_eye/template_tracker.h"
#include "dove_eye/tracker.h"
#include "dove_eye/types.h"
#include "frameset_converter.h"

/** Holds and manages all necessary object of application
 *
 * @note Thread and QObject handling copied from Clementine.
 */
class Application : public QObject {
  Q_OBJECT
 public:
  Application();

  ~Application() override;

  inline FramesetConverter *converter() {
    return converter_;
  }

  inline dove_eye::Parameters &parameters() {
    return parameters_;
  }

 signals:
  void ChangedArity(const dove_eye::CameraIndex arity);

 private:
  dove_eye::CameraIndex arity_;
  dove_eye::Parameters parameters_;

  Controller *controller_;
  Controller::Aggregator *aggregator_;
  FramesetConverter* converter_;

  std::unique_ptr<dove_eye::Tracker> tracker_;
  std::unique_ptr<dove_eye::Localization> localization_;
  std::unique_ptr<dove_eye::TemplateTracker> inner_tracker_;

  QList<QThread *> threads_;
  QList<QObject *> objects_in_threads_;


  void MoveToNewThread(QObject* object);
  void MoveToThread(QObject* object, QThread* thread);

  void SetArity(const dove_eye::CameraIndex arity);

  void SetupController();
  void SetupConverter();

  void SwapAndDestroy(QObject **object_ptr, QObject *new_object);
};


#endif // APPLICATION_H_