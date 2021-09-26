#include <QPushButton>
#include <QColor>
#include <QColorDialog>

class QColorButton: public QPushButton {
     Q_OBJECT;

public:
     QColorButton(const QColor& c,QWidget* parent=nullptr)
     :QPushButton(parent),_dialog(nullptr),_color(c)
     {
          QObject::connect(this, &QPushButton::clicked, this, &QColorButton::colorPickerOpen);
          QPushButton::setStyleSheet("background-color : " + _color.name() + ';');

     }
     ~QColorButton() = default;

public:
     void setColor(const QColor& newColor) {
          _color = newColor;
          setStyleSheet("background-color : " + _color.name() + ';');
     }
     QColor getColor() {
          return _color;
     }

signals:
     void colorChanged();

public slots:
     void colorPickerOpen() {
     	_dialog = new QColorDialog( _color , nullptr );
     	_dialog->setOption(QColorDialog::DontUseNativeDialog);

     	QObject::connect(
               _dialog, &QColorDialog::colorSelected,
               this, &QColorButton::colorPickerClose
          );
          _dialog->show();
     }
     
     void colorPickerClose(const QColor& newColor) {
          setColor(newColor);
          _dialog->hide();
          emit colorChanged();
     }

private: // Field
     QColorDialog* _dialog;
     QColor _color;
};
